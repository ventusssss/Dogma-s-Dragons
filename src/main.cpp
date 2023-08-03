#include "ddgm/enemies.hpp"
#include "ddgm/entity.hpp"
#include "ddgm/items.hpp"
#include "ddgm/pawn.hpp"
#include "ddgm/player.hpp"
#include "ddgm/skills.hpp"
#include "ddgm/utilities.hpp"
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <random>
#include <unistd.h>

using namespace std;
using namespace ddgm;

int main() {
  /*
  Enemy *g = new Golbin();
  Player *p = new Player("Guts", 2000, 15, 10, 500, 25, Vocations::Warrior, 0);
  std::cout << g->getHp() << "\n";
  p->attack(*g, Skill::SkillType::fire);
  std::cout << g->getHp() << "\n";
  Enemy *b = new Bandit();
  pawn->tellVulnerabilities(true, *b);
  Enemy *s = new Skeleton();
  pawn->tellResistances(true, *s);
  */
  std::cout << casuality(50) << "\n";
  Pawn *pawn = new Pawn("Brok", 100, 3, 4, 5, 6, Vocations::Warrior, 0);
  pawn->travelTalk();

  return int(bool(nullptr)) ? 1 : 0;
}