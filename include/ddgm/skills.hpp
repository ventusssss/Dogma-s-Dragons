#ifndef DDGM_ABILITIES_HPP
#define DDGM_ABILITIES_HPP

#include "ddgm/entity.hpp"
#include <ostream>
#include <string>
#include <vector>

namespace ddgm {
class Skill {
public:
  enum class SkillType { slash, dash, fire, ice, thunder, holy, dark, none };

private:
  SkillType type;
  std::string name;
  uint cooldown;

public:
  Skill(std::string name, uint cooldown, SkillType type)
      : name(name), cooldown(cooldown), type(type) {}
  std::string getSkillType() const;
  std::string getName() const;
  uint getCooldown() const;
  friend std::ostream &operator<<(std::ostream &os,
                                  const Skill::SkillType skilltype);
};

const std::vector<Skill> skills = {
    // Fighter
    Skill("Broad Cut", 1, Skill::SkillType::slash),
    Skill("Burst Strike", 0, Skill::SkillType::dash),
    Skill("Broad Slash", 1, Skill::SkillType::slash),
    Skill("Blitz Strike", 1, Skill::SkillType::dash),
    Skill("Heavenly Slash", 2, Skill::SkillType::slash),
    Skill("Handsight Strike", 2, Skill::SkillType::dash),

    // Warrior
    Skill("Pommel Strike", 1, Skill::SkillType::dash),
    Skill("Upward Strike", 1, Skill::SkillType::dash),
    Skill("Whirlwind Strike", 2, Skill::SkillType::dash),
    Skill("Corona Slash", 1, Skill::SkillType::slash),
    Skill("Catapult Blade", 2, Skill::SkillType::slash),
    Skill("Arc of Vengeance", 4, Skill::SkillType::slash),

    // Magick Knight
    Skill("Broad Cut", 0, Skill::SkillType::slash),
    Skill("Burst Strike", 0, Skill::SkillType::dash),
    Skill("Magick Cannon", 2, Skill::SkillType::holy),
    Skill("High Frigor", 1, Skill::SkillType::ice),
    Skill("High Comestion", 1, Skill::SkillType::fire),
    Skill("High Brontide", 1, Skill::SkillType::thunder),

    // Strider
    Skill("Thousand Kisses", 1, Skill::SkillType::slash),
    Skill("Shearing Wind", 0, Skill::SkillType::dash),
    Skill("Mighy Bend", 2, Skill::SkillType::dash),
    Skill("Brain Splitter", 2, Skill::SkillType::slash),
    Skill("Fivefold Flurry", 2, Skill::SkillType::dash),
    Skill("Hailstorm Volley", 2, Skill::SkillType::dash),

    // Ranger
    Skill("Thousand Kisses", 2, Skill::SkillType::slash),
    Skill("Shearing Wind", 1, Skill::SkillType::dash),
    Skill("Dazzle Blast", 1, Skill::SkillType::fire),
    Skill("Deatly Arrow", 2, Skill::SkillType::dash),
    Skill("Comet Shot", 1, Skill::SkillType::dash),
    Skill("Tenfold Flurry", 2, Skill::SkillType::dash),

    // Assassin
    Skill("Blind Strike", 1, Skill::SkillType::slash),
    Skill("Great Windmill", 2, Skill::SkillType::dash),
    Skill("Cutting Wind", 2, Skill::SkillType::dash),
    Skill("Masterful Kill", 3, Skill::SkillType::slash),
    Skill("Fivefold Flurry", 1, Skill::SkillType::dash),
    Skill("Eagle Sight", 3, Skill::SkillType::dash),

    // Mage
    Skill("Fire Pact", 2, Skill::SkillType::fire),
    Skill("Ice Pact", 2, Skill::SkillType::ice),
    Skill("Thunder Pact", 2, Skill::SkillType::thunder),
    Skill("Holy Pact", 2, Skill::SkillType::holy),
    Skill("Dark Pact", 2, Skill::SkillType::dark),
    Skill("High Comestion", 1, Skill::SkillType::fire),
    Skill("High Frigor", 1, Skill::SkillType::ice),
    Skill("High Brontide", 1, Skill::SkillType::thunder),
    Skill("High Spellscrean", 2, Skill::SkillType::none),

    // Sorcerer
    Skill("High Maelstorm", 4, Skill::SkillType::thunder),
    Skill("High Bolide", 4, Skill::SkillType::fire),
    Skill("High Seism", 4, Skill::SkillType::holy),
    Skill("High Gicel", 4, Skill::SkillType::ice),
    Skill("Necromancy", 3, Skill::SkillType::dark),
    Skill("Fire Affinity", 2, Skill::SkillType::fire),
    Skill("Ice Affinity", 2, Skill::SkillType::ice),
    Skill("Thunder Affinity", 2, Skill::SkillType::thunder),
    Skill("Holy Affinity", 2, Skill::SkillType::holy),
    Skill("Dark Affinity", 2, Skill::SkillType::dark),

    // Magick-Archer
    Skill("Hundred Kisses", 0, Skill::SkillType::slash),
    Skill("Bitting Wind", 0, Skill::SkillType::dash),
    Skill("Ricochet Hunter", 2, Skill::SkillType::thunder),
    Skill("Sixfold Bolt", 2, Skill::SkillType::ice),
    Skill("Magickal Gleam", 2, Skill::SkillType::holy),
    Skill("Explosive Bolt", 2, Skill::SkillType::fire),
    Skill("Sacrifice", 5, Skill::SkillType::dark)};
} // namespace ddgm
#endif