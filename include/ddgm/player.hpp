#ifndef DDGM_PLAYER_HPP
#define DDGM_PLAYER_HPP

#include "ddgm/enemies.hpp"
#include "ddgm/entity.hpp"
#include "ddgm/items.hpp"
#include "ddgm/json.hpp"
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
protected:
  // Declaring a vocation variable of type Vocations
  // that will store the player's vocation
  Vocations vocation;

  // Declaring and initializing the player's level
  uint lvl = 1;

  // Declaring a vector of type Item
  // to represent the player's inventory
  std::vector<Item> inventory;

  // Declaring a vector of type Skill
  // that contains all the usable skill
  // by the player/pawn
  std::vector<Skill> player_skills;

  // Creating variables to count how many levels
  // the player has done for each vocation
  uint fighter_levels = 0, warrior_levels = 0, paladin_levels = 0,
       strider_levels = 0, ranger_levels = 0, assassin_levels = 0,
       mage_levels = 0, sorcerer_levels = 0, magickarcher_levels = 0;

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

  // Getter function to return the vocation as an enum
  Vocations getVocation() const;

  // Getter function for the vocation
  std::string returnVocation() const;

  // Function to change vocations
  // under specific criteria
  void changeVocation(Vocations vocation);

  // Declaring function that respectively allow
  // the player to add an item to his inventory
  // or to use one
  void addItem(Item item);
  void useItem(uint pos, Entity *obj = nullptr);
  void useItem(std::string item_name, Entity *obj = nullptr);

  // do not remove this unless you want the code to stop working
  // void attack(Entity &obj);
  uint attack(Enemy &obj, Skill *skill);

  // Getter functions for the level counters
  uint getFighterLvls() const, getStriderLvls() const, getMageLvls() const,
      getWarriorLvls() const, getRangerLvls() const, getSorcererLvls() const,
      getPaladinLvls() const, getAssassinLvls() const,
      getMagickArcherLvls() const;

  // Getter function that returns the
  // player_skills vector
  std::vector<Skill> getSkills() const;

  std::vector<Skill> *getSkillsAddr();

  nlohmann::json getJson() const;

  inline std::vector<Item> getInventory() const { return this->inventory; }

  // setter functions for the name and the starting vocation
  void setName(std::string name);
  void setHp(uint hp);
  void setAtk(uint atk);
  void setMatk(uint matk);
  void setDef(uint def);
  void setMdef(uint mdef);
  void setVocation(Vocations vocation);
  void setXp(uint xp);
  void setStartingVocation(uint vocation);
  void setInventory(std::vector<Item> items);
  void setSkills(std::vector<Skill> player_abilities);

  void setFighterLvls(uint fighter_levels);
  void setStriderLvls(uint strider_levels);
  void setMageLvls(uint mage_levels);
  void setWarriorLvls(uint warrior_levels);
  void setRangerLvls(uint ranger_levels);
  void setSorcererLvls(uint sorcerer_levels);
  void setAssassinLvls(uint assassin_levels);
  void setPaladinLvls(uint paladin_levels);
  void setMagickArcherLvls(uint magickarcher_levels);

};

// Operator overloading that allows to print
// the player's stats
std::ostream &operator<<(std::ostream &os, const Player *player);

} // namespace ddgm

#endif