#include "ddgm/player.hpp"
#include "ddgm/enemies.hpp"
#include "ddgm/items.hpp"
#include "ddgm/utilities.hpp"
#include <chrono>
#include <cmath>
#include <iostream>
#include <math.h>
#include <random>
#include <string>
#include <sys/types.h>

namespace ddgm {
// chiamiamo il constructor di player,
// inizializzando la SUA entita'
Player::Player(std::string name, uint hp, uint atk, uint matk, uint def,
               uint mdef, Vocations vocation, uint xp)
    : Entity(name, hp, atk, matk, def, mdef, xp), vocation(vocation) {
  this->updateStats();
}
void Player::addXp(const uint xp) { this->xp += xp; }
void Player::updateStats() {
  this->hp = max_hp;
  uint tmp_lvl = this->lvl;
  // xp = 123 * lvl^2 - 123 * lvl
  // lvl = (123 + sqrt(123^2-4(123)(-xp))) / 123 * 2;

  uint delta = std::pow(123, 2) - (4 * 123 * (-this->xp));
  this->lvl = (123 + (std::sqrt(delta))) / 246;
  this->lvl = (!this->lvl ? 1 : this->lvl);

  uint diff = this->lvl - tmp_lvl;
  for (uint i = 0; i < diff; i++) {
    switch (this->vocation) {
    case Vocations::Fighter:
      this->def += percu(this->def, 10);
      break;
    case Vocations::Strider:
      this->def += percu(this->def, 2);
      this->atk += percu(this->atk, 2);
      break;
    case Vocations::Mage:
      this->mdef += percu(this->mdef, 15);
      break;
    case Vocations::Warrior:
      this->hp += percu(this->hp, 15);
      break;
    case Vocations::Ranger:
      this->def += percu(this->def, 5);
      this->atk += percu(this->atk, 5);
      break;
    case Vocations::Sorcerer:
      this->matk += percu(this->matk, 15);
      break;
    case Vocations::Assassin:
      this->atk += percu(this->atk, 15);
      this->def += percu(this->def, 5);
      break;
    case Vocations::MagickArcher:
      this->def += percu(this->def, 5);
      this->mdef += percu(this->mdef, 15);
      break;
    case Vocations::Paladin:
      this->hp += percu(this->hp, 10);
      this->matk += percu(this->matk, 10);
      break;
    }
  }
}

uint Player::getLvl() const { return this->lvl; }

std::string Player::returnVocation() const {
  switch (this->vocation) {
  case Vocations::Fighter:
    return "Fighter (Red)";
  case Vocations::Strider:
    return "Strider (Yellow)";
  case Vocations::Mage:
    return "Mage (Blue)";
  case Vocations::Warrior:
    return "Warrior (Red)";
  case Vocations::Ranger:
    return "Ranger (Yellow)";
  case Vocations::Sorcerer:
    return "Sorcerer (Blue)";
  case Vocations::Assassin:
    return "Assassin (Red/Yellow)";
  case Vocations::MagickArcher:
    return "Magick-Archer (Yellow/Blue)";
  case Vocations::Paladin:
    return "Paladin (Red/Blue)";
  default:
    return "Unknown (unexpected behavior nigga)";
  }
}

std::ostream &operator<<(std::ostream &os, const Player player) {
  os << "Name: " << player.getName() << "\n";
  os << "HP: " << player.getHp() << "\n";
  os << "ATK: " << player.getAtk() << "\n";
  os << "DEF: " << player.getDef() << "\n";
  os << "MATK: " << player.getMatk() << "\n";
  os << "MDEF: " << player.getMdef() << "\n";
  os << "Vocation: " << player.returnVocation() << "\n";
  os << "Level: " << player.getLvl() << "\n";
  os << "XP required for next level: "
     << (123 * std::pow((player.getLvl() + 1), 2) -
         123 * (player.getLvl() + 1)) -
            player.getXp()
     << "\n";
  os << "Total XP: " << player.getXp() << "\n";
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
      std::cout << "You cannote change vocation\nMinimum level required: 5\n";
      break;
    case Vocations::Assassin:
    case Vocations::MagickArcher:
    case Vocations::Paladin:
      std::cout << "You cannote change vocation\nMinimum level required: 10\n";
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
      std::cout << "You cannote change vocation\nMinimum level required: 10\n";
      break;
    }
  } else {
    this->vocation = vocation;
  }
}

void Player::addItem(Item *item) { this->inventory.push_back(item); }

void Player::useItem(uint pos, Entity *obj) {
  if (dynamic_cast<HealingItem *>(this->inventory[pos])) {
    this->hp += this->inventory[pos]->getValue();
    this->hp = (this->hp > this->max_hp ? this->max_hp : this->hp);
  } else if (dynamic_cast<AttackItem *>(this->inventory[pos])) {
    obj->getHit(this->inventory[pos]->getValue());
  } else if (dynamic_cast<MagicItem *>(this->inventory[pos])) {
    obj->getMagicHit(this->inventory[pos]->getValue());
  } else if (dynamic_cast<BufferItem *>(this->inventory[pos])) {
    if (this->inventory[pos]->getName() == "Conqueror's Periapt")
      this->atk *= this->inventory[pos]->getValue();
    else if (this->inventory[pos]->getName() == "Angel's Periapt")
      this->def *= this->inventory[pos]->getValue();
    else if (this->inventory[pos]->getName() == "Demon's Periapt")
      this->matk *= this->inventory[pos]->getValue();
    else if (this->inventory[pos]->getName() == "Mage's Periapt")
      this->mdef *= this->inventory[pos]->getValue();
  }

  this->inventory.erase(this->inventory.begin() + pos);
}

void Player::attackDragon(Entity *obj) {
  if (dynamic_cast<Grigori *>(obj)) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<uint> uni(this->atk - percu(this->atk, 10),
                                            this->atk + percu(this->atk, 10));
    uint dmg = uni(rng), dmg_eff = (dmg > obj->getDef() ? dmg - obj->getDef()
                                                        : obj->getDef() - dmg);
    obj->getHit(dmg);
  }
}
} // namespace ddgm