#ifndef DDGM_ENTITY_HPP
#define DDGM_ENTITY_HPP

#include <string>
#include <sys/types.h>

namespace ddgm {

class Entity {
public:
  enum class Colors { red, yellow, blue };

protected:
  std::string name;
  const uint max_hp;
  uint hp, atk, matk, def, mdef;
  uint xp;
  Colors color;

public:
  Entity(std::string name, uint hp, uint atk, uint matk, uint def, uint mdef,
         Colors color, uint xp);
  void attack(Entity &obj);

  std::string getName() const;
  uint getHp() const;
  uint getMaxHp() const;
  uint getAtk() const;
  uint getMatk() const;
  uint getDef() const;
  uint getMdef() const;
  Colors getColor() const;
  uint getXp() const;

  void getHit(uint dmg);
  void getMagicHit(uint mdmg);
};

class Magic : public Entity {
public:
  using Entity::Entity;
  void attack(Entity &obj);
};
} // namespace ddgm

#endif