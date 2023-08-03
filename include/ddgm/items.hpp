#ifndef DDGM_ITEMS_HPP
#define DDGM_ITEMS_HPP

#include "ddgm/entity.hpp"
#include <ostream>
#include <vector>

namespace ddgm {

class Item {
protected:
  // Declaring the various attributes
  // for each item
  std::string name;
  uint value;
  // do not delete PLS, with this function the code works
  virtual void magicFunc() {}

public:
  // Declaring the constructor for the item class
  Item(std::string name, uint value);

  // Getter functions for private attributes
  std::string getName() const;
  uint getValue() const;
};

// Creating class HealingItem that contains all
// the items that affect the player's HP
class HealingItem : public Item {
public:
  // Declaring its constructor
  HealingItem(std::string name, uint heal);
};

// Creating class AttackItem that contains all
// the items that deal physical damage
class AttackItem : public Item {
public:
  // Declaring its constructor
  AttackItem(std::string name, uint attackPower);
};

// Creating class MagicItem that contains all
// the items that deal magic damage
class MagicItem : public Item {
public:
  MagicItem(std::string name, uint magicDamage);
};

// Creating a BufferItem class that contains all
// the items that can boost the player's ATKs or DEFs
class BufferItem : public Item {
public:
  BufferItem(std::string name, uint buffx = 2);
};

// Declaring and initializing a vector of all
// the healing items
const std::vector<Item> availableHealingItems = {
    HealingItem("Gransys Herb", 30),
    HealingItem("Destiny Grass", 100),
    HealingItem("Greenwarish", 120),
    HealingItem("Harspud Milk", 150),
    HealingItem("Harspud Juice", 350),
    HealingItem("Potent Greenwarish", 350),
    HealingItem("Panacea", 430),
    HealingItem("Balmy Incense", 500),
    HealingItem("Matured Greenwarish", 500),
    HealingItem("Kingwarish", 0),
    HealingItem("Phoenix Down", 0)};

// Declaring and initializing a vector of all
// the attack items
const std::vector<Item> availableAttackItems = {
    AttackItem("Throwblast", 1000), AttackItem("Purse of Charity", 150)};

// Declaring and initializing a vector of all
// the magic items
const std::vector<Item> availableMagicItems = {
    MagicItem("Shattered-Earth Tome", 300),
    MagicItem("Surging-Light Tome", 300), MagicItem("Magic Throwblast", 1000)};

// Declaring and initializing a vector of all
// the buffer items
const std::vector<Item> availableBufferItems = {
    BufferItem("Conqueror's Periapt"), BufferItem("Angel's Periapt"),
    BufferItem("Demon's Periapt"), BufferItem("Mage's Periapt")};

} // namespace ddgm

#endif