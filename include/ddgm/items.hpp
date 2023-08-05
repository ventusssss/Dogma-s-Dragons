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
  std::string description;
  uint value;
  // do not delete PLS, with this function the code works
  virtual void magicFunc() {}

public:
  // Declaring the constructor for the item class
  Item(std::string name, uint value, std::string description);

  // Getter functions for private attributes
  std::string getName() const;
  uint getValue() const;
  std::string getDescription() const;
};

// Creating class HealingItem that contains all
// the items that affect the player's HP
class HealingItem : public Item {
public:
  // Declaring its constructor
  HealingItem(std::string name, uint heal, std::string description);
};

// Creating class AttackItem that contains all
// the items that deal physical damage
class AttackItem : public Item {
public:
  // Declaring its constructor
  AttackItem(std::string name, uint attackPower, std::string description);
};

// Creating class MagicItem that contains all
// the items that deal magic damage
class MagicItem : public Item {
public:
  MagicItem(std::string name, uint magicDamage, std::string description);
};

// Creating a BufferItem class that contains all
// the items that can boost the player's ATKs or DEFs
class BufferItem : public Item {
public:
  BufferItem(std::string name, std::string description, uint buffx = 2);
};

// Declaring and initializing a vector of all
// the healing items
const std::vector<Item> availableHealingItems = {
    HealingItem("Gransys Herb", 30,
                "A herb common across the peninsula."
                "\n- Restores 30 HP.\n"),
    HealingItem(
        "Destiny Grass", 100,
        "A herb that is the subject of many rumors.\nIt is said that it "
        "can change the fate of those who take it.\n- Restores 100 HP.\n"),
    HealingItem(
        "Greenwarish", 120,
        "A common herb used in preparing tisanes.\n- Restores 120 HP.\n"),
    HealingItem("Harspud Milk", 150,
                "The milky water that remains from washing a hardy "
                "harspud.\n-Restores 150 HP.\n"),
    HealingItem("Harspud Juice", 350,
                "A tonic liquid squeezed from harspuds.\n- Restores 350 HP.\n"),
    HealingItem(
        "Potent Greenwarish", 350,
        "A precious herb used in preparing tisanes.\n- Restores 350 HP.\n"),
    HealingItem("Panacea", 430,
                "A legendary cure-all employed since ancient times.\nIt is "
                "told that common humans used this potion to heal the greatest "
                "wounds.\n- Restores 430 HP.\n"),
    HealingItem(
        "Balmy Incense", 500,
        "An aromatic stick with a soothing scent. It fills the whole party "
        "with great energy\n- Restores 500 HP to both party members.\n"),
    HealingItem("Matured Greenwarish", 500,
                "The ripening process has only enhanced its healing powers.\n- "
                "Restores 500 HP.\n"),
    HealingItem(
        "Kingwarish", 0,
        "A divine herb said to have reinvigorated a King, and given "
        "him the strength to defeat the Dragon.\n- Restores FULL HP.\n"),
    HealingItem("Griffin Dawn", 0,
                "The tail of a Griffin. Those magic creatures have so high "
                "magic power that allows them to communicate through astral "
                "planes with other creatures.\nOnly a piece of their tail can "
                "bring back to life a Pawn.\n- Brings back to life the Pawn "
                "with HALF HP.\n")};

// Declaring and initializing a vector of all
// the attack items
const std::vector<Item> availableAttackItems = {
    AttackItem(
        "Throwblast", 1000,
        "A small explosive of flammable powder packed into a flask.\n"
        "Handle with extreme care.\n- Deals 1000 HP of physical damage to "
        "enemy.\n"),
    AttackItem("Purse of Charity", 350,
               "A coin purse said to help relieve one of material desires.\nIt "
               "allows money to be used as a throwing weapon.\n- Deals 350 HP "
               "of physical damage to the enemy.\n")};

// Declaring and initializing a vector of all
// the magic items
const std::vector<Item> availableMagicItems = {
    MagicItem("Shattered-Earth Tome", 400,
              "A treatise on magick from an author long forgotten.\nInfused "
              "with the power to pull forth spires of rock.\n- Deals 400 HP of "
              "magic damage to the enemy.\n"),
    MagicItem("Surging-Light Tome", 400,
              "A treatise on magick from an author long forgotten. Infused "
              "with power of spreading light.\n- Deals 400 HP of magic damage "
              "to the enemy.\n"),
    MagicItem(
        "Magic Throwblast", 1000,
        "A small clay urn filled with magic power.\nExplodes, inflicting "
        "magic damage.\n- Deals 1000 HP of magic damage to the enemy.\n")};

// Declaring and initializing a vector of all
// the buffer items
const std::vector<Item> availableBufferItems = {
    BufferItem("Conqueror's Periapt",
               "A charm said to contain the vigor of a mighty warlord.\nAfter "
               "use, amplifies Strength for a period of time.\n- Doubles the "
               "player's ATK value (can be stacked up to 4 times).\n",
               2),
    BufferItem("Angel's Periapt",
               "A charm some avow carries divine protection.\nIts use "
               "amplifies Defenses for a period of time.\n- Doubles the "
               "player's DEF value (can be stacked up to 4 times).\n",
               2),
    BufferItem("Demon's Periapt",
               "A charm many believe houses the wrath of a demon.\nIts use "
               "amplifies Magick for a period of time.\n- Doubles the player's "
               "MATK value (can be stacked up to 4 times).\n",
               2),
    BufferItem("Mage's Periapt",
               "A charm ensorceled by a mighty conjurer.\nIts use amplifies "
               "Magick Defenses for a period of time.\n- Doubles the player's "
               "MDEF value (can be stacked up to 4 times).\n",
               2)};

} // namespace ddgm

#endif