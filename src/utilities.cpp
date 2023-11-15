#include "ddgm/utilities.hpp"
#include "ddgm/enemies.hpp"
#include "ddgm/pawn.hpp"
#include "ddgm/player.hpp"
#include "ddgm/skills.hpp"
#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <random>
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

bool search_enemy(std::vector<Enemy> enemies, Enemy enemy) {
  for (uint i = 0; i < enemies.size(); i++) {
    if (enemy.getName() == enemies[i].getName())
      return true;
  }
  return false;
}

} // namespace ddgm