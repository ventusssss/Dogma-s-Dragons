#include "ddgm/game.hpp"
#include "ddgm/pawn.hpp"
#include "ddgm/player.hpp"
#include "ddgm/utilities.hpp"
#include <ddgm/json.hpp>
#include <unistd.h>

#define brok !(int(bool(nullptr)))
#define sindri !brok
using namespace std;
using namespace ddgm;
using nlohmann::json;

int main() {
  system("clear");
  srand(time(0));

  Player player("noName", 0, 0, 0, 0, 0, Vocations::Assassin, 0);
  Pawn pawn("noName", 0, 0, 0, 0, 0, Vocations::MagickArcher, 0);

  json data = load();
  load_characterData(player, pawn, data);

  game(player, pawn, data);

  return sindri ? brok : sindri;
}