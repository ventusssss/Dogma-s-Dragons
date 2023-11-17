#include "ddgm/game.hpp"
#include "ddgm/enemies.hpp"
#include "ddgm/items.hpp"
#include "ddgm/pawn.hpp"
#include "ddgm/player.hpp"
#include "ddgm/skills.hpp"
#include "ddgm/utilities.hpp"
#include <array>
#include <cctype>
#include <iostream>
#include <unistd.h>
#include <vector>

namespace ddgm {

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

// function to load the stats contained in the "save.json" file
void load_characterData(Player &player, Pawn &pawn, nlohmann::json data) {
  // checking if the file isn't empty
  if (data != nlohmann::json::parse("{}")) {
    // setting all the attributes value to the
    // corresponding value inside the file
    player.setName(data["player"]["name"]);
    player.setHp(data["player"]["hp"]);
    player.setMaxHp(player.getHp());
    player.setAtk(data["player"]["atk"]);
    player.setMatk(data["player"]["matk"]);
    player.setDef(data["player"]["def"]);
    player.setMdef(data["player"]["mdef"]);
    player.setVocation((Vocations)data["player"]["vocation"]);
    player.setXp(data["player"]["xp"]);

    player.setFighterLvls(data["player"]["fighter_levels"]);
    player.setStriderLvls(data["player"]["strider_levels"]);
    player.setMageLvls(data["player"]["mage_levels"]);
    player.setWarriorLvls(data["player"]["warrior_levels"]);
    player.setRangerLvls(data["player"]["ranger_levels"]);
    player.setSorcererLvls(data["player"]["sorcerer_levels"]);
    player.setAssassinLvls(data["player"]["assassin_levels"]);
    player.setMagickArcherLvls(data["player"]["magickarcher_levels"]);
    player.setPaladinLvls(data["player"]["paladin_levels"]);

    // creating a temporary vector of type skills to store
    // each skill contained in the file
    std::vector<Skill> skills;

    // iterating through all of the file skills
    for (nlohmann::json skill : data["player"]["skills"]) {
      // creating a temporary skill object to push inside
      // the skills vector
      Skill tmpSkill(skill["name"], skill["cooldown"],
                     (Skill::SkillType)skill["type"], skill["multiplier"]);
      skills.push_back(tmpSkill);
    }

    // and setting the skills vector as the player skills
    player.setSkills(skills);

    // doing literally the same thing as skills for items
    std::vector<Item> items;
    for (auto item : data["player"]["inventory"]) {
      Item tmpItem(item["name"], item["value"], item["description"]);
      items.push_back(tmpItem);
    }
    player.setInventory(items);

    // clearing the two vectors because we'll have to use them
    // for the pawn too
    skills.clear();
    skills.shrink_to_fit();

    items.clear();
    items.shrink_to_fit();

    // and doing the same thing we did with player
    pawn.setName(data["pawn"]["name"]);
    pawn.setHp(data["pawn"]["hp"]);
    pawn.setMaxHp(pawn.getHp());
    pawn.setAtk(data["pawn"]["atk"]);
    pawn.setMatk(data["pawn"]["matk"]);
    pawn.setDef(data["pawn"]["def"]);
    pawn.setMdef(data["pawn"]["mdef"]);
    pawn.setVocation((Vocations)data["pawn"]["vocation"]);
    pawn.setXp(data["pawn"]["xp"]);
    pawn.setFighterLvls(data["pawn"]["fighter_levels"]);
    pawn.setStriderLvls(data["pawn"]["strider_levels"]);
    pawn.setMageLvls(data["pawn"]["mage_levels"]);
    pawn.setWarriorLvls(data["pawn"]["warrior_levels"]);
    pawn.setRangerLvls(data["pawn"]["ranger_levels"]);
    pawn.setSorcererLvls(data["pawn"]["sorcerer_levels"]);
    pawn.setAssassinLvls(data["pawn"]["assassin_levels"]);
    pawn.setMagickArcherLvls(data["pawn"]["magickarcher_levels"]);
    pawn.setPaladinLvls(data["pawn"]["paladin_levels"]);

    for (auto skill : data["pawn"]["skills"]) {
      Skill tmpSkill(skill["name"], skill["cooldown"],
                     (Skill::SkillType)skill["type"], skill["multiplier"]);
      skills.push_back(tmpSkill);
    }
    pawn.setSkills(skills);

    for (auto item : data["pawn"]["inventory"]) {
      Item tmpItem(item["name"], item["value"], item["description"]);
      items.push_back(tmpItem);
    }
    pawn.setInventory(items);
  }
}

// creating the game menu for the in-game actions
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

// defining the travel function that has a 60% possibility
// of getting the players into a fight, and the remaining 40% to
// find an item
void travel(Player &player, Pawn &pawn) {
  uint travelPossibilities = generateRandom(1, 100);
  if (travelPossibilities <= 60) {
    battle(player, pawn);
  } else {
    // itemTypeFound is created to decide what type of item is found
    // (Healing, Buffer, Attack, Magick)
    uint itemTypeFound = generateRandom(1, 4);
    uint itemFound = 0;

    switch (itemTypeFound) {
    // inside each case it generates the random item
    // from the correspoding list AND a temporary value (0 or 1)
    // that indicates the item destination (1 player, 0 pawn)
    case 1: // case Healing
      itemFound = generateRandom(0, availableHealingItems.size() - 1);
      if (generateRandom(0, 1)) {
        player.addItem(availableHealingItems[itemFound]);
      } else {
        pawn.addItem(availableHealingItems[itemFound]);
      }
      break;
    case 2: // case Attack
      itemFound = generateRandom(0, availableAttackItems.size() - 1);
      if (generateRandom(0, 1)) {
        player.addItem(availableAttackItems[itemFound]);
      } else {
        pawn.addItem(availableAttackItems[itemFound]);
      }
      break;
    case 3: // case Magick
      itemFound = generateRandom(0, availableMagicItems.size() - 1);
      if (generateRandom(0, 1)) {
        player.addItem(availableMagicItems[itemFound]);
      } else {
        pawn.addItem(availableMagicItems[itemFound]);
      }
      break;
    case 4: // case Buffer
      itemFound = generateRandom(0, availableBufferItems.size() - 1);
      if (generateRandom(0, 1)) {
        player.addItem(availableBufferItems[itemFound]);
      } else {
        pawn.addItem(availableBufferItems[itemFound]);
      }
      break;
    }
  }
}

// substantialy, a function to display the enemies names
// when appearing in a grammatically correct way
std::vector<Enemy> enemies_appearing(uint enemyNumber) {
  std::vector<Enemy> enemiesToFight;
  std::vector<std::string> aEnemies = {
      "Golbin",   "Wolf",     "Bandit", "Saurian",    "Skeleton",
      "Gargoyle", "Succubus", "Ghost",  "Vile Eye",   "Cyclope",
      "Chimera",  "Golem",    "Wyrm",   "Frost Wyrm", "Drake"};

  for (uint i = 0; i < enemyNumber; i++) {
    enemiesToFight.push_back(
        selectable_enemies[generateRandom(0, selectable_enemies.size() - 1)]);
  }

  for (uint i = 0; i < enemiesToFight.size(); i++) {
    if (enemiesToFight.size() == 1) {
      if (isIn(enemiesToFight[i].getName(), aEnemies)) {
        std::cout << "A " << enemiesToFight[i].getName() << " has appeared!\n";
      } else {
        std::cout << "An " << enemiesToFight[i].getName() << " has appeared!\n";
      }
    } else {
      if (enemiesToFight.size() == 2) {
        if (!i) {
          if (isIn(enemiesToFight[i].getName(), aEnemies)) {
            std::cout << "A " << enemiesToFight[i].getName() << " ";
          } else {
            std::cout << "An " << enemiesToFight[i].getName() << " ";
          }
        } else {
          std::cout << "and ";
          if (isIn(enemiesToFight[i].getName(), aEnemies)) {
            std::cout << "a " << enemiesToFight[i].getName()
                      << " have appeared!\n";
          } else {
            std::cout << "an " << enemiesToFight[i].getName()
                      << " have appeared!\n";
          }
        }
      } else if (enemiesToFight.size() > 2) {
        if (!i) {
          if (isIn(enemiesToFight[i].getName(), aEnemies)) {
            std::cout << "A " << enemiesToFight[i].getName() << ", ";
          } else {
            std::cout << "An " << enemiesToFight[i].getName() << ", ";
          }
        } else if (i > 0 && i < (enemiesToFight.size() - 1)) {
          if (i == (enemiesToFight.size() - 2)) {
            if (isIn(enemiesToFight[i].getName(), aEnemies)) {
              std::cout << "a " << enemiesToFight[i].getName() << " ";
            } else {
              std::cout << "an " << enemiesToFight[i].getName() << " ";
            }
          } else {
            if (isIn(enemiesToFight[i].getName(), aEnemies)) {
              std::cout << "a " << enemiesToFight[i].getName() << ", ";
            } else {
              std::cout << "an " << enemiesToFight[i].getName() << ", ";
            }
          }
        } else if (i == (enemiesToFight.size() - 1)) {
          std::cout << "and ";
          if (isIn(enemiesToFight[i].getName(), aEnemies)) {
            std::cout << "a " << enemiesToFight[i].getName()
                      << " have appeared!\n";
          } else {
            std::cout << "an " << enemiesToFight[i].getName()
                      << " have appeared!\n";
          }
        }
      }
    }
  }
  return enemiesToFight;
}

// function to read the battle choice from user
uint battle_start() {
  uint battleChoice = 0;
  std::cout << "\n";
  std::cout << "1. Attack\n";
  std::cout << "2. Use Item\n";
  std::cout << "3. Flee\n";
  std::cout << ">> ";
  std::cin >> battleChoice;

  // controls if number is in range
  while (std::cin.fail() || (battleChoice < 1 || battleChoice > 3)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Choose a valid option: ";
    std::cin >> battleChoice;
  }
  std::cout << "\n";

  return battleChoice;
}

/*
  Returns subject index on user input
*/
uint enemy_choosing(std::vector<Enemy> vector) {
  uint enemyTarget = 0;
  std::cout << "Select the number of the enemy target\n";
  std::cout << "Selecting 0 gets back to Battle Choice\n>> ";
  std::cin >> enemyTarget;
  while (std::cin.fail() || (enemyTarget < 0 || enemyTarget > vector.size())) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Choose a valid enemy: ";
    std::cin >> enemyTarget;
  }
  return enemyTarget;
}

