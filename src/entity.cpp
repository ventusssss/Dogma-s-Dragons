#include "ddgm/entity.hpp"
//#include "ddgm/player.hpp"
//#include "ddgm/utilities.hpp"
//#include <iostream>
#include <sys/types.h>

// ALL THE MEANINGS OF THE FUNCTIONS
// ARE EXPLAINED IN THE HPP FILE

namespace ddgm {

// Initializing entity's member attributes
Entity::Entity(std::string name, uint hp, uint atk, uint matk, uint def,
               uint mdef, uint xp)
    : name(name), hp(hp), atk(atk), matk(matk), def(def), mdef(mdef),
      max_hp(hp), xp(xp) {}

void Entity::getHit(uint dmg) {
  this->hp = (this->hp >= dmg ? this->getHp() - dmg : 0);
}

std::string Entity::getName() const { return this->name; }

uint Entity::getHp() const { return this->hp; }

void Entity::setMaxHp(uint max_hp) { this->max_hp = max_hp; }

uint Entity::getMaxHp() const { return this->max_hp; }

uint Entity::getAtk() const { return this->atk; }

uint Entity::getMatk() const { return this->matk; }

uint Entity::getDef() const { return this->def; }

uint Entity::getMdef() const { return this->mdef; }

uint Entity::getXp() const { return this->xp; }

void Entity::healEntity(uint heal) {
  this->hp = (this->hp + heal > this->max_hp ? this->max_hp : this->hp + heal);
}

void Entity::increase_atk(uint increase) {
  this->atk *= increase;
}

void Entity::increase_def(uint increase) {
  this->def *= increase;
}

void Entity::increase_matk(uint increase) {
  this->matk *= increase;
}

void Entity::increase_mdef(uint increase) {
  this->mdef *= increase;
}

} // namespace ddgm