#include "ddgm/utilities.hpp"
#include "ddgm/skills.hpp"
#include <chrono>
#include <iostream>
#include <random>
#include <unistd.h>

namespace ddgm {
// Defining the function to calculate the percentage of a number
uint percu(uint n, uint perc) { return n * perc / 100; }

// defining a function to calculate (randomically) the chance
// of an event to verify
void casuality(uint perc) {
  // generates the seed for the randomization, taking the current time in
  // seconds
  uint seed = std::chrono::system_clock::now().time_since_epoch().count();
  // initializes the generator (gnr)
  std::mt19937 gnr(seed);
  std::uniform_int_distribution<int> range(1, 100);

  // creating the actual casual number
  range(gnr) > perc ? std::cout << "Missed\n" : std::cout << "Hit!\n";
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

// Credits of the game
void game_credits() {
  std::cout << "- DOGMA'S DRAGONS -\n";
  std::cout << "Game made by Kenkai and Ventus\n";
  std::cout << "Additional help by Salhell\n";
  std::cout << "Based on CAPCOM's already existing game \"Dragon's Dogma.\"\n";
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