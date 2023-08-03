#include "ddgm/enemies.hpp"
#include "ddgm/entity.hpp"
#include "ddgm/skills.hpp"
#include "ddgm/utilities.hpp"
#include <array>
#include <iostream>
#include <random>
#include <vector>

// ALL THE MEANINGS OF THE FUNCTIONS
// ARE EXPLAINED IN THE HPP FILE

namespace ddgm {

// Initializing Enemy's constructor
Enemy::Enemy(std::string name, uint hp, uint atk, uint matk, uint def,
             uint mdef, uint xp, std::vector<Skill::SkillType> vulnerabilities,
             std::vector<Skill::SkillType> resistances, uint vulperc,
             uint resperc)
    : Entity(name, hp, atk, matk, def, mdef, xp),
      vulnerabilities(vulnerabilities), resistances(resistances),
      vulperc(vulperc), resperc(resperc) {}

std::vector<Skill::SkillType> Enemy::getVulnerabilities() const {
  return this->vulnerabilities;
}

std::vector<Skill::SkillType> Enemy::getResistances() const {
  return this->resistances;
}

void Enemy::printVulnerabilities() const {
  std::cout << "Vulnerabilities:\n";
  // Iterating through all the vulnerablities vector
  // and with a switch case, printing the name of the SKillType
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

// Same thing here for the resistances
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

  uint dmg = generateRandom(this->atk - percu(this->atk, 10),
                            this->atk + percu(this->atk, 10)),
       dmg_eff = (dmg > obj.getDef() ? dmg - obj.getDef() : obj.getDef() - dmg);
  obj.getHit(dmg_eff);
}

void Enemy::magicAttack(Entity &obj) {
  uint dmg = generateRandom(this->matk - percu(this->matk, 10),
                            this->matk + percu(this->matk, 10)),
       dmg_eff =
           (dmg > obj.getMdef() ? dmg - obj.getMdef() : obj.getMdef() - dmg);
  obj.getHit(dmg_eff);
}

bool Enemy::isEffective(Skill::SkillType skill) {
  for (uint i = 0; i < this->vulnerabilities.size();) {
    if (skill == vulnerabilities[i++])
      return true;
  }
  return 0;
}

bool Enemy::isResistant(Skill::SkillType skill) {
  for (uint i = 0; i < this->resistances.size();)
    if (skill == resistances[i++])
      return true;
  return 0;
}

} // namespace ddgm