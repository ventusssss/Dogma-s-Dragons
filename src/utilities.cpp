#include "ddgm/utilities.hpp"
#include "ddgm/enemies.hpp"
#include "ddgm/game.hpp"
#include "ddgm/items.hpp"
#include "ddgm/pawn.hpp"
#include "ddgm/player.hpp"
#include "ddgm/skills.hpp"
// #include <chrono>
// #include <cmath>
#include <fstream>
#include <iostream>
// #include <random>
#include <stdexcept>
#include <unistd.h>
#include <utility>
#include <vector>

namespace ddgm {

nlohmann::json load() {
  std::ifstream stream("save.json");
  nlohmann::json data;
  data = nlohmann::json::parse(stream);
  stream.close();
  return data;
}

void save(Player &player, Pawn &pawn) {
  std::ofstream stream("save.json");
  nlohmann::json data = {{"player", player.getJson()},
                         {"pawn", pawn.getJson()}};
  stream << std::setw(4) << data;
  stream.close();
}

// Defining the function to calculate the percentage of a number
uint percu(uint n, uint perc) { return n * perc / 100; }

// Defining a function to create a random number between a given range
uint generateRandom(uint start, uint end) {
  return rand() % (end - start + 1) + start;
}

// Defining a function to check IF a number is contained in a range
bool isInRange(uint n, uint start, uint end) {
  if (n >= start && n <= end)
    return true;
  return false;
}

bool is_enemy_in_list(std::vector<std::string> enemies_names,
                      std::vector<Enemy> enemies) {
  for (Enemy enemy : enemies) {
    for (std::string name : enemies_names) {
      if (name == enemy.getName())
        return true;
    }
  }
  return false;
}

// defining a function to calculate (randomically) the chance
// of an event to verify
bool casuality(uint perc) {
  // creating the actual casual number
  if (generateRandom(1, 100) <= perc)
    return true;
  else
    return false;
}

/*uint totalDmg(uint dmg, float multiplier) {
  dmg *= multiplier;
  return std::ceil(dmg);
}*/

uint check_skill(uint end) {
  uint num = 0;
  std::string k = "";
  do {
    std::cin >> k;
    try {
      num = std::stoi(k);
      if (num > end || num < 0) {
        throw std::invalid_argument(std::string(""));
      }
      break;
    } catch (std::invalid_argument) {
      std::cout << "Choose a skill among the ones listed: ";
    }
  } while (true);
  return num;
}

bool search_skill(std::vector<Skill::SkillType> skill_typesVector,
                  Skill::SkillType skill_type) {
  for (uint i = 0; i < skill_typesVector.size(); i++) {
    if (skill_type == skill_typesVector[i]) {
      return true;
    }
  }
  return false;
}

bool find_skill(std::vector<Skill> skillsVector, Skill skillToFind) {
  for (uint i = 0; i < skillsVector.size(); i++) {
    if (skillToFind.getName() == skillsVector[i].getName()) {
      return true;
    }
  }
  return false;
}

void show_skills(std::vector<Skill> skills) {
  std::cout << "[ ";
  for (uint i = 0; i < skills.size(); i++) {
    if (i == skills.size() - 1) {
      std::cout << i + 1 << ". " << skills[i].getName() << ": "
                << skills[i].getSkillType();
    } else {
      std::cout << i + 1 << ". " << skills[i].getName() << ": "
                << skills[i].getSkillType() << ", ";
    }
  }
  std::cout << " ]\n";
}

std::vector<std::pair<std::string, uint>>
normalize_inventory(const std::vector<Item> &player_inventory) {
  std::vector<std::pair<std::string, uint>> inventory;

  for (const auto &player_item : player_inventory) {
    auto it = std::find_if(
        inventory.begin(), inventory.end(), [&](const auto &inventory_item) {
          return player_item.getName() == inventory_item.first;
        });
    if (it != inventory.end()) {
      it->second++;
    } else {
      inventory.emplace_back(player_item.getName(), 1);
    }
  }

  return inventory;
}

void choose_item(Player &player, Pawn &pawn, std::vector<Enemy> enemies) {
  auto inventory = normalize_inventory(player.getInventory());
  int item_to_use = -1;
  bool is_item_valid = true;

  do {
    for (uint i = 0; i < inventory.size(); i++) {
      std::cout << i + 1 << ". Name: " << inventory[i].first
                << ", Quantity: " << inventory[i].second << "\n";
    }
    std::cout << "0. Battle Choice\n";

    std::cout << "Choose the item to use\n>> ";
    std::cin >> item_to_use;

    while ((std::cin.fail()) ||
           (item_to_use < 0 || item_to_use > inventory.size())) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Choose a valid item: ";
      std::cin >> item_to_use;
    }

    if (!item_to_use)
      return;

    --item_to_use;

    for (uint index = 0; index < inventory.size(); index++) {
      if (inventory[item_to_use].first ==
          player.getInventory()[index].getName()) {
        item_to_use = index;
        break;
      }
    }

    if (player.getInventory()[item_to_use].getName() == "Griffin Dawn") {
      if (!pawn.getHp()) {
        std::cout << "Your pawn was brought back to life by this magic item!\n";
        pawn.healEntity(percu(pawn.getMaxHp(), 50));
        player.useItem(item_to_use);
        return;
      } else {
        std::cout << "You can only use this item on a dead pawn.\n";
        is_item_valid = false;
      }
    }
  } while (!is_item_valid);

  std::vector<Entity> entities = display_entities(player, pawn, enemies);
  uint entity_target = entity_choice(entities);
  Entity &entity = entities[entity_target];
  player.useItem(item_to_use, &entity);
}

void choose_item(Player &player, Pawn &pawn, Enemy &enemy) {
  auto inventory = normalize_inventory(player.getInventory());
  int item_to_use = -1;
  bool is_item_valid = true;

  do {
    for (uint i = 0; i < inventory.size(); i++) {
      std::cout << i + 1 << ". Name: " << inventory[i].first
                << ", Quantity: " << inventory[i].second << "\n";
    }
    std::cout << "0. Battle Choice\n";

    std::cout << "Choose the item to use\n>> ";
    std::cin >> item_to_use;

    while ((std::cin.fail()) ||
           (item_to_use < 0 || item_to_use > inventory.size())) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Choose a valid item: ";
      std::cin >> item_to_use;
    }

    if (!item_to_use)
      return;

    --item_to_use;

    for (uint index = 0; index < inventory.size(); index++) {
      if (inventory[item_to_use].first ==
          player.getInventory()[index].getName()) {
        item_to_use = index;
        break;
      }
    }

    if (player.getInventory()[item_to_use].getName() == "Griffin Dawn") {
      if (!pawn.getHp()) {
        std::cout << "Your pawn was brought back to life by this magic item!\n";
        pawn.healEntity(percu(pawn.getMaxHp(), 50));
        player.useItem(item_to_use);
        return;
      } else {
        std::cout << "You can only use this item on a dead pawn.\n";
        is_item_valid = false;
      }
    }
  } while (!is_item_valid);

  std::vector<Entity> entities = display_entities(player, pawn, enemy);
  uint entity_target = entity_choice(entities);
  Entity &entity = entities[entity_target];
  player.useItem(item_to_use, &entity);
}

bool search_enemy(std::vector<Enemy> enemies, Enemy enemy) {
  for (uint i = 0; i < enemies.size(); i++) {
    if (enemy.getName() == enemies[i].getName())
      return true;
  }
  return false;
}

} // namespace ddgm