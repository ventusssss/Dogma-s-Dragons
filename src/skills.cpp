#include "ddgm/skills.hpp"
#include <string>

namespace ddgm {
// Defining the function to return the type of the skill
// as a string so it's readable by the player

void Skill::use() {
  this->actual_cd = this->cd;
}
void Skill::decrement_cd() {
  if (actual_cd)
    this->actual_cd--;
}

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
  case SkillType::cure:
    return "Cure";
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

void Skill::setName(std::string name) { this->name = name; }

void Skill::setMultiplier(float multiplier) { this->multiplier = multiplier; }

void Skill::setType(uint type) { this->type = (Skill::SkillType)type; }

void Skill::setCooldown(uint cooldown) { this->cd = cooldown; }

nlohmann::json Skill::getJson() const {
  nlohmann::json data = {{"name", this->getName()},
                         {"type", this->returnSkillType()},
                         {"cooldown", this->getCd()},
                         {"multiplier", this->getMultiplier()}};
  return data;
}

} // namespace ddgm