#ifndef DDGM_ENEMIES_HPP
#define DDGM_ENEMIES_HPP

#include "ddgm/entity.hpp"
#include "ddgm/skills.hpp"
#include <vector>

namespace ddgm {

class Enemy : public Entity {
protected:
  std::vector<Skill::SkillType> vulnerabilities, resistances;

public:
  Enemy(std::string name, uint hp, uint atk, uint matk, uint def, uint mdef,
        uint xp, std::vector<Skill::SkillType> vulnerabilities,
        std::vector<Skill::SkillType> resistances, uint vulperc, uint resperc);
  std::vector<Skill::SkillType> gV() const;
  std::vector<Skill::SkillType> gR() const;
  void isEffective(Skill::SkillType skill);
};

class Magic : public Enemy {
public:
  void magicAttack(Entity &obj);
  using Enemy::Enemy;
};

// SMALL ENEMIES
// Red ones

class Golbin : public Enemy {
public:
  Golbin()
      : Enemy("Golbin", 300, 125, 0, 47, 37, 65,
              {Skill::SkillType::fire, Skill::SkillType::ice},
              {Skill::SkillType::dark}, 50, 40) {}
};

class Wolf : public Enemy {
public:
  Wolf()
      : Enemy("Wolf", 100, 23, 0, 55, 0, 25, {Skill::SkillType::fire},
              {Skill::SkillType::dash, Skill::SkillType::ice,
               Skill::SkillType::thunder},
              10, 10) {}
};

class Undead : public Enemy {
public:
  Undead()
      : Enemy("Undead", 1000, 55, 0, 300, 0, 185,
              {Skill::SkillType::fire, Skill::SkillType::holy},
              {Skill::SkillType::ice, Skill::SkillType::thunder,
               Skill::SkillType::dark},
              350, 50) {}
};

// Yellow ones

class Bandit : public Enemy {
public:
  Bandit()
      : Enemy("Bandit", 500, 150, 0, 63, 13, 65,
              {Skill::SkillType::fire, Skill::SkillType::ice,
               Skill::SkillType::thunder, Skill::SkillType::dark},
              {Skill::SkillType::none}, 40, 0) {}
};

class Saurian : public Enemy {
public:
  Saurian()
      : Enemy("Saurian", 1000, 220, 50, 76, 20, 400, {Skill::SkillType::ice},
              {Skill::SkillType::fire, Skill::SkillType::dash}, 150, 40) {}
};

class Gargoyle : public Enemy {
public:
  Gargoyle()
      : Enemy("Gargoyle", 5000, 710, 372, 280, 123, 1350,
              {Skill::SkillType::dash, Skill::SkillType::thunder},
              {Skill::SkillType::slash, Skill::SkillType::fire,
               Skill::SkillType::ice, Skill::SkillType::dark},
              50, 75) {}
};

class Harpy : public Enemy {
public:
  Harpy()
      : Enemy("Harpy", 700, 210, 0, 43, 63, 140, {Skill::SkillType::fire},
              {Skill::SkillType::dark}, 20, 20) {}
};

class Skeleton : public Enemy {
public:
  Skeleton()
      : Enemy("Skeleton", 650, 140, 55, 30, 30, 240,
              {Skill::SkillType::dash, Skill::SkillType::holy},
              {Skill::SkillType::slash, Skill::SkillType::fire,
               Skill::SkillType::ice, Skill::SkillType::thunder,
               Skill::SkillType::dark},
              50, 40) {}
};

class Succubus : public Enemy {
public:
  Succubus()
      : Enemy("Succubus", 3200, 520, 430, 160, 120, 660,
              {Skill::SkillType::slash, Skill::SkillType::holy},
              {Skill::SkillType::fire, Skill::SkillType::ice,
               Skill::SkillType::thunder, Skill::SkillType::dark},
              35, 95) {}
};

// Blue ones

class Ghost : public Magic {
public:
  Ghost()
      : Magic("Ghost", 1000, 1, 200, 100, 125, 900, {Skill::SkillType::holy},
              {Skill::SkillType::slash, Skill::SkillType::dash,
               Skill::SkillType::dark},
              250, 83) {}
};

class Vile_Eye : public Magic {
public:
  Vile_Eye()
      : Magic("Vile Eye", 1500, 525, 600, 130, 515, 5000,
              {Skill::SkillType::none},
              {Skill::SkillType::dash, Skill::SkillType::fire,
               Skill::SkillType::ice, Skill::SkillType::thunder,
               Skill::SkillType::dark},
              0, 57) {}
};

// BOSSES

// lvl >= 5
class Cyclope : public Enemy {
public:
  Cyclope()
      : Enemy("Cyclope", 12000, 400, 0, 80, 60, 4000,
              {Skill::SkillType::thunder},
              {Skill::SkillType::fire, Skill::SkillType::ice}, 80, 40) {}
};

// lvl >= 10
class Chimera : public Enemy {
public:
  Chimera()
      : Enemy("Chimera", 15000, 900, 150, 250, 150, 7700,
              {Skill::SkillType::none},
              {Skill::SkillType::fire, Skill::SkillType::ice,
               Skill::SkillType::thunder, Skill::SkillType::holy,
               Skill::SkillType::dark},
              0, 15) {}
};

// lvl >= 15
class Ogre : public Enemy {
public:
  Ogre()
      : Enemy("Ogre", 15000, 775, 0, 210, 15, 500, {Skill::SkillType::none},
              {Skill::SkillType::dark}, 0, 60) {}
};

// lvl >= 15
class Golem : public Magic {
public:
  Golem()
      : Magic("Golem", 20000, 735, 473, 0, 0, 8600, {Skill::SkillType::none},
              {Skill::SkillType::none}, 0, 0) {}
};

// lvl >= 25
class Hydra : public Enemy {
public:
  Hydra()
      : Enemy("Hydra", 75000, 1230, 675, 145, 145, 16000,
              {Skill::SkillType::slash},
              {Skill::SkillType::dash, Skill::SkillType::fire,
               Skill::SkillType::ice, Skill::SkillType::thunder,
               Skill::SkillType::holy, Skill::SkillType::dark},
              10, 58) {}
};

class Wyrm : public Enemy {
public:
  Wyrm()
      : Enemy("Wyrm", 60000, 800, 1300, 270, 800, 24000,
              {Skill::SkillType::fire}, {Skill::SkillType::ice}, 50, 75) {}
};

class FrostWyrm : public Magic {
public:
  FrostWyrm()
      : Magic("Frost Wyrm", 90000, 1000, 400, 320, 524, 64000,
              {Skill::SkillType::fire},
              {Skill::SkillType::ice, Skill::SkillType::thunder,
               Skill::SkillType::holy, Skill::SkillType::dark},
              20, 70) {}
};

class Drake : public Enemy {
public:
  Drake()
      : Enemy("Drake", 80000, 450, 275, 300, 100, 25000,
              {Skill::SkillType::ice}, {Skill::SkillType::fire}, 50, 80) {}
};

// 卍卍卍 --- FINAL BOSS --- 卍卍卍
class Grigori : public Enemy {
public:
  Grigori()
      : Enemy("Grigori", 100000, 1250, 600, 260, 280, 80000,
              {Skill::SkillType::dark}, {Skill::SkillType::fire}, 30, 80) {}
};

} // namespace ddgm

#endif