void display_enemies_names(std::vector<Enemy> enemies) {
  for (size_t i = 0; i < enemies.size(); i++) {
    std::cout << i + 1 << ") " << enemies[i].getName() << ": "
              << enemies[i].getHp() << "/" << enemies[i].getMaxHp() << "\n";
  }
}

void display_character_names(Player &player, Pawn &pawn) {
  std::cout << "\n- " << player.getName() << ": " << player.getHp() << "/"
            << player.getMaxHp() << "\n";
  std::cout << "- " << pawn.getName() << ": " << pawn.getHp() << "/"
            << pawn.getMaxHp() << "\n";
}

void display_skills(std::vector<Skill *> usable_skills) {
  std::cout << "Choose action to perform\n";
  for (size_t i = 0; i < usable_skills.size(); i++) {
    std::cout << i + 1 << ". " << usable_skills[i]->getName() << " ("
              << usable_skills[i]->getSkillType() << ")"
              << "\n";
  }
  std::cout << "0. Base Attack\n";
  std::cout << usable_skills.size() + 1 << ". Target Selection\n>> ";
}

std::vector<Entity> display_entities(Player &player, Pawn &pawn,
                                     std::vector<Enemy> enemies) {
  // entity number to take count of all entities
  uint entity_number = 1;

  // vector to store the entities
  std::vector<Entity> entities;
  std::cout << "Select the entity you want to cure\n";
  std::cout << entity_number++ << ". "
            << "|Player| " << player.getName() << ": " << player.getHp() << "/"
            << player.getMaxHp() << "\n";
  entities.push_back(player);
  if (pawn.getHp()) {
    std::cout << entity_number++ << ". "
              << "|Pawn| " << pawn.getName() << ": " << pawn.getHp() << "/"
              << pawn.getMaxHp() << "\n";
    entities.push_back(pawn);
    for (Enemy &enemy : enemies) {
      std::cout << entity_number++ << ". "
                << "|Enemy| " << enemy.getName() << ": " << enemy.getHp() << "/"
                << enemy.getMaxHp() << "\n";
      entities.push_back(enemy);
    }
  } else {
    for (Enemy &enemy : enemies) {
      std::cout << entity_number++ << ". "
                << "|Enemy| " << enemy.getName() << ": " << enemy.getHp() << "/"
                << enemy.getMaxHp() << "\n";
      entities.push_back(enemy);
    }
  }
  std::cout << ">> ";
  return entities;
}

