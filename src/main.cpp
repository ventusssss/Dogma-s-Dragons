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
#include <unistd.h>

using namespace std;
using namespace ddgm;

int main() {
  Enemy *g = new Golbin();
  Player *p = new Player("Guts", 2000, 15, 10, 500, 25, Vocations::Warrior, 0);
  std::cout << g->getHp() << "\n";
  p->attack(*g, Skill::SkillType::fire);
  std::cout << g->getHp() << "\n";
  return int(bool(nullptr)) ? 1 : 0;
}