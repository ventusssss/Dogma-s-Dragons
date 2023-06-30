#ifndef DDGM_PAWN_HPP
#define DDGM_PAWN_HPP

#include "ddgm/entity.hpp"
#include "ddgm/player.hpp"

namespace ddgm {
class Pawn : public Player {
  using Player::Player;
};
} // namespace ddgm

#endif