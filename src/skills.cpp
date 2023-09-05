#include "ddgm/skills.hpp"
#include <string>

namespace ddgm {
// Defining the function to return the type of the skill
// as a string so it's readable by the player
std::string Skill::getSkillType() const {
  switch (this->actualType) {
  case SkillType::slash:
    return "Slash";
  case SkillType::dash:
    return "Dash";
  case SkillType::fire:
    return "Fire";
  case SkillType::ice:
    return "Ice";
  case SkillType::thunder:
    return "Thunder";
  case SkillType::holy:
    return "Holy";
  case SkillType::dark:
    return "Dark";
  default:
    return "None";
  }
}

Skill::SkillType Skill::returnSkillType() const { return this->type; }
Skill::SkillType Skill::returnActualType() const { return this->actualType; }

std::string Skill::getName() const { return this->name; }
uint Skill::getCd() const { return this->cd; }
uint Skill::getActualCd() const { return this->actual_cd; }
float Skill::getMultiplier() const { return this->multiplier; }
} // namespace ddgm