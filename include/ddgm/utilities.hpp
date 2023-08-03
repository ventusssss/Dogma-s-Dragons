#ifndef DDGM_UTILITIES_HPP
#define DDGM_UTILITIES_HPP

#include <random>
#include <sys/types.h>

namespace ddgm {
// funzione per calcolare la percentuale
uint percu(uint n, uint perc);
bool casuality(uint perc);
int start_menu();
int game_menu();
void game_credits();
void game_introduction();
uint generateRandom(uint start, uint end);
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