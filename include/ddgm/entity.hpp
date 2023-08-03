#ifndef DDGM_ENTITY_HPP
#define DDGM_ENTITY_HPP

#include <string>
#include <sys/types.h>

namespace ddgm {

class Entity {
  // Protected because these members need
  // to be inherited by child classes
protected:
  // Defining the various attributes
  // of a generic entity
  std::string name;
  const uint max_hp;
  uint hp, atk, matk, def, mdef;
  uint xp;
  // Actually we don't know why but
  // without this the code breaks
  // Maybe because it wanted an abstract class
  virtual void magicFunc() {}

public:
  // Declaring Entity constructor
  Entity(std::string name, uint hp, uint atk, uint matk, uint def, uint mdef,
         uint xp);
  // Declaring all the getter functions for
  // the private/protected members
  std::string getName() const;
  uint getHp() const;
  uint getMaxHp() const;
  uint getAtk() const;
  uint getMatk() const;
  uint getDef() const;
  uint getMdef() const;
  uint getXp() const;

  // Declaring the function to allow an entity to take damage
  void getHit(uint dmg);
};
} // namespace ddgm

#endif