#ifndef DDGM_PAWN_HPP
#define DDGM_PAWN_HPP

#include "ddgm/entity.hpp"
#include "ddgm/player.hpp"
#include <random>

namespace ddgm {
class Pawn : public Player {
  using Player::Player;

public:
  // declaring a function that allows the pawn to say something
  // about weaknesses or resistances of an enemy
  void tellVulnerabilities(bool cas, Enemy &obj);
  void tellResistances(bool cas, Enemy &obj);
  void travelTalk();
  void itemfindTalk();
  void battleTalk();
  void arisendeathTalk();
  void pawndeathTalk();
};
} // namespace ddgm

#endif