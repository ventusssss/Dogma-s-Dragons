#ifndef DDGM_ITEMS_HPP
#define DDGM_ITEMS_HPP

#include "ddgm/entity.hpp"
#include <ostream>
#include <vector>

namespace ddgm {

class Item {
protected:
  std::string name;
  uint value;
  // do not delete PLS, with this function the code works
  virtual void magicFunc() {}

public:
  Item(std::string name, uint value);
  std::string getName() const;
  uint getValue() const;
};

class HealingItem : public Item {
public:
  HealingItem(std::string name, uint heal);
};

class AttackItem : public Item {
public:
  AttackItem(std::string name, uint attackPower);
};

class MagicItem : public Item {
public:
  MagicItem(std::string name, uint magicDamage);
};

class BufferItem : public Item {
public:
  BufferItem(std::string name, uint buffx = 2);
};

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
    HealingItem("Kingwarish", 0)};

const std::vector<Item> availableAttackItems = {
    AttackItem("Throwblast", 1000), AttackItem("Purse of Charity", 150)};

const std::vector<Item> availableMagicItems = {
    MagicItem("Shattered-Earth Tome", 300),
    MagicItem("Surging-Light Tome", 300), MagicItem("Magic Throwblast", 1000)};

const std::vector<Item> availableBufferItems = {
    BufferItem("Conqueror's Periapt"), BufferItem("Angel's Periapt"),
    BufferItem("Demon's Periapt"), BufferItem("Mage's Periapt")};

} // namespace ddgm

#endif