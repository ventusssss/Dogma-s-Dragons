#include "ddgm/enemies.hpp"
#include "ddgm/entity.hpp"
#include "ddgm/items.hpp"
#include "ddgm/pawn.hpp"
#include "ddgm/player.hpp"
#include "ddgm/skills.hpp"
#include "ddgm/utilities.hpp"

namespace ddgm {

// Declaring a function that allows to generate a casual item
// among the existent ones, with some percentages
void itemFind();

// Declaring a function for the main menu of the game;
int start_menu();

// Declaring a function for the menu in-game
int game_menu();

// Declaring a function for the final credits of the game
void game_credits();

// Declaring a function for the game introduction
void game_introduction();

// functions that take the user input to give
// a name to their characters
std::string playerChooseName();
std::string pawnChooseName();

// function to choose the player's starting vocation
uint chooseStartingVocation();

void characterCreation(Player *player);

// Declaring the function for the battles
void battle();

// Defining the function to print all
// the vocations' skills
void fighter_skills();
void warrior_skills();
void paladin_skills();
void strider_skills();
void ranger_skills();
void assassin_skills();
void mage_skills();
void sorcerer_skills();
void magickarcher_skills();

// Declaring a function that allows the player
// to choose what skills to use, from a minimum of 0
// to a maximum of 6
void skill_choosing(Player *player);

} // namespace ddgm
