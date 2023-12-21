// #include "ddgm/enemies.hpp"
// #include "ddgm/entity.hpp"
#include "ddgm/enemies.hpp"
#include "ddgm/game.hpp"
// #include "ddgm/items.hpp"
// #include "ddgm/items.hpp"
#include "ddgm/items.hpp"
#include "ddgm/pawn.hpp"
#include "ddgm/player.hpp"
// #include "ddgm/skills.hpp"
#include "ddgm/utilities.hpp"
#include <ddgm/json.hpp>
// #include <filesystem>
// #include <fstream>
#include <iostream>
#include <unistd.h>
// #include <vector>

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

  json data = load();
  load_characterData(player, pawn, data);

  uint choice = 0;
  std::cout << "Welcome to Dogma's Dragons!\nThanks for playing our game,\nwe "
               "really appreciate it!\n";

  player.setHp(player.getMaxHp());
  pawn.setHp(pawn.getMaxHp());

  choose_item(player, selectable_enemies);
  
  save(player, pawn);

  return sindri ? brok : sindri;
}