#include "ddgm/enemies.hpp"
#include "ddgm/entity.hpp"
#include "ddgm/game.hpp"
#include "ddgm/items.hpp"
#include "ddgm/pawn.hpp"
#include "ddgm/player.hpp"
#include "ddgm/skills.hpp"
#include "ddgm/utilities.hpp"
#include <algorithm>
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
  std::cout << g->getHp() << "\n";
  p->attack(*g, Skill::SkillType::fire);
  std::cout << g->getHp() << "\n";
  Enemy *b = new Bandit();
  pawn->tellVulnerabilities(true, *b);
  pawn->tellResistances(true, *s);
  */
  Enemy *s = new Skeleton();
  // std::cout << casuality(50) << "\n";
  Player *p = new Player("Guts", 2000, 15, 10, 500, 25, Vocations::Warrior, 0);
  Pawn *pawn = new Pawn("Brok", 100, 3, 4, 5, 6, Vocations::Warrior, 0);
  // pawn->tellResistances(*s);
  //  pawn->travelTalk(casuality(30));
  //  pawn->itemfindTalk(casuality(10));
  //  pawn->battleTalk(casuality(99), *s);
  //  pawn->pawndeathTalk();

  // itemFind();

  // std::cout << totalDmg(30, skills[0].getMultiplier()) << "\n";

  return int(bool(nullptr)) ? 1 : 0;
}