#include "ddgm/game.hpp"
#include "ddgm/player.hpp"
#include "ddgm/utilities.hpp"
#include <array>
#include <cctype>
#include <iostream>
#include <unistd.h>
#include <vector>

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
  uint c;
  std::cout << "-------------------\n";
  std::cout << "1. New Game\n";
  std::cout << "2. Continue\n";
  std::cout << "3. Credits\n";
  std::cout << "0. Exit\n";
  std::cout << "-------------------\n";
  std::cout << ">> ";
  std::cin >> c;
  return c;
}

int game_menu() {
  uint c;
  std::cout << "1. Travel\n";
  std::cout << "2. Change Abilities/Vocation\n";
  std::cout << "3. Check Stats\n";
  std::cout << "0. Main Menu\n";
  std::cout << ">> ";
  std::cin >> c;
  return c;
}

// to continue
void game_introduction() {
  system("clear");
  std::cout << "Legends tell that a Dragon has populated these lands since "
               "time immemorial.\nWhether it was the same creature over the "
               "centuries, no one can tell,\nfor no one has ever lived "
               "enough to witness...or did someone?\n";
  // std::cout << ">> Press any KEY to continue.";
  std::cin.get();
  std::cout << "The people haven't seen the Dragon for over fifty "
               "years now, and peace seems to reign sovereign in people's "
               "hearts once more.\n";
  // std::cout << "Press any KEY to continue.";
  std::cin.get();
  std::cout
      << "But one day is enough to turn the people's hope into pure fear.\n";
  // std::cout << "Press any KEY to continue.";
  std::cin.get();
  std::cout << "That day, the Dragon landed on the sea village of "
               "Cassardis.\nThe Royal Guards were in a mix of disbelief and "
               "terror at its appearance.\nEveryone tried to flee, but many "
               "were struck by The Dragon's infernal flames.\nAmongst all "
               "those terrified people, one person stepped forward, determined "
               "to fight The Dragon.\n";
  // std::cout << "Press any KEY to continue.";
  std::cin.get();
  std::cout
      << "The brave one was just a fisherman, but he wielded a rusted "
         "sword and challenged the Dragon.\nHe stood no choice. The "
         "Dragon struck him with his paw,\nbut in that moment, the "
         "fisherman also managed to thrust the sword into the Dragon's hand.\n";
  // std::cout << "Press any KEY to continue.";
  std::cin.get();
  std::cout << "Something awakened in the Dragon. Its eyes turned red as fire, "
               "and it seemed to realize what was happening.\nThe Beast then "
               "raised his paw, and with a single touch, he ripped the heart "
               "of the fisherman.\n";
  // std::cout << "Press any KEY to continue.";
  std::cin.get();
  std::cout
      << "It then flee away, speaking in an ancient language only the "
         "fisherman could apparently understand.\nIt said \"Come and get me, "
         "slay me. You'll find me on the tallest peak of the kingdom\".\n";
  // std::cout << "Press any KEY to continue.";
  std::cin.get();
  std::cout << "The fisherman woke up in a house, with a scar on his chest, "
               "in disbelief that he survived.\nSuddently, the scar "
               "enlightened,\nand the man heard the phrase that the Dragon "
               "told him before.\n";
  // std::cout << "Press any KEY to continue.";
  std::cin.get();
  std::cout << "Then, his beloved entered the room. To check if he was well, "
               "she asked a few questions,\nbeginning with simply asking him "
               "his name.\n";
}

std::string playerChooseName() {
  std::string name;
  char ans = ' ';
  do {
    name = "";
    std::cout << "What is your name?\n>> ";
    std::getline(std::cin, name);
    std::cout << "Is this really your name? Y/N\n>> ";
    std::cin >> ans;
    while (tolower(ans) != 'y' && tolower(ans) != 'n') {
      std::cout << "Select Y or N: ";
      std::cin >> ans;
    }
    std::cin.ignore();
  } while (ans != 'y');
  return name;
}

