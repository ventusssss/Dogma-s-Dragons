#include "ddgm/game.hpp"
#include "ddgm/items.hpp"
#include "ddgm/player.hpp"
#include "ddgm/skills.hpp"
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
  while (std::cin.fail() || (c < 0 || c > 3)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Please choose a valid option\n>> ";
    std::cin >> c;
  }
  return c;
}

void new_game(Player *player, Pawn *pawn) {
  game_introduction();
  characterCreation(player);
  game_progression(pawn);
  save(*player, *pawn);
}

void load_characterData(Player *player, Pawn *pawn, nlohmann::json data) {
  if (data != nlohmann::json::parse("{}")) {

    player->setName(data["player"]["name"]);
    player->setHp(data["player"]["hp"]);
    player->setAtk(data["player"]["atk"]);
    player->setMatk(data["player"]["matk"]);
    player->setDef(data["player"]["def"]);
    player->setMdef(data["player"]["mdef"]);
    player->setVocation((Vocations)data["player"]["vocation"]);
    player->setXp(data["player"]["xp"]);

    std::vector<Skill> tmpSkills;

    for (const auto &skill : data["player"]["skills"]) {
      if (skill.is_object() && skill.contains("name") &&
          skill.contains("type") && skill.contains("multiplier") &&
          skill.contains("cooldown")) {
        uint tmpCd = skill["cooldown"];
        float tmpMul = skill["multiplier"];
        std::string tmpName = skill["name"];
        uint tmpType = skill["type"];
        Skill tmpSkill(tmpName, tmpCd, (Skill::SkillType)tmpType, tmpMul);
        tmpSkills.push_back(tmpSkill);
      }
    }
    player->setSkills(tmpSkills);
    tmpSkills.clear();
    tmpSkills.shrink_to_fit();

    std::vector<Item *> tmpItems;

    for (const auto &item : data["player"]["inventory"]) {
      if (item.is_object() && item.contains("name") && item.contains("value") &&
          item.contains("description")) {
        std::string tmpDescription = item["description"];
        std::string tmpName = item["name"];
        uint tmpValue = item["value"];
        Item tmpItem(tmpName, tmpValue, tmpDescription);
        tmpItems.push_back(&tmpItem);
      }
    }
    player->setInventory(tmpItems);
    tmpItems.clear();
    tmpItems.shrink_to_fit();
  }
}

int game_menu() {
  uint c;
  std::cout << "1. Travel\n";
  std::cout << "2. Change Abilities\n";
  std::cout << "3. Change Vocation\n";
  std::cout << "4. Check Stats\n";
  std::cout << "0. Main Menu\n";
  std::cout << ">> ";
  std::cin >> c;
  while (std::cin.fail() || (c < 0 || c > 4)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Please choose a valid option\n>> ";
    std::cin >> c;
  }
  return c;
}

void game_introduction() {
  system("clear");
  std::cout << "Legends tell that a Dragon has populated these lands since "
               "time immemorial.\nWhether it was the same creature over the "
               "centuries, no one can tell,\nfor no one has ever lived "
               "enough to witness...or did someone?\n";
  std::cin.get();
  std::cout << "The people haven't seen the Dragon for over fifty "
               "years now,\nand peace seems to reign sovereign in people's "
               "hearts once more.\n";

  std::cin.get();
  std::cout
      << "But one day is enough to turn the people's hope into pure fear.\n";

  std::cin.get();
  std::cout
      << "That day, the Dragon landed on the sea village of "
         "Cassardis.\nThe Royal Guards were in a mix of disbelief and "
         "terror at its appearance.\nEveryone tried to flee, but many "
         "were struck by The Dragon's infernal flames.\nAmongst all "
         "those terrified people, one person stepped forward,\ndetermined "
         "to fight The Dragon.\n";

  std::cin.get();
  std::cout << "The brave one was just a fisherman, but he wielded a rusted "
               "sword\nand challenged the Dragon. He stood no choice.\nThe "
               "Dragon struck him with his paw,\nbut in that moment, the "
               "fisherman also managed\nto thrust the weapon into the Dragon's "
               "hand.\n";

  std::cin.get();
  std::cout
      << "Something awakened in the Dragon. Its eyes turned red as fire,\n"
         "and it seemed to realize what was happening.\nThe Beast then "
         "raised his paw, and with a single touch,\nhe ripped the heart "
         "of the fisherman.\n";

  std::cin.get();
  std::cout
      << "It then flee away, speaking in an ancient language\nonly the "
         "fisherman could apparently understand.\nIt said \"Come and get me, "
         "slay me. You'll find me on the tallest peak of the kingdom\"\n";

  std::cin.get();
  std::cout << "The fisherman woke up in a house, with a scar on his chest,"
               "\nin disbelief that he survived.\nSuddently, the scar "
               "enlightened,\nand the man heard the phrase that the Dragon "
               "told him before.\n";

  std::cin.get();
  std::cout << "Then, his beloved entered the room. To check if he was well,"
               "\nshe asked a few questions,\nbeginning with simply asking him "
               "his name.\n";

  std::cin.get();
}

