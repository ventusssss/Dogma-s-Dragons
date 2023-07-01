#ifndef DDGM_ABILITIES_HPP
#define DDGM_ABILITIES_HPP

#include <string>
/*
  Fighter:
  - Broad Cut, Slash, 0
  - Burst Strike, Dash, 0
  - Broad Slash, Slash, 1
  - Blitz Strike, Dash, 1
  - Heavenly Slash, Slash, 2
  - Hindsight Strike, Dash, 2
  Warrior:
  - Pommel Strike, dash, 1
  - Upward Strike, dash, 1
  - Whirlwind Strike, dash, 2
  - Corona Slash, slash, 1
  - Catapult Blade, slash, 2
  - Arc of Vengeance, slash, 4
  Mystic Knight
  - Broad Cut, slash, 0
  - Burst Strike, dash, 0
  - Magick Cannon, Holy, 2
  - High Frigor, Ice, 1
  - High Comestion, Fire, 1
  - High Brontide, Thunder, 1
  Strider:
  - Thousands Kisses, slash, 1
  - Shearing Wind, dash, 0
  - Mighty Bend, dash, 2
  - Brain Splitter, slash, 2
  - Fivefold Flurry, dash, 2
  - Hailstorm Volley, dash, 2
  Ranger:
  - Thousand Kisses, slash, 2
  - Shearing Wind, dash, 1
  - Dazzle Blast, fire, 1
  - Deathly Arrow, dash 2
  - Comet Shot, dash, 1
  - Tenfold Flurry, dash, 2
  Assassin:
  - Blind Strike, slash, 1
  - Great Windmill, dash, 2
  - Cutting Wind, dash, 2
  - Masterful Kill, slash, 2
  - Fivefold Flurry, dash, 1
  - Eagle Sight, dash, 3
  Mage:
  - Fire Affinity, fire, 2
  - Ice affinity, ice, 2
  - Thunder affinity, thunder, 2
  - Holy Affinity, holy, 2
  - dark affinity, dark, 2
  - High Comestion, fire, 1
  - High Frigor, ice, 1
  - High Brontide, thunder, 1
  - High Spellscrean, heal (holy), 2
  Sorcerer:
  - High Maelstorm, thunder, 4
  - High Bolide, fire, 4
  - High Seism, Holy, 4
  - High Gicel, ice, 4
  - Necromancy, dark, 3
  - Fire Affinity, fire, 2
  - Ice affinity, ice, 2
  - Thunder affinity, thunder, 2
  - Holy Affinity, holy, 2
  - dark affinity, dark, 2
  Magick Archer:
  - Hundreds Kisses, slash, 0
  - Bitting Wind, dash, 0
  - Ricochet Hunter, thunder, 2
  - Sixfold Bolt, ice, 2
  - Magickal Gleam, holy, 2
  - Explosive Bolt, fire, 2
*/
namespace ddgm {
class Skill {
protected:
  std::string name;
  uint cooldown;
  virtual void use() = 0;

public:
  Skill(std::string name, uint cooldown);
};

} // namespace ddgm

#endif