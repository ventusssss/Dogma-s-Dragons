#ifndef DDGM_ENEMIES_HPP
#define DDGM_ENEMIES_HPP

#include "ddgm/entity.hpp"
#include "ddgm/skills.hpp"
#include <vector>

namespace ddgm {

class Enemy : public Entity {
protected:
  // Declaring two vectors of type Skill::SkillType
  // to store all the vulnerabilities and resistences of an enemy
  std::vector<Skill::SkillType> vulnerabilities, resistances;

  // Declaring two variables that indicate the percentage
  // value of how much the player attack has to be increased
  // or decreased
  uint vulperc, resperc;

public:
  // Declaring the base constructor for each enemy object
  Enemy(std::string name, uint hp, uint atk, uint matk, uint def, uint mdef,
        uint xp, std::vector<Skill::SkillType> vulnerabilities,
        std::vector<Skill::SkillType> resistances, uint vulperc, uint resperc);

  // Defining the attack function for
  // physical class enemies
  int attack(Entity &obj);

  // Declaring two functions that are related to the battle
  // (that's why we haven't used them in the definition files)
  // that allow the player to see an enemy's vulnerabilities/resistances
  void printVulnerabilities() const;
  void printResistances() const;

  // Declaring getter functions that return a vector of type
  // Skill::SkillType
  std::vector<Skill::SkillType> getVulnerabilities() const;
  std::vector<Skill::SkillType> getResistances() const;

  // Declaring getter functions for vulperc
  // and resperc values
  uint getVulperc() const;
  uint getResperc() const;

  // Defining two functions to check if a type
  // of skill used by the player is effective or
  // not against an enemy
  bool isEffective(Skill::SkillType skill);
  bool isResistant(Skill::SkillType skill);
};

class Magic : public Enemy {
public:
  using Enemy::Enemy;
};

// Starting to declare each enemy, initializing
// its constructor

// SMALL ENEMIES

inline std::vector<Enemy> selectable_enemies = {
    Enemy("Golbin", 300, 125, 0, 47, 37, 65,
          {Skill::SkillType::fire, Skill::SkillType::ice},
          {Skill::SkillType::dark}, 50, 40),
    Enemy("Wolf", 100, 23, 0, 55, 0, 25, {Skill::SkillType::fire},
          {Skill::SkillType::dash, Skill::SkillType::ice,
           Skill::SkillType::thunder},
          10, 10),
    Enemy("Undead", 1000, 55, 0, 300, 0, 185,
          {Skill::SkillType::fire, Skill::SkillType::holy},
          {Skill::SkillType::ice, Skill::SkillType::thunder,
           Skill::SkillType::dark},
          350, 50),
    Enemy("Bandit", 500, 150, 0, 63, 13, 65,
          {Skill::SkillType::fire, Skill::SkillType::ice,
           Skill::SkillType::thunder, Skill::SkillType::dark},
          {Skill::SkillType::none}, 40, 0),
    Enemy("Saurian", 1000, 220, 50, 76, 20, 400, {Skill::SkillType::ice},
          {Skill::SkillType::fire, Skill::SkillType::dash}, 150, 40),
    Enemy("Gargoyle", 5000, 710, 372, 280, 123, 1350,
          {Skill::SkillType::dash, Skill::SkillType::thunder},
          {Skill::SkillType::slash, Skill::SkillType::fire,
           Skill::SkillType::ice, Skill::SkillType::dark},
          50, 75),
    Enemy("Harpy", 700, 210, 0, 43, 63, 140, {Skill::SkillType::fire},
          {Skill::SkillType::dark}, 20, 20),
    Enemy("Skeleton", 650, 140, 55, 30, 30, 240,
          {Skill::SkillType::dash, Skill::SkillType::holy},
          {Skill::SkillType::slash, Skill::SkillType::fire,
           Skill::SkillType::ice, Skill::SkillType::thunder,
           Skill::SkillType::dark},
          50, 40),
    Enemy("Succubus", 3200, 520, 430, 160, 120, 660,
          {Skill::SkillType::slash, Skill::SkillType::holy},
          {Skill::SkillType::fire, Skill::SkillType::ice,
           Skill::SkillType::thunder, Skill::SkillType::dark},
          35, 95),
    Magic("Ghost", 1000, 1, 200, 100, 125, 900, {Skill::SkillType::holy},
          {Skill::SkillType::slash, Skill::SkillType::dash,
           Skill::SkillType::dark},
          250, 83),
    Magic("Vile Eye", 1500, 525, 600, 130, 515, 5000, {Skill::SkillType::none},
          {Skill::SkillType::dash, Skill::SkillType::fire,
           Skill::SkillType::ice, Skill::SkillType::thunder,
           Skill::SkillType::dark},
          0, 57)};

// FINAL BOSS
class Grigori : public Enemy {
public:
  Grigori()
      : Enemy("Grigori", 100000, 1250, 600, 260, 280, 80000,
              {Skill::SkillType::dark}, {Skill::SkillType::fire}, 30, 80) {}
};

} // namespace ddgm

#endif