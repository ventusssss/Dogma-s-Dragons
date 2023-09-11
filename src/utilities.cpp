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
  if (generateRandom(0, 100) < perc)
    return true;
  else
    return false;
}

/*uint totalDmg(uint dmg, float multiplier) {
  dmg *= multiplier;
  return std::ceil(dmg);
}*/

uint check_skill(uint start, uint end) {
  uint k = 0;
  std::cin >> k;
  while (std::cin.fail() || (k < start || k > end)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Choose a skill between the ones listed.\n>> ";
    std::cin >> k;
  }
  return k;
}

bool search_skill(std::vector<Skill::SkillType> vector,
                  Skill::SkillType skill) {
  for (uint i = 0; i < vector.size(); i++) {
    if (skill == vector[i]) {
      return true;
    }
  }
  return false;
}

bool search_enemy(std::vector<Enemy> enemies, Enemy enemy) {
  for (uint i = 0; i < enemies.size(); i++) {
    if (enemy.getName() == enemies[i].getName())
      return true;
  }
  return false;
}

} // namespace ddgm