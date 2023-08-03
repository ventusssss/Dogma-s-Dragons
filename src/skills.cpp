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

// Defining the getters to get the member attributes of the Skill
std::string Skill::getName() const { return this->name; }
uint Skill::getCooldown() const { return this->cooldown; }
} // namespace ddgm