std::string pawnChooseName() {
  std::string name;
  char ans = ' ';
  do {
    name = "";
    std::cout << "Choose a name for your Pawn: ";
    std::getline(std::cin, name);
    std::cout << "Is this the name for your partner? Y/N\n>> ";
    std::cin >> ans;
    while (tolower(ans) != 'y' && tolower(ans) != 'n') {
      std::cout << "Select Y or N: ";
      std::cin >> ans;
    }
    std::cin.ignore();
  } while (ans != 'y');
  return name;
}

uint chooseStartingVocation() {
  system("clear");
  uint vocation = 0;
  std::cout << "Choose the starting vocation: \n";
  std::cout << "1. Fighter, grants a high bonus to DEF when levelling up. "
               "\n   Small increase of life too.\n";
  std::cout << "2. Strider, grants a small increase to ATK and DEF when "
               "levelling up.\n";
  std::cout << "3. Mage, grants a huge boost to MDEF when levelling up.\n";
  std::cout
      << "(Other stats will also increase, but in a less significant way)\n";
  std::cout << ">> ";
  std::cin >> vocation;
  while (std::cin.fail() || (vocation < 1 || vocation > 3)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Choose a valid vocation: ";
    std::cin >> vocation;
  }
  std::cin.ignore();
  return vocation;
}

void characterCreation(Player *player) {
  std::string name = "";
  uint vocation = 0;
  system("clear");
  if (dynamic_cast<Pawn *>(player)) {
    name = pawnChooseName();
    vocation = chooseStartingVocation();
    player->setName(name);
    player->setStartingVocation(vocation);
  } else {
    name = playerChooseName();
    vocation = chooseStartingVocation();
    player->setName(name);
    player->setStartingVocation(vocation);
  }
}

void battle() {}

// Those functions show the entirety of the vocations' skills
void fighter_skills() {
  for (int i = 0; i < 6; i++) {
    std::cout << "\n" << i + 1 << ") Name: " << skills[i].getName() << "\n";
    std::cout << "   Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "   Cooldown: " << skills[i].getCd() << "\n";
  }
}

void warrior_skills() {
  for (int i = 6; i < 12; i++) {
    std::cout << "\n" << i + 1 << ") Name: " << skills[i].getName() << "\n";
    std::cout << "   Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "   Cooldown: " << skills[i].getCd() << "\n";
  }
}

void paladin_skills() {
  for (int i = 12; i < 18; i++) {
    std::cout << "\n" << i + 1 << ") Name: " << skills[i].getName() << "\n";
    std::cout << "   Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "   Cooldown: " << skills[i].getCd() << "\n";
  }
}

void strider_skills() {
  for (int i = 18; i < 24; i++) {
    std::cout << "\n" << i + 1 << ") Name: " << skills[i].getName() << "\n";
    std::cout << "   Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "   Cooldown: " << skills[i].getCd() << "\n";
  }
}

void ranger_skills() {
  for (int i = 24; i < 30; i++) {
    std::cout << "\n" << i + 1 << ") Name: " << skills[i].getName() << "\n";
    std::cout << "   Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "   Cooldown: " << skills[i].getCd() << "\n";
  }
}

void assassin_skills() {
  for (int i = 30; i < 36; i++) {
    std::cout << "\n" << i + 1 << ") Name: " << skills[i].getName() << "\n";
    std::cout << "   Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "   Cooldown: " << skills[i].getCd() << "\n";
  }
}

void mage_skills() {
  for (int i = 36; i < 45; i++) {
    std::cout << "\n" << i + 1 << ") Name: " << skills[i].getName() << "\n";
    std::cout << "   Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "   Cooldown: " << skills[i].getCd() << "\n";
  }
}

void sorcerer_skills() {
  for (int i = 45; i < 55; i++) {
    std::cout << "\n" << i + 1 << ") Name: " << skills[i].getName() << "\n";
    std::cout << "   Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "   Cooldown: " << skills[i].getCd() << "\n";
  }
}

void magickarcher_skills() {
  for (int i = 55; i < 61; i++) {
    std::cout << "\n" << i + 1 << ") Name: " << skills[i].getName() << "\n";
    std::cout << "   Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "   Cooldown: " << skills[i].getCd() << "\n";
  }
}

// NEED TO ADD LIMITATIONS TO THE CHOOSING SKILLS
// BY CHECKING THE CURRENT VOCATION LEVELS