void game_progression(Pawn *pawn) {
  system("clear");
  std::cout
      << "After packing all your things, and saying goodbye to your "
         "loved ones,\nyou prepare for leaving the Cassardis village,\nin "
         "order to find the dragon, and get your heart back.\n";
  std::cin.ignore();
  std::cin.get();
  std::cout << "But, before leaving, you notice a strange rock,\nwith strange "
               "symbols and patterns hollowed out.\nSuddently, the rock starts "
               "glowing with a bluish color,\nand from inside, you hear a "
               "voice.\n";
  std::cin.get();
  std::cout
      << "\"Arisen, chosen one. Come and touch this Rift "
         "Stone.\n"
         "You'll connect with another dimension, the Pawn Dimension.\nThe "
         "Pawns "
         "are meant to serve the Arisen only.\nThen come, and let your heart "
         "choose the best companion for your journey\"\n";
  std::cin.get();
  system("clear");
  characterCreation(pawn);
  system("clear");
  std::cin.ignore();
  std::cout
      << "You enter the so called \"Rift\", and you see coming towards you a "
         "person\nthat looks a lot like your best friend, but it's clearly "
         "not "
         "him.\nIt must be that \"Pawn\" the Rift Voice was talking "
         "about.\nYou "
         "aproach the Pawn and, as soon as you do to greet him,\nhe shows "
         "his "
         "hand, and you notice a strage bright scar on the palm.\n";
  std::cin.get();
  std::cout << "You immediately go back to the normal world,\nand even if it "
               "seems like only a few seconds passed to you,\nit has already "
               "become night.\nSo, you decide to wait 'till tomorrow morning "
               "to leave.\nIt's commonly known that the roads aren't safe at "
               "night.\n";
  std::cin.get();
  std::cout
      << "During the night, you notice that your partner doesn't sleep.\n"
         "So, intrigued, you ask him\n\"Hey, wouldn't you mind some rest? "
         "Tomorrow's gonna be a tough day\"\nAfter listening what you "
         "had to say, he replied\n\"Pawns do not need rest, Master\""
         "\nAtsounded, you go back to sleep.\n";
  std::cin.get();
  std::cout
      << "You wake up at the crack of dawn.\nStill a bit stunned, you "
         "hear the Pawn say \"Have you slept well, Master?\"\nAt first, "
         "you scare a bit, but after setting up all your memories,\nyou "
         "answer \"Oh, well thanks, and yo-\nWait, right, you do not need "
         "rest. And ehm, one more thing.\nDon't call me Master, please. "
         "You make me unconfortable!\"\n";
  std::cin.get();
  std::cout << "The Pawn strangely looks at you, and nods with his head.\nThen "
               "you ask him \"So...what is YOUR name?\nI mean, you must have "
               "one, everyone does\"\nThe Pawn looks at you with a puzzled "
               "look, and says\n\"Master, you know my name is "
            << pawn->getName() << ", it was you who gave it to me.\"\n";
  std::cin.get();
  std::cout << "Upon hearing that name, your face goes pale, and you say\n"
               "\"Wait, wait wait...that is not possible...THAT was...my best "
               "friend's name...how could this be...\"\n";
  std::cin.get();
  std::cout << "The Pawn replies saying \"Pawns are made in the image and "
               "likeness of the Arisen's dearest people\"\n";
  std::cin.get();
  std::cout << "Those words are for you the clear explanation of the "
               "similarity noticed previously.\n";
  std::cin.get();
  std::cout << "After getting your head back on track, you take your things "
               "and finally,\nafter saying goodbye to everyone for the last "
               "time,\nset off for your adventure.\n";
  std::cin.get();
  std::cout
      << "This, is where your journey begins.\nNow it's your time to make "
         "your "
         "way to The Dragon.\nYou do not know what risks you're facing.\nYou "
         "only know what your goal is, and that you'll do anything to "
         "acomplish it.\n";
  std::cin.get();
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
    std::cout << "Choose a name for your Pawn\n>> ";
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
  char ans = ' ';
  do {
    std::cout << "Choose the starting vocation: \n";
    std::cout << "1. Fighter, grants a high bonus to DEF when levelling up. "
                 "\n   Small increase of life too.\n";
    std::cout << "2. Strider, grants a small increase to ATK and DEF when "
                 "levelling up.\n";
    std::cout << "3. Mage, grants a huge boost to MDEF when levelling up.\n";
    std::cout << "(Other stats will also increase, but in a less significant "
                 "way)\n";
    std::cout << ">> ";
    std::cin >> vocation;
    while (std::cin.fail() || (vocation < 1 || vocation > 3)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Choose a valid vocation: ";
      std::cin >> vocation;
    }
    std::cin.ignore();
    std::cout << "Do you really want to chose this Vocation? Y/N\n>> ";
    std::cin >> ans;
    while (tolower(ans) != 'y' && tolower(ans) != 'n') {
      std::cout << "Select Y or N: ";
      std::cin >> ans;
    }
  } while (ans != 'y');
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
  for (uint i = 0, j = 0; i < 6; i++, j++) {
    std::cout << "\n" << j + 1 << ") Name: " << skills[i].getName() << "\n";
    std::cout << "   Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "   Cooldown: " << skills[i].getCd() << "\n";
  }
}

