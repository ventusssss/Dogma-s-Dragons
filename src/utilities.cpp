#include "ddgm/utilities.hpp"
#include <chrono>
#include <iostream>
#include <random>

namespace ddgm {
uint percu(uint n, uint perc) { return n * perc / 100; }
void casuality(uint perc) {
  // generates the seed for the randomization, taking the current time in
  // seconds
  uint seed = std::chrono::system_clock::now().time_since_epoch().count();
  // initializes the generator (gnr)
  std::mt19937 gnr(seed);
  std::uniform_int_distribution<int> range(1, 100);

  // creating the actual casual number
  (range(gnr) > perc ? std::cout << "Missed\n" : std::cout << "Hit!\n");
}
} // namespace ddgm