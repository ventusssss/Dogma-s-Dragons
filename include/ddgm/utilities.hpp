#ifndef DDGM_UTILITIES_HPP
#define DDGM_UTILITIES_HPP

#include <random>
#include <sys/types.h>

namespace ddgm {
// Declaring a function that returns the
// percentage of a given number
uint percu(uint n, uint perc);

// Declaring a function that, given the start
//  and the end of a range, creates a random number
//  among that range
uint generateRandom(uint start, uint end);

// Declaring the function that calculates
// the probability of an event to happen
bool casuality(uint perc);

// Declaring a function for the main menu of the game;
int start_menu();

// Declaring a function for the menu in-game
int game_menu();

// Declaring a function for the final credits of the game
void game_credits();

// Declaring a function for the game introduction
void game_introduction();

// Defining the function to print all
// the vocations' skills
void fighter_skills();
void warrior_skills();
void magicknight_skills();
void strider_skills();
void ranger_skills();
void assassin_skills();
void mage_skills();
void sorcerer_skills();
void magickarcher_skills();
} // namespace ddgm

#endif