void warrior_skills() {
  for (uint i = 6, j = 0; i < 12; i++, j++) {
    std::cout << "\n" << j + 1 << ") Name: " << skills[i].getName() << "\n";
    std::cout << "   Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "   Cooldown: " << skills[i].getCd() << "\n";
  }
}

void paladin_skills() {
  for (uint i = 12, j = 0; i < 18; i++, j++) {
    std::cout << "\n" << j + 1 << ") Name: " << skills[i].getName() << "\n";
    std::cout << "   Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "   Cooldown: " << skills[i].getCd() << "\n";
  }
}

void strider_skills() {
  for (uint i = 18, j = 0; i < 24; i++, j++) {
    std::cout << "\n" << j + 1 << ") Name: " << skills[i].getName() << "\n";
    std::cout << "   Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "   Cooldown: " << skills[i].getCd() << "\n";
  }
}

void ranger_skills() {
  for (uint i = 24, j = 0; i < 30; i++, j++) {
    std::cout << "\n" << j + 1 << ") Name: " << skills[i].getName() << "\n";
    std::cout << "   Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "   Cooldown: " << skills[i].getCd() << "\n";
  }
}

void assassin_skills() {
  for (uint i = 30, j = 0; i < 36; i++, j++) {
    std::cout << "\n" << j + 1 << ") Name: " << skills[i].getName() << "\n";
    std::cout << "   Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "   Cooldown: " << skills[i].getCd() << "\n";
  }
}

