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
  uint max_hp, hp, atk, matk, def, mdef;
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
  void setMaxHp(uint max_hp);
  uint getMaxHp() const;
  uint getAtk() const;
  uint getMatk() const;
  uint getDef() const;
  uint getMdef() const;
  uint getXp() const;

  // function to heal an entity
  void healEntity(uint hp);

  // Declaring the function to allow an entity to take damage
  void getHit(uint dmg);

  // Declaring a function that increases the stats of an entity
  void increase_atk(uint increase);
  void increase_def(uint increase);
  void increase_matk(uint increase);
  void increase_mdef(uint increase);
};
} // namespace ddgm

#endif