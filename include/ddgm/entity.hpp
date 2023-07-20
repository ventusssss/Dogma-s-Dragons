#ifndef DDGM_ENTITY_HPP
#define DDGM_ENTITY_HPP

#include <string>
#include <sys/types.h>

namespace ddgm {

class Entity {
protected:
  std::string name;
  const uint max_hp;
  uint hp, atk, matk, def, mdef;
  uint xp;
  virtual void magicFunc() {}

public:
  Entity(std::string name, uint hp, uint atk, uint matk, uint def, uint mdef,
         uint xp);

  std::string getName() const;
  uint getHp() const;
  uint getMaxHp() const;
  uint getAtk() const;
  uint getMatk() const;
  uint getDef() const;
  uint getMdef() const;
  uint getXp() const;
  void getHit(uint dmg);
};
} // namespace ddgm

#endif