void mage_skills() {
  for (uint i = 36, j = 0; i < 45; i++, j++) {
    std::cout << "\n" << j + 1 << ") Name: " << skills[i].getName() << "\n";
    std::cout << "   Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "   Cooldown: " << skills[i].getCd() << "\n";
  }
}

void sorcerer_skills() {
  for (uint i = 45, j = 0; i < 55; i++, j++) {
    std::cout << "\n" << j + 1 << ") Name: " << skills[i].getName() << "\n";
    std::cout << "   Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "   Cooldown: " << skills[i].getCd() << "\n";
  }
}

void magickarcher_skills() {
  for (uint i = 55, j = 0; i < 62; i++, j++) {
    std::cout << "\n" << j + 1 << ") Name: " << skills[i].getName() << "\n";
    std::cout << "   Damage Type: " << skills[i].getSkillType() << "\n";
    std::cout << "   Cooldown: " << skills[i].getCd() << "\n";
  }
}

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
      skill = check_skill(6);
      std::cin.ignore();
      if (!skill)
        break;
      if (find_skill(player_abilities, skills[skill - 1])) {
        std::cout << "You already have this skill set.\n";
        std::cin.get();
        continue;
      } else {
        if ((skill == 5) && (player->getFighterLvls() < 2)) {
          std::cout << "\nYou cannot set this skill yet.\nYou have to do at "
                       "least 2 "
                       "levels as a Fighter.\nNow you currently have "
                    << player->getFighterLvls() << " levels as a Fighter.\n";

          std::cin.get();
          continue;
        } else if ((skill == 6) && (player->getFighterLvls() < 3)) {
          std::cout << "\nYou cannot set this skill yet.\nYou have to do at "
                       "least 3 "
                       "levels as a Fighter.\nNow you currently have "
                    << player->getFighterLvls() << " levels as a Fighter.\n";
          std::cin.get();
          continue;
        }
      }
      player_abilities.push_back(skills[skill - 1]);
    } while (skill != 0 && player_abilities.size() < 6);
    break;
  case Vocations::Strider:
    do {
      system("clear");
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
      skill = check_skill(6);
      std::cin.ignore();
      if (!skill)
        break;
      if (find_skill(player_abilities, skills[skill + 17])) {
        std::cout << "You already havr this skill set.\n";
        std::cin.get();
        continue;
      } else {
        if (((skill == 3) || (skill == 5)) && (player->getStriderLvls() < 2)) {
          std::cout << "\nYou cannot set this skill yet.\nYou have to do at "
                       "least 2 "
                       "levels as a Strider.\nNow you currently have "
                    << player->getStriderLvls() << " levels as a Strider.\n";
          std::cin.get();
          continue;
        } else if ((skill == 4) && (player->getStriderLvls() < 3)) {
          std::cout << "\nYou cannot set this skill yet.\nYou have to do at "
                       "least 3 "
                       "levels as a Strider.\nNow you currently have "
                    << player->getStriderLvls() << " levels as a Strider.\n";
          std::cin.get();
          continue;
        }
      }
      skill += 17;
      player_abilities.push_back(skills[skill]);
    } while (skill != 0 && player_abilities.size() < 6);
    break;
  case Vocations::Mage:
    do {
      system("clear");
      mage_skills();
      std::cout << "0) None\n\n";
      std::cout << "Skills that end with the word \"Pact\"\nare a special kind "
                   "of skills\nthat do not damage the enemy, but instead\nthey "
                   "buff the Arisen's weapon\nwith that specific element.\n";
      std::cout << "\nHigh Spellscrean is a skill that allows the healing of "
                   "an Arisen or a Pawn.\n";
      std::cout << "\n[ ";
      for (uint i = 0; i < player_abilities.size(); i++) {
        if (i != player_abilities.size() - 1)
          std::cout << player_abilities[i].getName() << ", ";
        else
          std::cout << player_abilities[i].getName();
      }
      std::cout << " ]\n";
      std::cout << "\nChoose which skill you want to add to your roaster\n>> ";
      skill = check_skill(9);
      std::cin.ignore();
      if (!skill)
        break;
      if (find_skill(player_abilities, skills[skill + 35])) {
        std::cout << "You already have this skills set.\n";
        std::cin.get();
        continue;
      } else {
        if ((skill == 9) && (player->getMageLvls() < 3)) {
          std::cout << "\nYou cannot set this skill yet.\nYou have to do at "
                       "least 3 "
                       "levels as a Mage.\nNow you currently have "
                    << player->getMageLvls() << " levels as a Mage.\n";
          std::cin.get();
          continue;
        }
      }
      skill += 35;
      player_abilities.push_back(skills[skill]);
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
      skill = check_skill(6);
      std::cin.ignore();
      if (!skill)
        break;
      if (find_skill(player_abilities, skills[skill + 5])) {
        std::cout << "You already have this skill set.\n";
        std::cin.get();
        continue;
      } else {
        if ((skill == 5) && (player->getWarriorLvls() < 2)) {
          std::cout << "\nYou cannot set this skill yet.\nYou have to do at "
                       "least 2 "
                       "levels as a Warrior.\nNow you currently have "
                    << player->getWarriorLvls() << " levels as a Warrior.\n";
          std::cin.get();
          continue;
        } else if ((skill == 6) && (player->getWarriorLvls() < 5)) {
          std::cout << "\nYou cannot set this skill yet.\nYou have to do at "
                       "least 5 "
                       "levels as a Warrior.\nNow you currently have "
                    << player->getWarriorLvls() << " levels as a Warrior.\n";
          std::cin.get();
          continue;
        }
      }
      skill += 5;
      player_abilities.push_back(skills[skill]);
    } while (skill != 0 && player_abilities.size() < 6);
    break;
  case Vocations::Ranger:
    do {
      system("clear");
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
      skill = check_skill(6);
      std::cin.ignore();
      if (!skill)
        break;
      if (find_skill(player_abilities, skills[skill + 23])) {
        std::cout << "You already have this skill set.\n";
        std::cin.get();
        continue;
      } else {
        if ((skill == 4) && (player->getRangerLvls() < 3)) {
          std::cout << "\nYou cannot set this skill yet.\nYou have to do at "
                       "least 3 "
                       "levels as a Ranger.\nNow you currently have "
                    << player->getRangerLvls() << " levels as a Ranger.\n";
          std::cin.get();
          continue;
        } else if ((skill == 6) && (player->getRangerLvls() < 4)) {
          std::cout << "\nYou cannot set this skill yet.\nYou have to do at "
                       "least 4 "
                       "levels as a Ranger.\nNow you currently have "
                    << player->getRangerLvls() << " levels as a Ranger.\n";
          std::cin.get();
          continue;
        }
      }
      skill += 23;
      player_abilities.push_back(skills[skill]);
    } while (skill != 0 && player_abilities.size() < 6);
    break;
  case Vocations::Sorcerer:
    do {
      system("clear");
      sorcerer_skills();
      std::cout << "0) None\n\n";
      std::cout << "Skills that end with the word \"Pact\"\nare a special kind "
                   "of skills\nthat do not damage the enemy, but instead\nthey "
                   "buff the Arisen's weapon\nwith that specific element.\n";
      std::cout << "\n[ ";
      for (uint i = 0; i < player_abilities.size(); i++) {
        if (i != player_abilities.size() - 1)
          std::cout << player_abilities[i].getName() << ", ";
        else
          std::cout << player_abilities[i].getName();
      }
      std::cout << " ]\n";
      std::cout << "\nChoose which skill you want to add to your roaster\n>> ";
      skill = check_skill(10);
      std::cin.ignore();
      if (!skill)
        break;
      if (find_skill(player_abilities, skills[skill + 44])) {
        std::cout << "You already have this skill set.\n";
        std::cin.get();
        continue;
      } else {
        if ((isInRange(skill, 1, 4)) && (player->getSorcererLvls() < 5)) {
          std::cout << "\nYou cannot set this skill yet.\nYou have to do at "
                       "least 5 "
                       "levels as a Sorcerer.\nNow you currently have "
                    << player->getSorcererLvls() << " levels as a Sorcerer.\n";
          std::cin.get();
          continue;
        }
      }
      skill += 44;
      player_abilities.push_back(skills[skill]);
    } while (skill != 0 && player_abilities.size() < 6);
    break;
  case Vocations::Assassin:
    do {
      system("clear");
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
      skill = check_skill(6);
      std::cin.ignore();
      if (!skill)
        break;
      if (find_skill(player_abilities, skills[skill + 29])) {
        std::cout << "You already have this skill set.\n";
        std::cin.get();
        continue;
      } else {
        if (((skill == 2) || (skill == 6)) && (player->getAssassinLvls() < 2)) {
          std::cout << "\nYou cannot set this skill yet.\nYou have to do at "
                       "least 2 "
                       "levels as an Assassin.\nNow you currently have "
                    << player->getAssassinLvls() << " levels as Assassin.\n";
          std::cin.get();
          continue;
        } else if ((skill == 4) && (player->getAssassinLvls() < 3)) {
          std::cout << "\nYou cannot set this skill yet.\nYou have to do at "
                       "least 3 "
                       "levels as an Assassin.\nNow you currently have "
                    << player->getAssassinLvls() << " levels as Assassin.\n";
          std::cin.get();
          continue;
        }
      }
      skill += 29;
      player_abilities.push_back(skills[skill]);
    } while (skill != 0 && player_abilities.size() < 6);
    break;
  case Vocations::MagickArcher:
    do {
      system("clear");
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
      skill = check_skill(7);
      std::cin.ignore();
      if (!skill)
        break;
      if (find_skill(player_abilities, skills[skill + 54])) {
        std::cout << "You already have this skill set.\n";
        std::cin.get();
        continue;
      } else {
        if ((isInRange(skill, 3, 4)) && (player->getMagickArcherLvls() < 3)) {
          std::cout << "\nYou cannot set this skill yet.\nYou have to do at "
                       "least 3 "
                       "levels as a Magick Archer.\nNow you currently have "
                    << player->getMagickArcherLvls()
                    << " levels as a Magick Archer.\n";
          std::cin.get();
          continue;
        } else if ((skill == 7) && (player->getMagickArcherLvls() < 5)) {
          std::cout << "\nYou cannot set this skill yet.\nYou have to do at "
                       "least 5 "
                       "levels as a Magick Archer.\nNow you currently have "
                    << player->getMagickArcherLvls()
                    << " levels as a Magick Archer.\n";
          std::cin.get();
          continue;
        }
      }
      skill += 54;
      player_abilities.push_back(skills[skill]);
    } while (skill != 0 && player_abilities.size() < 6);
    break;
  case Vocations::Paladin:
    do {
      system("clear");
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
      skill = check_skill(6);
      std::cin.ignore();
      if (!skill)
        break;
      if (find_skill(player_abilities, skills[skill + 11])) {
        std::cout << "You already have this skill set.\n";
        std::cin.get();
        continue;
      } else {
        if ((skill == 3) && (player->getPaladinLvls() < 4)) {
          std::cout << "\nYou cannot set this skill yet.\nYou have to do at "
                       "least 4 "
                       "levels as a Paladin.\nNow you currently have "
                    << player->getPaladinLvls() << " levels as a Paladin.\n";
          std::cin.get();
          continue;
        }
      }
      skill += 11;
      player_abilities.push_back(skills[skill]);
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

void skill_removing(Player *player) {
  uint skill = 0;
  std::vector<Skill> player_abilities = player->getPlayerSkills();
  std::cout << "[ ";
  for (uint i = 0; i < player_abilities.size(); i++) {
    if (i == player_abilities.size() - 1) {
      std::cout << i + 1 << "." << player_abilities[i].getName();
    } else {
      std::cout << i + 1 << "." << player_abilities[i].getName() << ", ";
    }
  }
  std::cout << " ]\n";
}

} // namespace ddgm
