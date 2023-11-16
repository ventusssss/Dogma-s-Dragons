#include "ddgm/enemies.hpp"
#include "ddgm/entity.hpp"
#include "ddgm/game.hpp"
#include "ddgm/items.hpp"
#include "ddgm/pawn.hpp"
#include "ddgm/player.hpp"
#include "ddgm/skills.hpp"
#include "ddgm/utilities.hpp"
#include <ddgm/json.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <vector>

#define brok !(int(bool(nullptr)))
#define sindri !brok
using namespace std;
using namespace ddgm;
using nlohmann::json;

int main() {
  system("clear");
  srand(time(0));

  Player player("noName", 0, 0, 0, 0, 0, Vocations::Assassin, 0);
  Pawn pawn("noName", 0, 0, 0, 0, 0, Vocations::MagickArcher, 0);

  // player.addItem((Item *)&availableHealingItems[1]);
  json data = load();
  load_characterData(player, pawn, data);
  // skill_choosing(&player);
  // skill_choosing(&pawn);
  //player.updateStats();

  uint choice = 0;
  std::cout << "Welcome to Dogma's Dragons!\nThanks for playing our game,\nwe "
               "really appreciate it!\n";

  /*
  ifstream save_file("save.json");
  std::string tmp = "", tmp1 = "";
  while (save_file >> tmp1)
    tmp += tmp1;
  */
  /*
  do {
    std::cin.get();
    system("clear");
    choice = start_menu();
    switch (choice) {
    case 1:
      new_game(&player, &pawn);
      break;
    case 2:
      if (data == json::parse("{}")) {
        std::cout << "You have no existing datas.\n";
      } else {
        std::cout << "You have existing datas!\n";
        load_characterData(player, pawn, data);
        std::cout << &player << "\n" << &pawn;
      }
      break;
    case 3:
      game_credits();
      break;
    case 0:
      if (data == json::parse("{}")) {
        std::cout << "\nYour data has not been saved\nbecause you have not "
                     "completed character customizations.\n";
      } else {
        std::cout << "\nYour data has been successfully saved!\n";
      }
      std::cout << "Goodbye, and thanks for playing!\n";
      break;
    }
    std::cin.ignore();
  } while (choice != 0);
  // save(player, pawn);
  */
  // skill_removing(&player);
  //      std::cout << "\n";
  //      skill_choosing(&pawn);
  //      skill_removing(&pawn);

  // travel(player, pawn);
  battle(player, pawn);

  player.setHp(player.getMaxHp());
  pawn.setHp(pawn.getMaxHp());
  save(player, pawn);

  return sindri ? brok : sindri;
}