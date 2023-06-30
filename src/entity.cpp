#include "ddgm/entity.hpp"
#include "ddgm/player.hpp"
#include "ddgm/utilities.hpp"
#include <chrono>
#include <iostream>
#include <random>
#include <sys/types.h>

namespace ddgm {

// inizializziamo i membri di entity
Entity::Entity(std::string name, uint hp, uint atk, uint matk, uint def,
               uint mdef, Colors color, uint xp)
    : name(name), hp(hp), atk(atk), matk(matk), def(def), mdef(mdef),
      max_hp(hp), color(color), xp(xp) {}

// Physical section
void Entity::attack(Entity &obj) {
  // r y b r
  std::random_device rd;
  std::mt19937 rng(rd());
  std::uniform_int_distribution<uint> uni(this->atk - percu(this->atk, 10),
                                          this->atk + percu(this->atk, 10));
  uint dmg = uni(rng),
       dmg_eff = (dmg > obj.def ? dmg - obj.def : obj.def - dmg);
  switch (obj.color) {
  case Colors::red:
    if (this->color != Colors::red) {
      dmg_eff += (this->color == Colors::blue ? percu(dmg_eff, 15)
                                              : -percu(dmg_eff, 15));
      std::cout << "critical!\n";
    }
    break;
  case Colors::yellow:
    if (this->color != Colors::yellow) {
      dmg_eff += (this->color == Colors::red ? percu(dmg_eff, 15)
                                             : -percu(dmg_eff, 15));
      std::cout << "critical!\n";
    }

    break;
  case Colors::blue:
    if (this->color != Colors::blue) {
      dmg_eff += (this->color == Colors::yellow ? percu(dmg_eff, 15)
                                                : -percu(dmg_eff, 15));
      std::cout << "critical!\n";
    }
    break;
  }
  obj.hp = (obj.hp > dmg_eff ? obj.hp - dmg_eff : 0);
}

void Entity::getMagicHit(uint mdmg) {
  this->hp = (this->hp > mdmg ? this->getHp() - mdmg : 0);
}

std::string Entity::getName() const { return this->name; }

uint Entity::getHp() const { return this->hp; }

uint Entity::getMaxHp() const { return this->max_hp; }

uint Entity::getAtk() const { return this->atk; }

uint Entity::getMatk() const { return this->matk; }

uint Entity::getDef() const { return this->def; }

uint Entity::getMdef() const { return this->mdef; }

Entity::Colors Entity::getColor() const { return this->color; }

uint Entity::getXp() const { return this->xp; }

void Entity::getHit(uint dmg) {
  this->hp = (this->hp > dmg ? this->getHp() - dmg : 0);
}

// Magic section
void Magic::attack(Entity &obj) {
  std::random_device rd;
  std::mt19937 rng(rd());
  std::uniform_int_distribution<uint> uni(this->matk - percu(this->matk, 10),
                                          this->matk + percu(this->matk, 10));
  uint dmg = uni(rng), dmg_eff = (dmg > obj.getMdef() ? dmg - obj.getMdef()
                                                      : obj.getMdef() - dmg);
  switch (obj.getColor()) {
  case Colors::red:
    if (this->color != Colors::red) {
      dmg_eff += (this->color == Colors::blue ? percu(dmg_eff, 15)
                                              : -percu(dmg_eff, 15));
      std::cout << "magick attack crit!\n";
    }
    break;
  case Colors::yellow:
    if (this->color != Colors::yellow) {
      dmg_eff += (this->color == Colors::red ? percu(dmg_eff, 15)
                                             : -percu(dmg_eff, 15));
      std::cout << "magick attack crit!\n";
    }
    break;
  case Colors::blue:
    if (this->color != Colors::blue) {
      dmg_eff += (this->color == Colors::yellow ? percu(dmg_eff, 15)
                                                : -percu(dmg_eff, 15));
      std::cout << "magick attack crit!\n";
    }
    break;
  }
  obj.getMagicHit(dmg_eff);
}

} // namespace ddgm