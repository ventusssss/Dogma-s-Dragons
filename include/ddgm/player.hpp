#ifndef DDGM_PLAYER_HPP
#define DDGM_PLAYER_HPP

#include "ddgm/enemies.hpp"
#include "ddgm/entity.hpp"
#include "ddgm/items.hpp"
#include "ddgm/skills.hpp"
#include <ostream>
#include <vector>

namespace ddgm {

// crea un tipo che rappresenta le vocations
enum class Vocations {
  Fighter,      // def (mid-high 10%)
  Strider,      // def (non troppo 2%) e atk (non troppo)
  Mage,         // mdef (massive)
  Warrior,      // hp (massive)
  Ranger,       // mid (5%) def, mid atk
  Sorcerer,     // matk (massive 15%)
  Assassin,     // atk (massive) def (mid)
  MagickArcher, // def (mid) mdef (massive)
  Paladin       // hp (mid-high) matk (mid-high)
};

class Player : public Entity {
private:
  Vocations vocation;
  uint lvl = 1;
  std::vector<Item *> inventory;

public:
  Player(std::string name, uint hp, uint atk, uint matk, uint def, uint mdef,
         Vocations vocation, uint xp = 0);
  void addXp(const uint xp);
  void updateStats();
  uint getLvl() const;
  std::string returnVocation() const;
  void changeVocation(Vocations vocation);
  void addItem(Item *item);
  void useItem(uint pos, Entity *obj = nullptr);

  // do not remove this unless you want the code to stop working
  // void attack(Entity &obj);
  void attack(Enemy &obj, Skill::SkillType skill);
};

std::ostream &operator<<(std::ostream &os, const Player *player);

} // namespace ddgm

#endif