#include "ddgm/enemies.hpp"
#include "ddgm/entity.hpp"
#include "ddgm/skills.hpp"
#include "ddgm/utilities.hpp"
#include <array>
#include <iostream>
#include <random>
#include <vector>

namespace ddgm {

Enemy::Enemy(std::string name, uint hp, uint atk, uint matk, uint def,
             uint mdef, uint xp, std::vector<Skill::SkillType> vulnerabilities,
             std::vector<Skill::SkillType> resistances, uint vulperc,
             uint resperc)
    : Entity(name, hp, atk, matk, def, mdef, xp),
      vulnerabilities(vulnerabilities), resistances(resistances),
      vulperc(vulperc), resperc(resperc) {}

// Defining the function to return the vector of
// vulnerabilities of the enemy
std::vector<Skill::SkillType> Enemy::getVulnerabilities() const {
  return this->vulnerabilities;
}

std::vector<Skill::SkillType> Enemy::getResistances() const {
  return this->resistances;
}

void Enemy::printVulnerabilities() const {
  std::cout << "Vulnerabilities:\n";
  for (int i = 0; i < this->vulnerabilities.size(); i++) {
    std::cout << "  - ";
    switch (vulnerabilities[i]) {
    case Skill::SkillType::slash:
      std::cout << "Slash";
      break;
    case Skill::SkillType::dash:
      std::cout << "Dash";
      break;
    case Skill::SkillType::fire:
      std::cout << "Fire";
      break;
    case Skill::SkillType::ice:
      std::cout << "Ice";
      break;
    case Skill::SkillType::thunder:
      std::cout << "Thunder";
      break;
    case Skill::SkillType::holy:
      std::cout << "Holy";
      break;
    case Skill::SkillType::dark:
      std::cout << "Dark";
      break;
    case Skill::SkillType::none:
      break;
    }
    std::cout << "\n";
  }
}

void Enemy::printResistances() const {
  std::cout << "Resistances:\n";
  for (int i = 0; i < this->resistances.size(); i++) {
    std::cout << "  - ";
    switch (resistances[i]) {
    case Skill::SkillType::slash:
      std::cout << "Slash";
      break;
    case Skill::SkillType::dash:
      std::cout << "Dash";
      break;
    case Skill::SkillType::fire:
      std::cout << "Fire";
      break;
    case Skill::SkillType::ice:
      std::cout << "Ice";
      break;
    case Skill::SkillType::thunder:
      std::cout << "Thunder";
      break;
    case Skill::SkillType::holy:
      std::cout << "Holy";
      break;
    case Skill::SkillType::dark:
      std::cout << "Dark";
      break;
    case Skill::SkillType::none:
      break;
    }
    std::cout << "\n";
  }
}

uint Enemy::getVulperc() const { return this->vulperc; }
uint Enemy::getResperc() const { return this->resperc; }

// attack methods
void Enemy::attack(Entity &obj) {

  // random generator
  std::random_device rd;
  std::mt19937 rng(rd());

  // range of damage
  std::uniform_int_distribution<uint> uni(this->atk - percu(this->atk, 10),
                                          this->atk + percu(this->atk, 10));
  uint dmg = uni(rng),
       dmg_eff = (dmg > obj.getDef() ? dmg - obj.getDef() : obj.getDef() - dmg);
  obj.getHit(dmg_eff);
}

void Enemy::magicAttack(Entity &obj) {

  // creating random generator
  std::random_device rd;
  std::mt19937 rng(rd());

  // range of damage
  std::uniform_int_distribution<uint> uni(this->matk - percu(this->matk, 10),
                                          this->matk + percu(this->matk, 10));
  uint dmg = uni(rng), dmg_eff = (dmg > obj.getMdef() ? dmg - obj.getMdef()
                                                      : obj.getMdef() - dmg);
  obj.getHit(dmg_eff);
}

// check skill type is effective
// against the enemy (needs to be corrected)
bool Enemy::isEffective(Skill::SkillType skill) {
  for (uint i = 0; i < this->vulnerabilities.size();) {
    if (skill == vulnerabilities[i++])
      return true;
  }
  return 0;
}

bool Enemy::isResistant(Skill::SkillType skill) {
  for (uint i = 0; i < this->resistances.size();)
    if (skill == vulnerabilities[i++])
      return true;
  return 0;
}

} // namespace ddgm