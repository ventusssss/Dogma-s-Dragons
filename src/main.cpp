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

using namespace std;
using namespace ddgm;
using nlohmann::json;

int main() {
  system("clear");
  srand(time(0));
  Player player("", 0, 0, 0, 0, 0, Vocations::Fighter, 0);
  Pawn pawn("", 0, 0, 0, 0, 0, Vocations::Fighter, 0);

  uint choice = 0;
  // std::cout << "Welcome to Dogma's Dragons!\nThanks for playing our game,\nwe
  // "
  //             "really appreciate it!\n";

  ifstream save_file("save.json");
  std::string tmp = "", tmp1 = "";
  while (save_file >> tmp1)
    tmp += tmp1;

  /*do {
    std::cin.get();
    system("clear");
    choice = start_menu();
    switch (choice) {
    case 1:
      new_game(&player, &pawn);
      break;
    case 2:
      if (!save_file && tmp == "{}") {
        std::cout << "You have no existing datas.\n";
      } else {
        std::cout << "You have existing datas!\n";
      }
      break;
    case 3:
      game_credits();
      std::cin.get();
      break;
    case 0:
      std::cout
          << "Goodbye, and thanks for playing!\nYour datas will be saved.\n";
      std::cin.get();
      break;
    }
  } while (choice != 0);
  // save(player, pawn);
  std::cout << &player;
  save_file.close();*/
  new_game(&player, &pawn);

  std::cout << &player << "\n";
  std::cout << &pawn;

  return int(bool(nullptr)) ? !(bool(nullptr)) : bool(nullptr);
}