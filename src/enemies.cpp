#include "ddgm/enemies.hpp"
// #include "ddgm/entity.hpp"
#include "ddgm/skills.hpp"
#include <array>
#include <iostream>
#include <vector>

namespace ddgm {
std::vector<Skill::SkillType> Enemy::gV() const {
  return this->vulnerabilities;
}

std::vector<Skill::SkillType> Enemy::gR() const { return this->resistances; }

void Enemy::isEffective(Skill::SkillType skill) {
  for (int i = 0; i < this->vulnerabilities.size(); i++) {
    if (skill == vulnerabilities[i])
      std::cout << "namo";
  }
}

} // namespace ddgm