uint entity_choice(std::vector<Entity> entities) {
  uint choice = 0;
  std::cin >> choice;
  while (std::cin.fail() || (choice < 1 || choice > entities.size())) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Choose a valid entity: ";
    std::cin >> choice;
  }
  return --choice;
}

// function to decide action choice (skills or normal attack)
uint attack_choice(std::vector<Skill *> usable_skills) {
  uint action = 0;
  std::cin >> action;
  while (std::cin.fail() || (action < 0 || action > usable_skills.size() + 1)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Choose a valid action: ";
    std::cin >> action;
  }
  return action;
}

// final battle function
void battle(Player &player, Pawn &pawn) {
  // creating an enemies vector that contains all the enemies
  // spawned by the enemies_appearing function
  std::vector<Enemy> enemies = enemies_appearing(generateRandom(1, 3));

  // creating an object of type enemy that will make as
  // destination for our attacks
  // then will change and will be a randomly chosen enemy
  // to attack
  Enemy *subject = nullptr;

  std::vector<Skill> player_skills = player.getSkills();
  std::vector<Skill *> usable_skills;
  Skill *skill = nullptr;

  std::cin.get();
  do {
    system("clear");
    uint choice = 0;
    bool on_turn = true;
    bool is_flee_success = false;

    // displaying all the enemies names and hp on screen
    display_enemies_names(enemies);

    // clears the usable_skills vector
    usable_skills.clear();
    usable_skills.shrink_to_fit();

    // select available skills
    for (Skill &skill : player_skills) {
      if (!skill.getActualCd())
        // if the skill is available (actual cd 0)
        // it gets pushed inside the usable_skills vect
        usable_skills.push_back(&skill);
      else
        // else, it means that has been already used,
        // so the cd gets decremented
        skill.decrement_cd();
    }

    // displays player and pawn names/hps
    display_character_names(player, pawn);

    // starts the battle
    std::cout << "\nSelect an action";
    switch (battle_start()) {
    // attack
    case 1: {
      system("clear");
      display_enemies_names(enemies);
      std::cout << "\n";
      pawn.battleTalk(casuality(60),
                      enemies[generateRandom(0, enemies.size() - 1)]);
      uint enemy_target = enemy_choosing(enemies);
      if (!enemy_target)
        break;
      subject = &enemies[enemy_target - 1];

      if (usable_skills.size()) {
        bool is_choice_reset = false;
        display_skills(usable_skills);
        choice = attack_choice(usable_skills);
        std::cout << "\n";
        while (choice == usable_skills.size() + 1) {
          system("clear");
          display_enemies_names(enemies);
          std::cout << "\n";
          enemy_target = enemy_choosing(enemies);
          if (!enemy_target)
            break;
          enemy_target--;
          display_skills(usable_skills);
          choice = attack_choice(usable_skills);
        }
        if (!enemy_target)
          continue;
        if (!choice)
          std::cout << "You dealt " << player.attack(*subject, nullptr)
                    << " damage to " << subject->getName() << "\n";
        else {
          choice--;
          skill = usable_skills[choice];
          if (skill->returnSkillType() == Skill::SkillType::cure) {
            system("clear");
            std::vector<Entity> entities =
                display_entities(player, pawn, enemies);
            // index for the entity to heal
            uint entity_to_heal = entity_choice(entities);
            Entity &entity = entities[entity_to_heal];
            uint previous_entity_hp = entity.getHp();
            entity.healEntity(percu(entity.getMaxHp(), 40));
            uint entity_heal_value = entity.getHp() - previous_entity_hp;
            std::cout << entity.getName() << " was healed of "
                      << entity_heal_value << "!\n";
          } else if (skill->getName() == "Fire Pact" ||
                     skill->getName() == "Ice Pact" ||
                     skill->getName() == "Thunder Pact" ||
                     skill->getName() == "Holy Pact" ||
                     skill->getName() == "Dark Pact") {
            if ((pawn.getVocation() == Vocations::Mage) ||
                (pawn.getVocation() == Vocations::Sorcerer)) {
              std::cout
                  << "This action can't be performed on Mage and Sorcerers\n";
              std::cin.ignore();
              std::cin.get();
              continue;
            } else {
              std::vector<Skill> *pawn_skills = pawn.getSkillsAddr();
              for (Skill &x : *pawn_skills) {
                x.setSkillType(skill->returnSkillType());
              }
              std::cout << "All of " << pawn.getName()
                        << "'s skill types have turned to "
                        << skill->getSkillType()
                        << " for the rest of the battle!\n";
            }
          } else {
            std::cout << "You dealt " << player.attack(*subject, skill)
                      << " damage to " << subject->getName() << "\n";
          }
          skill->use();
          usable_skills.erase(usable_skills.begin() + choice);
        }
      } else {
        std::cout << "You have no usable skills.\n";
        std::cout << "You will use a normal attack.\n";
        std::cout << "You dealt " << player.attack(*subject, nullptr)
                  << " damage to " << subject->getName() << "\n";
      }
      std::cout << "Remaining HP: " << subject->getHp() << "\n";

      // checking if enemy is dead (hp 0)
      if (!subject->getHp()) {
        std::cout << subject->getName() << " was defeated!\n";
        enemies.erase(enemies.begin() + enemy_target - 1);
        if (!enemies.size()) {
          std::cin.ignore();
          std::cin.get();
          break;
        }
      }

      if (pawn.getHp() && enemies.size()) {
        std::cout << "\n";
        subject = &enemies[generateRandom(0, enemies.size() - 1)];
        std::cout << pawn.getName() << " attacked " << subject->getName();
        std::cout << " and dealt " << pawn.pawn_attack(*subject, player)
                  << " damage\n\n";
      }

      if (enemies.size()) {
        // algorithm to make a random enemy attack the player
        subject = &enemies[generateRandom(0, enemies.size() - 1)];

        // deciding if to attack pawn or player
        if (!pawn.getHp()) {
          std::cout << subject->getName() << " dealt "
                    << subject->attack(player) << " damage to "
                    << player.getName() << "\n";
        } else if (generateRandom(0, 1)) {
          std::cout << subject->getName() << " dealt "
                    << subject->attack(player) << " damage to "
                    << player.getName() << "\n";
          std::cout << "Remaining HP: " << player.getHp() << "\n";
          if (!player.getHp()) {
            std::cout << "And so...the Arisen died...\n";
            std::cin.ignore();
            std::cin.get();
            break;
          }
        } else {
          std::cout << subject->getName() << " dealt " << subject->attack(pawn)
                    << " damage to " << pawn.getName() << "\n";
          std::cout << "Remaining HP: " << pawn.getHp() << "\n";
        }
      }
      std::cin.ignore();
      std::cin.get();
    } break;
    // use item
    case 2:
      break;
    // flee
    case 3:
      break;
    }
  } while (enemies.size() && player.getHp());
  system("clear");
  if (!player.getHp())
    std::cout << "The enemies got their best on you...\n";
  else
    std::cout << "You defeated all the enemies!\n";
}