void skill_choosing(Player *player) {
  uint skill = 0;
  std::vector<Skill> player_abilities;
  switch (player->getVocation()) {
  case Vocations::Fighter:
    do {
      system("clear");
      fighter_skills();
      std::cout << "0) None\n\n";
      std::cout << "[ ";
      for (uint i = 0; i < player_abilities.size(); i++) {
        if (i != player_abilities.size() - 1)
          std::cout << player_abilities[i].getName() << ", ";
        else
          std::cout << player_abilities[i].getName();
      }
      std::cout << " ]\n";
      std::cout << "\nChoose which skill you want to add to your roaster\n>> ";
      skill = check_skill(0, 6);
      std::cin.ignore();
      if (!skill)
        break;
      if (skill - 1 == 4 && player->getFighterLvls() < 2) {
        std::cout
            << "\nYou cannot set this skill yet.\nYou have to do at least 2 "
               "levels as a Fighter.\nNow you currently have "
            << player->getFighterLvls() << " levels as a Fighter.\n";
        std::cin.get();
      } else if (skill - 1 == 5 && player->getFighterLvls() < 3) {
        std::cout
            << "\nYou cannot set this skill yet.\nYou have to do at least 3 "
               "levels as a Fighter.\nNow you currently have "
            << player->getFighterLvls() << " levels as a Fighter.\n";
        std::cin.get();
      } else {
        player_abilities.push_back(skills[skill - 1]);
      }
    } while (skill != 0 && player_abilities.size() < 6);
    break;
  case Vocations::Strider:
    do {
      strider_skills();
      std::cout << "0) None\n\n";
      std::cout << "[ ";
      for (uint i = 0; i < player_abilities.size(); i++) {
        if (i != player_abilities.size() - 1)
          std::cout << player_abilities[i].getName() << ", ";
        else
          std::cout << player_abilities[i].getName();
      }
      std::cout << " ]\n";
      std::cout << "\nChoose which skill you want to add to your roaster\n>> ";
      skill = check_skill(19, 24);
      std::cin.ignore();
      if (!skill)
        break;
      if (skill - 1 == 20 && player->getStriderLvls() < 2) {
        std::cout
            << "\nYou cannot set this skill yet.\nYou have to do at least 2 "
               "levels as a Strider.\nNow you currently have "
            << player->getStriderLvls() << " levels as a Strider.\n";
        std::cin.get();
      } else if (skill - 1 == 22 && player->getStriderLvls() < 2) {
        std::cout
            << "\nYou cannot set this skill yet.\nYou have to do at least 2 "
               "levels as a Strider.\nNow you currently have "
            << player->getStriderLvls() << " levels as a Strider.\n";
        std::cin.get();
      } else if (skill - 1 == 21 && player->getStriderLvls() < 3) {
        std::cout
            << "\nYou cannot set this skill yet.\nYou have to do at least 3 "
               "levels as a Strider.\nNow you currently have "
            << player->getStriderLvls() << " levels as a Strider.\n";
        std::cin.get();
      } else {
        player_abilities.push_back(skills[skill - 1]);
      }
    } while (skill != 0 && player_abilities.size() < 6);
    break;
  case Vocations::Mage:
    do {
      mage_skills();
      std::cout << "0) None\n\n";
      std::cout << "[ ";
      for (uint i = 0; i < player_abilities.size(); i++) {
        if (i != player_abilities.size() - 1)
          std::cout << player_abilities[i].getName() << ", ";
        else
          std::cout << player_abilities[i].getName();
      }
      std::cout << " ]\n";
      std::cout << "\nChoose which skill you want to add to your roaster\n>> ";
      skill = check_skill(37, 45);
      std::cin.ignore();
      if (!skill)
        break;
      if (skill - 1 == 44 && player->getMageLvls() < 3) {
        std::cout
            << "\nYou cannot set this skill yet.\nYou have to do at least 3 "
               "levels as a Mage.\nNow you currently have "
            << player->getMageLvls() << " levels as a Mage.\n";
        std::cin.get();
      } else {
        player_abilities.push_back(skills[skill - 1]);
      }
    } while (skill != 0 && player_abilities.size() < 6);
    break;
  case Vocations::Warrior:
    do {
      system("clear");
      warrior_skills();
      std::cout << "0) None\n\n";
      std::cout << "[ ";
      for (uint i = 0; i < player_abilities.size(); i++) {
        if (i != player_abilities.size() - 1)
          std::cout << player_abilities[i].getName() << ", ";
        else
          std::cout << player_abilities[i].getName();
      }
      std::cout << " ]\n";
      std::cout << "\nChoose which skill you want to add to your roaster\n>> ";
      skill = check_skill(7, 12);
      std::cin.ignore();
      if (!skill)
        break;
      if (skill - 1 == 10 && player->getWarriorLvls() < 2) {
        std::cout
            << "\nYou cannot set this skill yet.\nYou have to do at least 2 "
               "levels as a Warrior.\nNow you currently have "
            << player->getWarriorLvls() << " levels as a Warrior.\n";
        std::cin.get();
      } else if (skill - 1 == 11 && player->getWarriorLvls() < 5) {
        std::cout
            << "\nYou cannot set this skill yet.\nYou have to do at least 5 "
               "levels as a Warrior.\nNow you currently have "
            << player->getWarriorLvls() << " levels as a Warrior.\n";
        std::cin.get();
      } else {
        player_abilities.push_back(skills[skill - 1]);
      }
    } while (skill != 0 && player_abilities.size() < 6);
    break;
  case Vocations::Ranger:
    do {
      ranger_skills();
      std::cout << "0) None\n\n";
      std::cout << "[ ";
      for (uint i = 0; i < player_abilities.size(); i++) {
        if (i != player_abilities.size() - 1)
          std::cout << player_abilities[i].getName() << ", ";
        else
          std::cout << player_abilities[i].getName();
      }
      std::cout << " ]\n";
      std::cout << "\nChoose which skill you want to add to your roaster\n>> ";
      skill = check_skill(25, 30);
      std::cin.ignore();
      if (!skill)
        break;
      if (skill - 1 == 27 && player->getRangerLvls() < 3) {
        std::cout
            << "\nYou cannot set this skill yet.\nYou have to do at least 3 "
               "levels as a Ranger.\nNow you currently have "
            << player->getRangerLvls() << " levels as a Ranger.\n";
        std::cin.get();
      } else if (skill - 1 == 29 && player->getRangerLvls() < 4) {
        std::cout
            << "\nYou cannot set this skill yet.\nYou have to do at least 4 "
               "levels as a Ranger.\nNow you currently have "
            << player->getRangerLvls() << " levels as a Ranger.\n";
        std::cin.get();
      } else {
        player_abilities.push_back(skills[skill - 1]);
      }
    } while (skill != 0 && player_abilities.size() < 6);
    break;
  case Vocations::Sorcerer:
    do {
      sorcerer_skills();
      std::cout << "0) None\n\n";
      std::cout << "[ ";
      for (uint i = 0; i < player_abilities.size(); i++) {
        if (i != player_abilities.size() - 1)
          std::cout << player_abilities[i].getName() << ", ";
        else
          std::cout << player_abilities[i].getName();
      }
      std::cout << " ]\n";

      std::cout << "\nChoose which skill you want to add to your roaster\n>> ";
      skill = check_skill(46, 55);
      std::cin.ignore();
      if (!skill)
        break;
      if (((skill - 1 == 45) || (skill - 1 == 46) || (skill - 1 == 47) ||
           (skill - 1 == 48)) &&
          player->getSorcererLvls() < 5) {
        std::cout
            << "\nYou cannot set this skill yet.\nYou have to do at least 5 "
               "levels as a Sorcerer.\nNow you currently have "
            << player->getSorcererLvls() << " levels as a Sorcerer.\n";
        std::cin.get();
      } else {
        player_abilities.push_back(skills[skill - 1]);
        std::cout << player_abilities.size() << "L\n";
        std::cin.get();
      }
    } while (skill != 0 && player_abilities.size() < 6);
    break;
  case Vocations::Assassin:
    do {
      assassin_skills();
      std::cout << "0) None\n\n";
      std::cout << "[ ";
      for (uint i = 0; i < player_abilities.size(); i++) {
        if (i != player_abilities.size() - 1)
          std::cout << player_abilities[i].getName() << ", ";
        else
          std::cout << player_abilities[i].getName();
      }
      std::cout << " ]\n";
      std::cout << "\nChoose which skill you want to add to your roaster\n>> ";
      skill = check_skill(31, 36);
      std::cin.ignore();
      if (!skill)
        break;
      if (((skill - 1 == 35) || (skill - 1 == 31)) &&
          player->getAssassinLvls() < 2) {
        std::cout
            << "\nYou cannot set this skill yet.\nYou have to do at least 2 "
               "levels as a Assassin.\nNow you currently have "
            << player->getAssassinLvls() << " levels as a Assassin.\n";
        std::cin.get();
      } else if (skill - 1 == 33 && player->getAssassinLvls() < 4) {
        std::cout
            << "\nYou cannot set this skill yet.\nYou have to do at least 4 "
               "levels as an Assassin.\nNow you currently have "
            << player->getAssassinLvls() << " levels as an Assassin.\n";
        std::cin.get();
      } else {
        player_abilities.push_back(skills[skill - 1]);
      }
    } while (skill != 0 && player_abilities.size() < 6);
    break;
  case Vocations::MagickArcher:
    do {
      magickarcher_skills();
      std::cout << "0) None\n\n";
      std::cout << "[ ";
      for (uint i = 0; i < player_abilities.size(); i++) {
        if (i != player_abilities.size() - 1)
          std::cout << player_abilities[i].getName() << ", ";
        else
          std::cout << player_abilities[i].getName();
      }
      std::cout << " ]\n";
      std::cout << "\nChoose which skill you want to add to your roaster\n>> ";
      skill = check_skill(56, 61);
      std::cin.ignore();
      if (!skill)
        break;
      if ((skill - 1 == 57) ||
          (skill - 1 == 58) && player->getMagickArcherLvls() < 3) {
        std::cout
            << "\nYou cannot set this skill yet.\nYou have to do at least 3 "
               "levels as a Magick-Archer.\nNow you currently have "
            << player->getMagickArcherLvls() << " levels as a Magick-Archer.\n";
        std::cin.get();
      } else if (skill - 1 == 61 && player->getMagickArcherLvls() < 5) {
        std::cout
            << "\nYou cannot set this skill yet.\nYou have to do at least 5 "
               "levels as a Magick-Archer.\nNow you currently have "
            << player->getMagickArcherLvls() << " levels as a Magick-Archer.\n";
        std::cin.get();
      } else {
        player_abilities.push_back(skills[skill - 1]);
      }
    } while (skill != 0 && player_abilities.size() < 6);
    break;
  case Vocations::Paladin:
    do {
      paladin_skills();
      std::cout << "0) None\n\n";
      std::cout << "[ ";
      for (uint i = 0; i < player_abilities.size(); i++) {
        if (i != player_abilities.size() - 1)
          std::cout << player_abilities[i].getName() << ", ";
        else
          std::cout << player_abilities[i].getName();
      }
      std::cout << " ]\n";
      std::cout << "\nChoose which skill you want to add to your roaster\n>> ";
      skill = check_skill(13, 18);
      std::cin.ignore();
      if (!skill)
        break;
      if (skill - 1 == 14 && player->getPaladinLvls() < 4) {
        std::cout
            << "\nYou cannot set this skill yet.\nYou have to do at least 4 "
               "levels as a Paladin.\nNow you currently have "
            << player->getPaladinLvls() << " levels as a Paladin.\n";
        std::cin.get();
      }
      player_abilities.push_back(skills[skill - 1]);
    } while (skill != 0 && player_abilities.size() < 6);
    break;
  }

  if (player_abilities.size() == 6)
    std::cout
        << "\nYou have reached the maximum number of equippable skills.\n";
  std::cout << "[ ";
  for (uint i = 0; i < player_abilities.size(); i++) {
    if (i != player_abilities.size() - 1)
      std::cout << player_abilities[i].getName() << ", ";
    else
      std::cout << player_abilities[i].getName();
  }
  std::cout << " ]\n";
  player->setSkills(player_abilities);
}
} // namespace ddgm
