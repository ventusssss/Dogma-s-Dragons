#ifndef DDGM_ENEMIES_HPP
#define DDGM_ENEMIES_HPP

#include "ddgm/entity.hpp"

namespace ddgm {

// SMALL ENEMIES
// Red ones

class Golbin : public Entity {
public:
  Golbin() : Entity("Golbin", 300, 125, 0, 47, 37, Colors::red, 65) {}
};

class Wolf : public Entity {
public:
  Wolf() : Entity("Wolf", 100, 23, 0, 55, 0, Colors::red, 25) {}
};

class Undead : public Entity {
public:
  Undead() : Entity("Undead", 1000, 55, 0, 300, 0, Colors::red, 185) {}
};

// Yellow ones

class Bandit : public Entity {
public:
  Bandit() : Entity("Bandit", 500, 150, 0, 63, 13, Colors::yellow, 65) {}
};

class Saurian : public Entity {
public:
  Saurian() : Entity("Saurian", 1000, 220, 50, 76, 20, Colors::yellow, 400) {}
};

class Gargoyle : public Entity {
public:
  Gargoyle()
      : Entity("Gargoyle", 5000, 710, 372, 280, 123, Colors::yellow, 1350) {}
};

class Harpy : public Entity {
public:
  Harpy() : Entity("Harpy", 700, 210, 0, 43, 63, Colors::yellow, 140) {}
};

class Skeleton : public Entity {
public:
  Skeleton() : Entity("Skeleton", 650, 140, 55, 30, 30, Colors::yellow, 240) {}
};

class Succubus : public Entity {
public:
  Succubus()
      : Entity("Succubus", 3200, 520, 430, 160, 120, Colors::yellow, 660) {}
};

// Blue ones

class Ghost : public Magic {
public:
  Ghost() : Magic("Ghost", 1000, 1, 200, 100, 125, Colors::blue, 900) {}
};

class Vile_Eye : public Magic {
public:
  Vile_Eye()
      : Magic("Vile Eye", 1500, 525, 600, 130, 515, Colors::blue, 5000) {}
};

// BOSSES

// lvl >= 5
class Cyclope : public Entity {
public:
  Cyclope() : Entity("Cyclope", 12000, 400, 0, 80, 60, Colors::red, 4000) {}
};

// lvl >= 10
class Chimera : public Entity {
public:
  Chimera() : Entity("Chimera", 15000, 900, 150, 250, 150, Colors::red, 7700) {}
};

// lvl >= 15
class Ogre : public Entity {
public:
  Ogre() : Entity("Ogre", 15000, 775, 0, 210, 15, Colors::red, 500) {}
};

// lvl >= 15
class Golem : public Magic {
public:
  Golem() : Magic("Golem", 20000, 735, 473, 0, 0, Colors::blue, 8600) {}
};

// lvl >= 25
class Hydra : public Entity {
public:
  Hydra()
      : Entity("Hydra", 75000, 1230, 675, 145, 145, Colors::yellow, 16000) {}
};

// 卍卍卍 --- FINAL BOSS --- 卍卍卍
class Grigori : public Entity {
public:
  Grigori()
      : Entity("Grigori", 100000, 1250, 600, 260, 280, Colors::red, 80000) {}
};

} // namespace ddgm

#endif