void change_abilities(Player &player, Pawn &pawn) {}

void change_vocation(Player &player, Pawn &pawn) {}

void check_stats(Player &player, Pawn *pawn) {}

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
  std::cout

      << "The brave one was just a fisherman, but he wielded a rusted "
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
  std::cout

      << "Then, his beloved entered the room. To check if he was well,"
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
  std::cout

      << "But, before leaving, you notice a strange rock,\nwith strange "
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
  std::cout

      << "The Pawn strangely looks at you, and nods with his head.\nThen "
         "you ask him \"So...what is YOUR name?\nI mean, you must have "
         "one, everyone does\"\nThe Pawn looks at you with a puzzled "
         "look, and says\n\"Master, you know my name is "
      << pawn->getName() << ", it was you who gave it to me.\"\n";
  std::cin.get();
  std::cout

      << "Upon hearing that name, your face goes pale, and you say\n"
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
      std::cout

          << "\nChoose which skill you want to add to your roaster\n>> ";
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
      std::cout

          << "\nChoose which skill you want to add to your roaster\n>> ";
      skill = check_skill(6);
      std::cin.ignore();
      if (!skill)
        break;
      if (find_skill(player_abilities, skills[skill + 17])) {
        std::cout << "You already havr this skill set.\n";
        std::cin.get();
        continue;
      } else {
        if (((skill == 3) || (skill == 5)) &&

            (player->getStriderLvls() < 2)) {
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
      std::cout

          << "Skills that end with the word \"Pact\"\nare a special kind "
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
      std::cout

          << "\nChoose which skill you want to add to your roaster\n>> ";
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
      std::cout

          << "\nChoose which skill you want to add to your roaster\n>> ";
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
      std::cout

          << "\nChoose which skill you want to add to your roaster\n>> ";
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
      std::cout

          << "Skills that end with the word \"Pact\"\nare a special kind "
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
      std::cout

          << "\nChoose which skill you want to add to your roaster\n>> ";
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
                    << player->getSorcererLvls()

                    << " levels as a Sorcerer.\n";
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
      std::cout

          << "\nChoose which skill you want to add to your roaster\n>> ";
      skill = check_skill(6);
      std::cin.ignore();
      if (!skill)
        break;
      if (find_skill(player_abilities, skills[skill + 29])) {
        std::cout << "You already have this skill set.\n";
        std::cin.get();
        continue;
      } else {
        if (((skill == 2) || (skill == 6)) &&

            (player->getAssassinLvls() < 2)) {
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
      std::cout

          << "\nChoose which skill you want to add to your roaster\n>> ";
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
  std::vector<Skill> player_abilities = player->getSkills();

  do {
    system("clear");
    show_skills(player_abilities);
    std::cout << "Choose the skill you want to remove\n";
    std::cout << "Write 0 to get out: ";
    std::cin >> skill;
    while (std::cin.fail() || (skill < 0 || skill > player_abilities.size())) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Please choose a valid skill: ";
      std::cin >> skill;
    }

    if (!skill)
      break;

    player_abilities.erase(player_abilities.begin() + (skill - 1));

  } while (skill != 0);

  player->setSkills(player_abilities);
}

} // namespace ddgm
