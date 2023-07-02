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
               uint mdef, uint xp)
    : name(name), hp(hp), atk(atk), matk(matk), def(def), mdef(mdef),
      max_hp(hp), xp(xp) {}

// Physical section
void Entity::attack(Entity &obj) {
  // r y b r
  std::random_device rd;
  std::mt19937 rng(rd());
  std::uniform_int_distribution<uint> uni(this->atk - percu(this->atk, 10),
                                          this->atk + percu(this->atk, 10));
  uint dmg = uni(rng),
       dmg_eff = (dmg > obj.def ? dmg - obj.def : obj.def - dmg);
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

uint Entity::getXp() const { return this->xp; }

void Entity::getHit(uint dmg) {
  this->hp = (this->hp > dmg ? this->getHp() - dmg : 0);
}

// Magic section

} // namespace ddgm