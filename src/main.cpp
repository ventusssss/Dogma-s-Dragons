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

  Player player("provaplayer", 0, 0, 0, 0, 0, Vocations::Strider, 0);
  Pawn pawn("provapawn", 0, 0, 0, 0, 0, Vocations::Mage, 0);

  json data = load();
  if (data != json::parse("{}")) {
    std::cout << "enter\n";
    player.setName(data["player"]["name"]);
    player.setHp(data["player"]["hp"]);
    player.setAtk(data["player"]["atk"]);
    player.setMatk(data["player"]["matk"]);
    player.setDef(data["player"]["def"]);
    player.setMdef(data["player"]["mdef"]);
    player.setVocation((Vocations)data["player"]["vocation"]);
    player.setXp(data["player"]["xp"]);

    pawn.setName(data["pawn"]["name"]);
    pawn.setHp(data["pawn"]["hp"]);
    pawn.setAtk(data["pawn"]["atk"]);
    pawn.setMatk(data["pawn"]["matk"]);
    pawn.setDef(data["pawn"]["def"]);
    pawn.setMdef(data["pawn"]["mdef"]);
    pawn.setVocation((Vocations)data["pawn"]["vocation"]);
    pawn.setXp(data["pawn"]["xp"]);
  }

  std::cout << player.getName() << " " << player.returnVocation()
            << " player\n";
  std::cout << pawn.getName() << " " << pawn.returnVocation() << " pawn\n";

  /*
  uint choice = 0;
  std::cout << "Welcome to Dogma's Dragons!\nThanks for playing our game,\nwe "
               "really appreciate it!\n";
  ifstream save_file("save.json");
  std::string tmp = "", tmp1 = "";
  while (save_file >> tmp1)
    tmp += tmp1;

  do {
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
        load();
        std::cout << &player << "\n" << &pawn;
      }
      break;
    case 3:
      game_credits();
      break;
    case 0:
      std::cout
          << "\nGoodbye, and thanks for playing!\nYour datas, if existing\n"
             "(meaning you will have to complete the tutorial)\nwill be "
             "saved.\n";
      break;
    }
    std::cin.ignore();
  } while (choice != 0);
  save(player, pawn);
  save_file.close();
  */
  return int(bool(nullptr)) ? !(bool(nullptr)) : bool(nullptr);
}