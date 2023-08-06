#include "ddgm/game.hpp"
#include <iostream>
#include <unistd.h>

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

// Credits of the game
void game_credits() {
  std::cout << "- DOGMA'S DRAGONS -\n";
  std::cout << "Game made by Kenkai and Ventus\n";
  std::cout << "Additional help by Salhell\n";
  std::cout << "Based on CAPCOM's already existing game \"Dragon's Dogma.\"\n";
}

// Basic start menu of the game
int start_menu() {
  uint r;
  std::cout << "-------------------\n";
  std::cout << "1. New Game\n";
  std::cout << "2. Continue\n";
  std::cout << "3. Credits\n";
  std::cout << "0. Exit\n";
  std::cout << "-------------------\n";
  std::cout << ">> ";
  std::cin >> r;
  return r;
}

// to continue
void game_introduction() {
  std::cout << "Legends tell that a Dragon has populated these lands since "
               "time immemorial. Whether it was the same creature over the "
               "centuries, no one can tell, for no one has ever lived "
               "enough to witness...or did someone?\n";
  sleep(1);
  std::cout << "The people hasn't seen the Dragon's shadow for over fifty "
               "years now, and peace seems to reign sovereign in people's "
               "hearts once more.\n";
}

void battle() {}

// Those functions show the entirety of the vocations' skills
void fighter_skills() {
  for (int i = 0; i < 6; i++) {
    std::cout << "\nName: " << skills[i].getName() << "\n";
    std::cout << "Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "Cooldown: " << skills[i].getCooldown() << "\n";
  }
}

void warrior_skills() {
  for (int i = 6; i < 12; i++) {
    std::cout << "\nName: " << skills[i].getName() << "\n";
    std::cout << "Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "Cooldown: " << skills[i].getCooldown() << "\n";
  }
}

void magicknight_skills() {
  for (int i = 12; i < 18; i++) {
    std::cout << "\nName: " << skills[i].getName() << "\n";
    std::cout << "Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "Cooldown: " << skills[i].getCooldown() << "\n";
  }
}

void strider_skills() {
  for (int i = 18; i < 24; i++) {
    std::cout << "\nName: " << skills[i].getName() << "\n";
    std::cout << "Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "Cooldown: " << skills[i].getCooldown() << "\n";
  }
}

void ranger_skills() {
  for (int i = 24; i < 30; i++) {
    std::cout << "\nName: " << skills[i].getName() << "\n";
    std::cout << "Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "Cooldown: " << skills[i].getCooldown() << "\n";
  }
}

void assassin_skills() {
  for (int i = 30; i < 36; i++) {
    std::cout << "\nName: " << skills[i].getName() << "\n";
    std::cout << "Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "Cooldown: " << skills[i].getCooldown() << "\n";
  }
}

void mage_skills() {
  for (int i = 36; i < 45; i++) {
    std::cout << "\nName: " << skills[i].getName() << "\n";
    std::cout << "Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "Cooldown: " << skills[i].getCooldown() << "\n";
  }
}

void sorcerer_skills() {
  for (int i = 45; i < 55; i++) {
    std::cout << "\nName: " << skills[i].getName() << "\n";
    std::cout << "Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "Cooldown: " << skills[i].getCooldown() << "\n";
  }
}

void magickarcher_skills() {
  for (int i = 55; i < 61; i++) {
    std::cout << "\nName: " << skills[i].getName() << "\n";
    std::cout << "Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "Cooldown: " << skills[i].getCooldown() << "\n";
  }
}

} // namespace ddgm