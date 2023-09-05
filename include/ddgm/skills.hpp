#ifndef DDGM_ABILITIES_HPP
#define DDGM_ABILITIES_HPP

#include "ddgm/entity.hpp"
#include <ostream>
#include <string>
#include <vector>

namespace ddgm {
class Skill {
public:
  // Declaring an enumeration of all the possible types
  // of skill in-game
  enum class SkillType {
    slash,
    dash,
    fire,
    ice,
    thunder,
    holy,
    dark,
    cure,
    none
  };

private:
  // Declaring the type, name and cooldown of each skill
  SkillType type, actualType;
  std::string name;
  // 5/0
  uint cd, actual_cd;
  float multiplier;

public:
  // Declaring and initializing the constructor for
  // the skill class
  Skill(std::string name, uint cd, SkillType type, float multiplier)
      : name(name), cd(cd), actual_cd(0), type(type), actualType(type),
        multiplier(multiplier) {}

  inline void use() {
    if (!actual_cd)
      this->actual_cd = this->cd;
  }
  inline Skill operator--() {
    if (this->actual_cd)
      this->actual_cd--;
    return *this;
  }

  // Getter functions that return the private
  // values of the class
  std::string getSkillType() const;
  SkillType returnSkillType() const;
  SkillType returnActualType() const;
  std::string getName() const;
  uint getCd() const;
  uint getActualCd() const;
  float getMultiplier() const;

  inline void setSkillType(SkillType type) { this->actualType = type; }
  inline void resetSkillType() { this->actualType = this->type; }
};

// Declaring and initializing a vector of type Skill
// that contains all the skills in game

const std::vector<Skill> skills = {
    // Fighter
    Skill("Broad Cut", 1, Skill::SkillType::slash, 1.1),
    Skill("Burst Strike", 0, Skill::SkillType::dash, 1.2),
    Skill("Broad Slash", 1, Skill::SkillType::slash, 1.1),
    Skill("Blitz Strike", 1, Skill::SkillType::dash, 1.2),
    Skill("Heavenly Slash", 2, Skill::SkillType::slash, 1.4),
    Skill("Handsight Strike", 2, Skill::SkillType::dash, 1.5),

    // Warrior
    Skill("Pommel Strike", 1, Skill::SkillType::dash, 1.3),
    Skill("Upward Strike", 1, Skill::SkillType::dash, 1.3),
    Skill("Whirlwind Strike", 2, Skill::SkillType::dash, 1.7),
    Skill("Corona Slash", 1, Skill::SkillType::slash, 1.4),
    Skill("Catapult Blade", 2, Skill::SkillType::slash, 1.5),
    Skill("Arc of Vengeance", 4, Skill::SkillType::slash, 6.3),

    // Paladin
    Skill("Broad Cut", 0, Skill::SkillType::slash, 1.2),
    Skill("Burst Strike", 0, Skill::SkillType::dash, 1.3),
    Skill("Magick Cannon", 2, Skill::SkillType::holy, 3.4),
    Skill("High Frigor", 1, Skill::SkillType::ice, 2.1),
    Skill("High Comestion", 1, Skill::SkillType::fire, 2.1),
    Skill("High Brontide", 1, Skill::SkillType::thunder, 2.1),

    // Strider
    Skill("Thousand Kisses", 1, Skill::SkillType::slash, 1.3),
    Skill("Shearing Wind", 0, Skill::SkillType::dash, 1.1),
    Skill("Mighy Bend", 2, Skill::SkillType::dash, 2.4),
    Skill("Brain Splitter", 2, Skill::SkillType::slash, 3.5),
    Skill("Fivefold Flurry", 2, Skill::SkillType::dash, 2.3),
    Skill("Hailstorm Volley", 2, Skill::SkillType::dash, 2.1),

    // Ranger
    Skill("Thousand Kisses", 2, Skill::SkillType::slash, 1.7),
    Skill("Shearing Wind", 1, Skill::SkillType::dash, 1.3),
    Skill("Dazzle Blast", 1, Skill::SkillType::fire, 1.7),
    Skill("Deatly Arrow", 2, Skill::SkillType::dash, 3.3),
    Skill("Comet Shot", 1, Skill::SkillType::dash, 1.7),
    Skill("Tenfold Flurry", 2, Skill::SkillType::dash, 3.7),

    // Assassin
    Skill("Blind Strike", 1, Skill::SkillType::slash, 1.3),
    Skill("Great Windmill", 2, Skill::SkillType::dash, 2.4),
    Skill("Cutting Wind", 2, Skill::SkillType::dash, 1.8),
    Skill("Masterful Kill", 3, Skill::SkillType::slash, 4.2),
    Skill("Fivefold Flurry", 1, Skill::SkillType::dash, 1.8),
    Skill("Eagle Sight", 3, Skill::SkillType::dash, 2.7),

    // Mage
    Skill("Fire Pact", 2, Skill::SkillType::fire, 1),
    Skill("Ice Pact", 2, Skill::SkillType::ice, 1),
    Skill("Thunder Pact", 2, Skill::SkillType::thunder, 1),
    Skill("Holy Pact", 2, Skill::SkillType::holy, 1),
    Skill("Dark Pact", 2, Skill::SkillType::dark, 1),
    Skill("High Comestion", 1, Skill::SkillType::fire, 1.2),
    Skill("High Frigor", 1, Skill::SkillType::ice, 1.2),
    Skill("High Brontide", 1, Skill::SkillType::thunder, 1.2),
    Skill("High Spellscrean", 2, Skill::SkillType::cure, 0),

    // Sorcerer
    Skill("High Maelstorm", 4, Skill::SkillType::thunder, 6.4),
    Skill("High Bolide", 4, Skill::SkillType::fire, 5.2),
    Skill("High Seism", 4, Skill::SkillType::holy, 5.2),
    Skill("High Gicel", 4, Skill::SkillType::ice, 4.7),
    Skill("Necromancy", 3, Skill::SkillType::dark, 3.2),
    Skill("Fire Pact", 2, Skill::SkillType::fire, 1),
    Skill("Ice Pact", 2, Skill::SkillType::ice, 1),
    Skill("Thunder Pact", 2, Skill::SkillType::thunder, 1),
    Skill("Holy Pact", 2, Skill::SkillType::holy, 1),
    Skill("Dark Pact", 2, Skill::SkillType::dark, 1),

    // Magick-Archer
    Skill("Hundred Kisses", 0, Skill::SkillType::slash, 1.2),
    Skill("Bitting Wind", 0, Skill::SkillType::dash, 1.1),
    Skill("Ricochet Hunter", 2, Skill::SkillType::thunder, 3.2),
    Skill("Sixfold Bolt", 2, Skill::SkillType::ice, 3.3),
    Skill("Magickal Gleam", 2, Skill::SkillType::holy, 2.1),
    Skill("Explosive Bolt", 2, Skill::SkillType::fire, 1.8),
    Skill("Sacrifice", 10, Skill::SkillType::dark, 50)};
} // namespace ddgm
#endif