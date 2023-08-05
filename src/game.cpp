#include "ddgm/game.hpp"
#include <iostream>

namespace ddgm {

void itemFind() {
  uint i = generateRandom(1, 100);
  if (isInRange(i, 1, 20)) {
    std::cout << availableHealingItems[0].getName() << "\n";
  } else if (isInRange(i, 21, 32)) {
    std::cout << availableHealingItems[1].getName() << "\n";
  } else if (isInRange(i, 33, 42)) {
    std::cout << availableHealingItems[2].getName() << "\n";
  } else if (isInRange(i, 43, 52)) {
    std::cout << availableHealingItems[3].getName() << "\n";
  } else if (isInRange(i, 53, 59)) {
    std::cout << availableHealingItems[4].getName() << "\n";
  } else if (isInRange(i, 60, 64)) {
    std::cout << availableHealingItems[5].getName() << "\n";
  } else if (isInRange(i, 65, 68)) {
    std::cout << availableHealingItems[6].getName() << "\n";
  } else if (isInRange(i, 69, 71)) {
    std::cout << availableHealingItems[7].getName() << "\n";
  } else if (isInRange(i, 72, 74)) {
    std::cout << availableHealingItems[8].getName() << "\n";
  } else if (i == 75) {
    std::cout << availableHealingItems[9].getName() << "\n";
  } else if (isInRange(i, 76, 77)) {
    std::cout << availableHealingItems[10].getName() << "\n";
  } else if (isInRange(i, 78, 79)) {
    std::cout << availableAttackItems[0].getName() << "\n";
  } else if (isInRange(i, 80, 82)) {
    std::cout << availableAttackItems[1].getName() << "\n";
  } else if (isInRange(i, 83, 86)) {
    std::cout << availableMagicItems[0].getName() << "\n";
  } else if (isInRange(i, 87, 90)) {
    std::cout << availableMagicItems[1].getName() << "\n";
  } else if (isInRange(i, 91, 92)) {
    std::cout << availableMagicItems[2].getName() << "\n";
  } else if (isInRange(i, 93, 94)) {
    std::cout << availableBufferItems[0].getName() << "\n";
  } else if (isInRange(i, 95, 96)) {
    std::cout << availableBufferItems[1].getName() << "\n";
  } else if (isInRange(i, 97, 98)) {
    std::cout << availableBufferItems[2].getName() << "\n";
  } else {
    std::cout << availableBufferItems[3].getName() << "\n";
  }
}
} // namespace ddgm