#include "ddgm/utilities.hpp"
#include "ddgm/skills.hpp"
#include <chrono>
#include <cmath>
#include <iostream>
#include <random>
#include <unistd.h>

namespace ddgm {
// Defining the function to calculate the percentage of a number
uint percu(uint n, uint perc) { return n * perc / 100; }

// Defining a function to create a random number between a given range
uint generateRandom(uint start, uint end) {
  uint seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 gnr(seed);
  std::uniform_int_distribution<int> range(start, end);
  return range(gnr);
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

uint totalDmg(uint dmg, float multiplier) {
  dmg *= multiplier;
  return std::ceil(dmg);
}

uint check_skill(uint start, uint end) {
  uint k = 0;
  std::cin >> k;
  if (k == 0)
    return k;
  while (k < start || k > end) {
    std::cout << "Choose a skill between the ones listed.\n>> ";
    std::cin >> k;
  }
  return k;
}

} // namespace ddgm