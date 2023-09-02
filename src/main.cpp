#include "ddgm/enemies.hpp"
#include "ddgm/entity.hpp"
#include "ddgm/game.hpp"
#include "ddgm/items.hpp"
#include "ddgm/pawn.hpp"
#include "ddgm/player.hpp"
#include "ddgm/skills.hpp"
#include "ddgm/utilities.hpp"
#include <cstdlib>
#include <iostream>
#include <random>
#include <unistd.h>

using namespace std;
using namespace ddgm;

int main() {
  srand(time(0));
  Enemy *sk = new Skeleton();
  Enemy *g = new Golbin();
  Pawn *pawn = new Pawn("Brok", 110, 3, 4, 5, 6, Vocations::Warrior, 3690);
  pawn->updateStats();
  std::cout << pawn;

  skill_choosing(pawn);

  std::cout << g->getHp() << "\n";
  pawn->pawn_attack(*g);
  std::cout << g->getHp() << "\n";

  return int(bool(nullptr)) ? 1 : 0;
}