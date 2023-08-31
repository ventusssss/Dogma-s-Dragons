#ifndef DDGM_PAWN_HPP
#define DDGM_PAWN_HPP

#include "ddgm/entity.hpp"
#include "ddgm/player.hpp"
#include <random>

namespace ddgm {
class Pawn : public Player {
  using Player::Player;

public:
  // declaring functions that allow the pawn to say something
  // about weaknesses or resistances of an enemy
  void tellVulnerabilities(Enemy &obj);
  void tellResistances(Enemy &obj);

  // Declaring all the functions that allow the pawn to
  // say something during specific phases of the game
  void travelTalk(bool cas);
  void itemfindTalk(bool cas);
  void battleTalk(bool cas, Enemy &obj);
  void pawndeathTalk();

  // Declaring a function that allows the pawn to attack
  // managing the attack choice based on the enemy vulnerabilities
  // and resistances
  void pawn_attack(Enemy &obj);
};
} // namespace ddgm

#endif