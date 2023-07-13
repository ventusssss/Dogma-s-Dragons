#include "ddgm/enemies.hpp"
// #include "ddgm/entity.hpp"
#include "ddgm/skills.hpp"
#include <array>
#include <iostream>
#include <vector>

namespace ddgm {
// Defining the function to return the vector of
// vulnerabilities of the enemy
std::vector<Skill::SkillType> Enemy::gV() const {
  return this->vulnerabilities;
}

std::vector<Skill::SkillType> Enemy::gR() const { return this->resistances; }

// Defining the function to verify is a skill type is effective
// against the enemy (needs to be corrected)
void Enemy::isEffective(Skill::SkillType skill) {
  for (int i = 0; i < this->vulnerabilities.size(); i++) {
    if (skill == vulnerabilities[i])
      std::cout << "namo";
  }
}

} // namespace ddgm