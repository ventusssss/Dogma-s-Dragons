#ifndef DDGM_PLAYER_HPP
#define DDGM_PLAYER_HPP

#include "ddgm/enemies.hpp"
#include "ddgm/entity.hpp"
#include "ddgm/items.hpp"
#include "ddgm/skills.hpp"
#include <ostream>
#include <vector>

namespace ddgm {

// Enumeration of all the in-game existing
// vocations selectable by the player
enum class Vocations {
  Fighter,
  Strider,
  Mage,
  Warrior,
  Ranger,
  Sorcerer,
  Assassin,
  MagickArcher,
  Paladin
};

class Player : public Entity {
private:
  // Declaring a vocation variable of type Vocations
  // that will store the player's vocation
  Vocations vocation;

  // Declaring and initializing the player's level
  uint lvl = 1;

  // Declaring a vector of type Item
  // to represent the player's inventory
  std::vector<Item *> inventory;

public:
  // Declaring player's constructor
  Player(std::string name, uint hp, uint atk, uint matk, uint def, uint mdef,
         Vocations vocation, uint xp = 0);

  // Defining a function to add xp to the player
  // after a battle
  void addXp(const uint xp);

  // Defining a function to update all stats of the player
  // after a battle, or at the start of the game
  void updateStats();

  // Getter function for the level
  uint getLvl() const;

  // Getter function for the vocation
  std::string returnVocation() const;

  // Function to change vocations
  // under specific criteria
  void changeVocation(Vocations vocation);

  // Declaring function that respectively allow
  // the player to add an item to his inventory
  // or to use one
  void addItem(Item *item);
  void useItem(uint pos, Entity *obj = nullptr);

  // do not remove this unless you want the code to stop working
  // void attack(Entity &obj);
  void attack(Enemy &obj, Skill::SkillType skill);
};

// Operator overloading that allows to print
// the player's stats
std::ostream &operator<<(std::ostream &os, const Player *player);

} // namespace ddgm

#endif