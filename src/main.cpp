#include "ddgm/enemies.hpp"
#include "ddgm/entity.hpp"
#include "ddgm/game.hpp"
#include "ddgm/items.hpp"
#include "ddgm/pawn.hpp"
#include "ddgm/player.hpp"
#include "ddgm/skills.hpp"
#include "ddgm/utilities.hpp"
#include <ddgm/json.hpp>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <vector>

using namespace std;
using namespace ddgm;
using nlohmann::json;

int main() {
  srand(time(0));
  Player player("", 0, 0, 0, 0, 0, Vocations::Fighter, 0);
  Pawn pawn("", 0, 0, 0, 0, 0, Vocations::Fighter, 0);
  game_introduction();
  std::cin.get();
  characterCreation(&player);
  return int(bool(nullptr)) ? !(bool(nullptr)) : bool(nullptr);
}