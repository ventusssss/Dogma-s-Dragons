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
  Player player = Player("Guts", 500, 250, 25, 250, 150, Vocations::Warrior, 0);
  Pawn pawn = Pawn("Brok", 110, 3, 4, 5, 6, Vocations::Sorcerer, 0);

  player.addItem(new Item(availableHealingItems[0]));
  player.addItem(new Item(availableAttackItems[0]));
  player.addItem(new Item(availableMagicItems[0]));
  player.addItem(new Item(availableBufferItems[0]));

  save(player, pawn);
  json data = load();

  for (uint i = 0; i < 20; i++) {
    std::cout << data["player"]["inventory"][0]["name"] << "\n";
  }

  return int(bool(nullptr)) ? 1 : 0;
}