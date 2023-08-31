#include "ddgm/skills.hpp"
#include <string>

namespace ddgm {
// Defining the function to return the type of the skill
// as a string so it's readable by the player
std::string Skill::getSkillType() const {
  switch (this->type) {
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
    return "Nigga what";
  }
}

Skill::SkillType Skill::returnSkillType() const {
  switch (this->type) {
  case SkillType::slash:
    return SkillType::slash;
    break;
  case SkillType::dash:
    return SkillType::dash;
    break;
  case SkillType::fire:
    return SkillType::fire;
    break;
  case SkillType::ice:
    return SkillType::ice;
    break;
  case SkillType::thunder:
    return SkillType::thunder;
    break;
  case SkillType::holy:
    return SkillType::holy;
    break;
  case SkillType::dark:
    return SkillType::dark;
    break;
  case SkillType::none:
    return SkillType::none;
    break;
  default:
    return SkillType::none;
  }
}

std::string Skill::getName() const { return this->name; }
uint Skill::getCd() const { return this->cd; }
uint Skill::getActualCd() const { return this->actual_cd; }
float Skill::getMultiplier() const { return this->multiplier; }
} // namespace ddgm