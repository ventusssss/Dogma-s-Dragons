#include "ddgm/enemies.hpp"
#include "ddgm/entity.hpp"
//#include "ddgm/items.hpp"
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

// declaring a function for the new game start
void new_game(Player *player, Pawn *pawn);

void load_characterData(Player &player, Pawn &pawn, nlohmann::json data);

// Declaring a function for the menu in-game
int game_menu();

// Declaring the in-game functions
void travel(Player &player, Pawn &pawn);

std::vector<Enemy> enemies_appearing(uint enemyNumber);

uint battle_start();

uint enemy_choosing(std::vector<Enemy> enemiesToFight);

void display_enemies_names(std::vector<Enemy> enemies);

void display_character_names(Player &player, Pawn &pawn);

void display_skills(std::vector<Skill> usable_skills);

std::vector<Entity> display_entities(Player &player, Pawn &pawn, std::vector<Enemy> enemies);

uint entity_choice(std::vector<Entity> entities);

uint attack_choice(std::vector<Skill *> usable_skills);

void battle(Player &player, Pawn &pawn);

void change_abilities(Player &player, Pawn &pawn);

void change_vocation(Player &player, Pawn &pawn);

void check_stats(Player &player, Pawn &pawn);

// Declaring a function for the final credits of the game
void game_credits();

// Declaring a function for the game introduction
void game_introduction();

// declaring a function for narrating what
// happens after the introduction
void game_progression(Pawn *pawn);

// functions that take the user input to give
// a name to their characters
std::string playerChooseName();
std::string pawnChooseName();

// function to choose the player's starting vocation
uint chooseStartingVocation();

void characterCreation(Player *player);

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

void skill_removing(Player *player);

} // namespace ddgm
