#include "ddgm/enemies.hpp"
#include "ddgm/entity.hpp"
#include "ddgm/items.hpp"
#include "ddgm/pawn.hpp"
#include "ddgm/player.hpp"
#include "ddgm/utilities.hpp"
#include <iostream>
#include <ostream>

using namespace std;
using namespace ddgm;

int main() {
  // test commit
  Player player("Guts", 200, 500, 0, 500, 25, Vocations::Fighter,
                Player::Colors::red, 1390);
  player.updateStats();
  // player.changeVocation(Vocations::Paladin);
  cout << player;
  return 0;
}
