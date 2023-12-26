#include "ddgm/player.hpp"
#include "ddgm/enemies.hpp"
#include "ddgm/entity.hpp"
#include "ddgm/items.hpp"
#include "ddgm/skills.hpp"
#include "ddgm/utilities.hpp"
// #include <chrono>
#include <cmath>
// #include <cstddef>
#include <iostream>
#include <math.h>
// #include <random>
#include <string>
#include <sys/types.h>

namespace ddgm {
/*
  Calling and initializing Player's constructor
*/

Player::Player(std::string name, uint hp, uint atk, uint matk, uint def,
               uint mdef, Vocations vocation, uint xp)
    : Entity(name, hp, atk, matk, def, mdef, xp), vocation(vocation) {
  // Updating the stats everytime the constructor is called
  this->updateStats();
}

// Defining the method to add xp to the Player
void Player::addXp(const uint xp) { this->xp += xp; }

// Defining the method to update the stats at the end of a fight
void Player::updateStats() {
  this->hp = max_hp;
  uint tmp_lvl = this->lvl;

  // Creating an xp curve and a levelling system
  uint delta = std::pow(123, 2) - (4 * 123 * (-this->xp));
  this->lvl = (123 + (std::sqrt(delta))) / 246;
  this->lvl = (!this->lvl ? 1 : this->lvl);

  // Checking how many levels the player gained after acquiring xp
  // And boosting specific stats for whatever vocation the player is.
  uint diff = this->lvl - tmp_lvl;
  if (diff)
    std::cout << "You reached level " << this->lvl << "\n";

  for (uint i = 0; i < diff; i++) {
    switch (this->vocation) {
    case Vocations::Fighter:
      this->def += percu(this->def, 10);
      this->hp += percu(this->hp, 3);
      this->atk += percu(this->atk, 3);
      this->fighter_levels++;
      break;
    case Vocations::Strider:
      this->def += percu(this->def, 4);
      this->atk += percu(this->atk, 4);
      this->hp += percu(this->hp, 2);
      this->strider_levels++;
      break;
    case Vocations::Mage:
      this->mdef += percu(this->mdef, 15);
      this->hp += percu(this->hp, 2);
      this->matk += percu(this->matk, 4);
      this->mage_levels++;
      break;
    case Vocations::Warrior:
      this->hp += percu(this->hp, 15);
      this->atk += percu(this->atk, 5);
      this->def += percu(this->def, 3);
      this->warrior_levels++;
      break;
    case Vocations::Ranger:
      this->def += percu(this->def, 7);
      this->atk += percu(this->atk, 7);
      this->hp += percu(this->hp, 3);
      this->ranger_levels++;
      break;
    case Vocations::Sorcerer:
      this->matk += percu(this->matk, 15);
      this->mdef += percu(this->mdef, 4);
      this->hp += percu(this->hp, 3);
      this->sorcerer_levels++;
      break;
    case Vocations::Assassin:
      this->atk += percu(this->atk, 15);
      this->def += percu(this->def, 7);
      this->hp += percu(this->hp, 5);
      this->assassin_levels++;
      break;
    case Vocations::MagickArcher:
      this->def += percu(this->def, 5);
      this->mdef += percu(this->mdef, 15);
      this->matk += percu(this->matk, 10);
      this->hp += percu(this->hp, 5);
      this->magickarcher_levels++;
      break;
    case Vocations::Paladin:
      this->hp += percu(this->hp, 10);
      this->matk += percu(this->matk, 10);
      this->def += percu(this->def, 7);
      this->mdef += percu(this->mdef, 5);
      this->atk += percu(this->atk, 3);
      this->paladin_levels++;
      break;
    }
  }
  if (this->lvl >= 5 && this->lvl < 10) {
    if (!search_enemy(selectable_enemies,
                      Enemy("Cyclope", 12000, 400, 0, 80, 60, 4000,
                            {Skill::SkillType::thunder},
                            {Skill::SkillType::fire, Skill::SkillType::ice}, 80,
                            40))) {
      selectable_enemies.push_back(Enemy(
          "Cyclope", 12000, 400, 0, 80, 60, 4000, {Skill::SkillType::thunder},
          {Skill::SkillType::fire, Skill::SkillType::ice}, 80, 40));
    }
  } else if (this->lvl >= 10 && this->lvl < 15) {
    if (!search_enemy(selectable_enemies,
                      Enemy("Chimera", 15000, 900, 150, 250, 150, 7700,
                            {Skill::SkillType::none},
                            {Skill::SkillType::fire, Skill::SkillType::ice,
                             Skill::SkillType::thunder, Skill::SkillType::holy,
                             Skill::SkillType::dark},
                            0, 15)))
      selectable_enemies.push_back(Enemy(
          "Chimera", 15000, 900, 150, 250, 150, 7700, {Skill::SkillType::none},
          {Skill::SkillType::fire, Skill::SkillType::ice,
           Skill::SkillType::thunder, Skill::SkillType::holy,
           Skill::SkillType::dark},
          0, 15));
  } else if (this->lvl >= 15 && this->lvl < 40) {
    if (!search_enemy(selectable_enemies,
                      Enemy("Ogre", 15000, 775, 0, 210, 15, 500,
                            {Skill::SkillType::none}, {Skill::SkillType::dark},
                            0, 60)) &&
        (!search_enemy(selectable_enemies,
                       Magic("Golem", 20000, 735, 473, 0, 0, 8600,
                             {Skill::SkillType::none}, {Skill::SkillType::none},
                             0, 0)))) {
      selectable_enemies.push_back(Enemy("Ogre", 15000, 775, 0, 210, 15, 500,
                                         {Skill::SkillType::none},
                                         {Skill::SkillType::dark}, 0, 60));
      selectable_enemies.push_back(Magic("Golem", 20000, 735, 473, 0, 0, 8600,
                                         {Skill::SkillType::none},
                                         {Skill::SkillType::none}, 0, 0));
    }
  } else if (this->lvl >= 40 && this->lvl < 50) {
    if (!search_enemy(selectable_enemies,
                      Enemy("Hydra", 75000, 1230, 675, 145, 145, 16000,
                            {Skill::SkillType::slash},
                            {Skill::SkillType::dash, Skill::SkillType::fire,
                             Skill::SkillType::ice, Skill::SkillType::thunder,
                             Skill::SkillType::holy, Skill::SkillType::dark},
                            10, 58)) &&
        !search_enemy(selectable_enemies,
                      Enemy("Wyrm", 60000, 800, 1300, 270, 800, 24000,
                            {Skill::SkillType::fire}, {Skill::SkillType::ice},
                            50, 75)) &&
        !search_enemy(selectable_enemies,
                      Magic("Frost Wyrm", 90000, 1000, 400, 320, 524, 64000,
                            {Skill::SkillType::fire},
                            {Skill::SkillType::ice, Skill::SkillType::thunder,
                             Skill::SkillType::holy, Skill::SkillType::dark},
                            20, 70)) &&
        !search_enemy(selectable_enemies,
                      Enemy("Drake", 80000, 450, 275, 300, 100, 25000,
                            {Skill::SkillType::ice}, {Skill::SkillType::fire},
                            50, 80))) {
      selectable_enemies.push_back(Enemy(
          "Hydra", 75000, 1230, 675, 145, 145, 16000, {Skill::SkillType::slash},
          {Skill::SkillType::dash, Skill::SkillType::fire,
           Skill::SkillType::ice, Skill::SkillType::thunder,
           Skill::SkillType::holy, Skill::SkillType::dark},
          10, 58));
      selectable_enemies.push_back(Enemy("Wyrm", 60000, 800, 1300, 270, 800,
                                         24000, {Skill::SkillType::fire},
                                         {Skill::SkillType::ice}, 50, 75));

      selectable_enemies.push_back(
          Magic("Frost Wyrm", 90000, 1000, 400, 320, 524, 64000,
                {Skill::SkillType::fire},
                {Skill::SkillType::ice, Skill::SkillType::thunder,
                 Skill::SkillType::holy, Skill::SkillType::dark},
                20, 70));
      selectable_enemies.push_back(Enemy("Drake", 80000, 450, 275, 300, 100,
                                         25000, {Skill::SkillType::ice},
                                         {Skill::SkillType::fire}, 50, 80));
    }
  }
}

uint Player::getLvl() const { return this->lvl; }

// Defining the getter method to return the vocation as it is
// declared (enum)
Vocations Player::getVocation() const { return this->vocation; }

// Defining the getter method for the vocation and returning a string
// (it's simpler in the code)
std::string Player::returnVocation() const {
  switch (this->vocation) {
  case Vocations::Fighter:
    return "Fighter";
  case Vocations::Strider:
    return "Strider";
  case Vocations::Mage:
    return "Mage";
  case Vocations::Warrior:
    return "Warrior";
  case Vocations::Ranger:
    return "Ranger";
  case Vocations::Sorcerer:
    return "Sorcerer";
  case Vocations::Assassin:
    return "Assassin";
  case Vocations::MagickArcher:
    return "Magick-Archer";
  case Vocations::Paladin:
    return "Paladin";
  default:
    return "Unknown (unexpected behavior)";
  }
}

std::ostream &operator<<(std::ostream &os, const Player *player) {
  os << "Name: " << player->getName() << "\n";
  os << "HP: " << player->getHp() << "\n";
  os << "ATK: " << player->getAtk() << "\n";
  os << "DEF: " << player->getDef() << "\n";
  os << "MATK: " << player->getMatk() << "\n";
  os << "MDEF: " << player->getMdef() << "\n";
  os << "Vocation: " << player->returnVocation() << "\n";
  os << "Level: " << player->getLvl() << "\n";
  /*
  here we make a subtraction between player's xp required
  for next level (that's why player.getLvl() +1 ) and player's
  current xp
  */
  os << "XP required for next level: "
     << (123 * std::pow((player->getLvl() + 1), 2) -
         123 * (player->getLvl() + 1)) -
            player->getXp()
     << "\n";
  os << "Total XP: " << player->getXp() << "\n";
  return os;
}

void Player::changeVocation(Vocations vocation) {
  if (this->lvl < 5) {
    switch (vocation) {
    case Vocations::Fighter:
    case Vocations::Strider:
    case Vocations::Mage:
      this->vocation = vocation;
      break;
    case Vocations::Warrior:
    case Vocations::Ranger:
    case Vocations::Sorcerer:
      std::cout << "You cannote change vocation\nMinimum "
                   "level required: 5\n";
      break;
    case Vocations::Assassin:
    case Vocations::MagickArcher:
    case Vocations::Paladin:
      std::cout << "You cannote change vocation\nMinimum "
                   "level required: 10\n";
      break;
    }
  } else if (this->lvl < 10) {
    switch (vocation) {
    case Vocations::Fighter:
    case Vocations::Strider:
    case Vocations::Mage:
    case Vocations::Warrior:
    case Vocations::Ranger:
    case Vocations::Sorcerer:
      this->vocation = vocation;
      break;
    case Vocations::Assassin:
    case Vocations::MagickArcher:
    case Vocations::Paladin:
      std::cout << "You cannote change vocation\nMinimum "
                   "level required: 10\n";
      break;
    }
  } else {
    this->vocation = vocation;
  }
}

void Player::addItem(Item item) { this->inventory.push_back(item); }

// Defining the method for using the items, that will affect
// the player, or the object which the item is directed to
void Player::useItem(uint pos, Entity *obj) {
  std::cout << "You used " << this->inventory[pos].getName() << " on " << obj->getName() << " ";
  if ((dynamic_cast<HealingItem *>(&this->inventory[pos])) && (this->inventory[pos].getName() != "Griffin Dawn")) {
    obj->healEntity(this->inventory[pos].getValue());
    std::cout << "and healed it of " << this->inventory[pos].getValue() << "\n";
  } else if ((dynamic_cast<AttackItem *>(&this->inventory[pos])) ||
             (dynamic_cast<MagicItem *>(&this->inventory[pos]))) {
    obj->getHit(this->inventory[pos].getValue());
    std::cout << "and dealt " << this->inventory[pos].getValue() << " damage to it!\n";
  } else if (dynamic_cast<BufferItem *>(&this->inventory[pos])) {
    if (this->inventory[pos].getName() == "Conqueror's Periapt") {
      obj->increase_atk(this->inventory[pos].getValue());
      std::cout << "and doubled its attack!\n";
    }
    else if (this->inventory[pos].getName() == "Angel's Periapt") {
      obj->increase_def(this->inventory[pos].getValue());
      std::cout << "and doubled its defense!\n";
    }
    else if (this->inventory[pos].getName() == "Demon's Periapt") {
      obj->increase_matk(this->inventory[pos].getValue());
      std::cout << "and doubled its magick attack!\n";
    }
    else if (this->inventory[pos].getName() == "Mage's Periapt") {
      obj->increase_mdef(this->inventory[pos].getValue());
      std::cout << "and doubled its magick defense!\n";
    }
  }
  this->inventory.erase(this->inventory.begin() + pos);
}

uint Player::attack(Enemy &obj, Skill *skill) {
  uint dmg = 0, dmg_eff = 0;

  if (dynamic_cast<Magic *>(&obj))
    dmg = generateRandom(this->matk - percu(this->matk, 10),
                         this->matk + percu(this->matk, 10));
  else
    dmg = generateRandom(this->atk - percu(this->atk, 10),
                         this->atk + percu(this->atk, 10));

  if (!skill) {
    dmg_eff = dmg;
  } else {
    dmg *= skill->getMultiplier();
    if (obj.isEffective(skill->returnSkillType()))
      dmg += percu(dmg, obj.getVulperc());
    else if (obj.isResistant(skill->returnSkillType()))
      dmg -= percu(dmg, obj.getResperc());

    if (dynamic_cast<Magic *>(&obj)) {
      if (dmg >= obj.getMdef()) {
        dmg_eff = dmg - obj.getMdef();
      } else {
        dmg_eff =
            ceil(log((3 * pow(obj.getMdef(), 2)) - (4 * obj.getMdef()) + dmg));
      }
    } else {
      if (dmg >= obj.getDef()) {
        dmg_eff = dmg - obj.getDef();
      } else {
        dmg_eff =
            ceil(log((3 * pow(obj.getDef(), 2)) - (4 * obj.getMdef()) + dmg));
      }
    }
  }
  obj.getHit(dmg_eff);
  return dmg_eff;
}

uint Player::getFighterLvls() const { return this->fighter_levels; }
uint Player::getStriderLvls() const { return this->strider_levels; }
uint Player::getMageLvls() const { return this->mage_levels; }
uint Player::getWarriorLvls() const { return this->warrior_levels; }
uint Player::getRangerLvls() const { return this->ranger_levels; }
uint Player::getSorcererLvls() const { return this->sorcerer_levels; }
uint Player::getPaladinLvls() const { return this->paladin_levels; }
uint Player::getAssassinLvls() const { return this->assassin_levels; }
uint Player::getMagickArcherLvls() const { return this->magickarcher_levels; }

std::vector<Skill> Player::getSkills() const { return this->player_skills; }
std::vector<Skill> *Player::getSkillsAddr() { return &this->player_skills; }

nlohmann::json Player::getJson() const {
  nlohmann::json items;
  nlohmann::json skills;
  for (Skill &skill : this->getSkills()) {
    skills.push_back(skill.getJson());
  }
  for (Item item : this->getInventory()) {
    items.push_back(item.getJson());
  }

  nlohmann::json data = {{"name", this->name},
                         {"hp", this->hp},
                         {"atk", this->atk},
                         {"matk", this->matk},
                         {"def", this->def},
                         {"mdef", this->mdef},
                         {"xp", this->xp},
                         {"lvl", this->lvl},
                         {"vocation", this->getVocation()},
                         {"fighter_levels", this->fighter_levels},
                         {"warrior_levels", this->warrior_levels},
                         {"paladin_levels", this->paladin_levels},
                         {"strider_levels", this->strider_levels},
                         {"ranger_levels", this->ranger_levels},
                         {"assassin_levels", this->assassin_levels},
                         {"mage_levels", this->mage_levels},
                         {"sorcerer_levels", this->sorcerer_levels},
                         {"magickarcher_levels", this->magickarcher_levels},
                         {"skills", skills},
                         {"inventory", items}};
  return data;
}

void Player::setName(std::string name) { this->name = name; }

void Player::setStartingVocation(uint vocation) {
  switch (vocation) {
  case 1:
    this->vocation = Vocations::Fighter;
    this->hp = 430;
    this->atk = 80;
    this->def = 80;
    this->matk = 60;
    this->mdef = 60;
    break;
  case 2:
    this->vocation = Vocations::Strider;
    this->hp = 430;
    this->atk = 70;
    this->def = 70;
    this->matk = 70;
    this->mdef = 70;
    break;
  case 3:
    this->vocation = Vocations::Mage;
    this->hp = 410;
    this->atk = 60;
    this->def = 60;
    this->matk = 80;
    this->mdef = 80;
    break;
  }
}

void Player::setHp(uint hp) { this->hp = hp; }
void Player::setAtk(uint atk) { this->atk = atk; }
void Player::setMatk(uint matk) { this->matk = matk; }
void Player::setDef(uint def) { this->def = def; }
void Player::setMdef(uint mdef) { this->mdef = mdef; }
void Player::setVocation(Vocations vocation) { this->vocation = vocation; }
void Player::setXp(uint xp) { this->xp = xp; }
void Player::setInventory(std::vector<Item> items) { this->inventory = items; }
void Player::setSkills(std::vector<Skill> player_abilities) {
  this->player_skills = player_abilities;
}

void Player::setFighterLvls(uint fighter_levels) {
  this->fighter_levels = fighter_levels;
}
void Player::setStriderLvls(uint strider_levels) {
  this->strider_levels = strider_levels;
}
void Player::setMageLvls(uint mage_levels) { this->mage_levels = mage_levels; }

void Player::setWarriorLvls(uint warrior_levels) {
  this->warrior_levels = warrior_levels;
}
void Player::setRangerLvls(uint ranger_levels) {
  this->ranger_levels = ranger_levels;
}
void Player::setSorcererLvls(uint sorcerer_levels) {
  this->sorcerer_levels = sorcerer_levels;
}
void Player::setAssassinLvls(uint assassin_levels) {
  this->assassin_levels = assassin_levels;
}
void Player::setPaladinLvls(uint paladin_levels) {
  this->paladin_levels = paladin_levels;
}
void Player::setMagickArcherLvls(uint magickarcher_levels) {
  this->magickarcher_levels = magickarcher_levels;
}

} // namespace ddgm
