#include "ddgm/utilities.hpp"
#include "ddgm/enemies.hpp"
#include "ddgm/items.hpp"
#include "ddgm/pawn.hpp"
#include "ddgm/player.hpp"
#include "ddgm/skills.hpp"
// #include <chrono>
// #include <cmath>
#include <fstream>
#include <iostream>
#include <map>
// #include <random>
#include <stdexcept>
#include <unistd.h>
#include <vector>

namespace ddgm {

nlohmann::json load() {
  std::ifstream stream("save.json");
  nlohmann::json data;
  data = nlohmann::json::parse(stream);
  stream.close();
  return data;
}

void save(Player player, Pawn pawn) {
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

std::map<std::string, std::pair<uint, uint>>
normalize_inventory(std::vector<Item> inventory) {
  std::map<std::string, std::pair<uint, uint>> printable_inventory;
  for (uint i = 0; i < inventory.size(); i++) {
    if (isIn(inventory[i].getName(), printable_inventory)) {
      printable_inventory[inventory[i].getName()].first++;
    } else {
      printable_inventory[inventory[i].getName()].first = 1;
      if (i == 0)
        printable_inventory[inventory[i].getName()].second = i;
      else if (inventory[i - 1].getName() != inventory[i].getName())
        printable_inventory[inventory[i].getName()].second =
            printable_inventory[inventory[i - 1].getName()].second + 1;
    }
  }
  return printable_inventory;
}

/*
void choose_item(Player &player) {
  std::map<std::string, std::pair<uint, uint>> normalized_inventory =
      normalize_inventory(player.getInventory());
  uint item_to_use = 0;
  std::map<std::string, std::pair<uint, uint>>::iterator it =
      normalized_inventory.begin();
  for (uint i = 0; it != normalized_inventory.end();) {
    std::cout << it->second.second << ". Name: " << it->first
              << ", Quantity: " << it->second.first << "\n";
    ++it, ++i;
  }
  std::cout << "Choose the item to use\n>> ";
  std::cin >> item_to_use;
  while ((std::cin.fail()) ||
         (item_to_use < 1 || item_to_use > normalized_inventory.size())) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Choose a valid item: ";
    std::cin >> item_to_use;
  }
  //--item_to_use;
  std::cout << "item to use: " << item_to_use << "\n";
  std::string item_name = "";
  for (auto item : normalized_inventory) {
    std::cout << "it index" << item.second.second << "\n";
    if (item.second.second == item_to_use) {
      std::cout << "entering\n";
      item_name = item.first;
      break;
    }
  }
  std::cout << "item name before use: " << item_name << "\n";
  player.useItem(item_name);
  std::cout << "used";
}*/

void choose_item_(Player &player) {
  std::map<std::string, std::pair<uint, uint>> inventory =
      normalize_inventory(player.getInventory());
  
  for (auto x: inventory) {
    std::cout << x.first << "\n";
  }
}

int get_item_index(std::string item_name, std::vector<Item> inventory) {
  for (int i = 0; i < inventory.size(); i++) {
    // std::cout << "item name: " << item_name << "\n";
    std::cout << "inventory[i] name: " << inventory[i].getName() << "\n";
    if (item_name == inventory[i].getName())
      return i;
  }
  return -1;
}

bool search_enemy(std::vector<Enemy> enemies, Enemy enemy) {
  for (uint i = 0; i < enemies.size(); i++) {
    if (enemy.getName() == enemies[i].getName())
      return true;
  }
  return false;
}

} // namespace ddgm