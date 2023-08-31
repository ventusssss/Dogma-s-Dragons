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
/*
Enemy *g = new Golbin();
std::cout << g->getHp() << "\n";
p->attack(*g, Skill::SkillType::fire);
std::cout << g->getHp() << "\n";
Enemy *b = new Bandit();
pawn->tellVulnerabilities(true, *b);
pawn->tellResistances(true, *s);
*/
http: //
  Enemy *s = new Skeleton();
  Enemy *g = new Golbin();
  //  std::cout << casuality(50) << "\n";
  // Player *p = new Player("Guts", 2000, 15, 10, 500, 25, Vocations::Warrior,
  // 0);
  // p->addXp(1000);
  //    p->updateStats();
  Pawn *pawn = new Pawn("Brok", 110, 3, 4, 5, 6, Vocations::Warrior, 3690);
  pawn->updateStats();
  std::cout << pawn;
  // pawn->tellResistances(*s);
  //  pawn->travelTalk(casuality(30));
  // pawn->itemfindTalk(casuality(10));
  // pawn->battleTalk(casuality(99), *g);
  // pawn->pawndeathTalk();

  /*std::cout << pawn->getPlayerSkills().size() << "\n";
  for (uint i = 0; i < pawn->getPlayerSkills().size(); i++) {
    std::cout << pawn->getPlayerSkills()[i].getName() << "\n";
  }*/

  skill_choosing(pawn);
  /*std::cout << g->getHp() << "\n";
  pawn->pawn_attack(*g);
  // nulla
  std::cout << g->getHp() << "\n";
  */
  return int(bool(nullptr)) ? 1 : 0;
}