#ifndef DDGM_UTILITIES_HPP
#define DDGM_UTILITIES_HPP

#include "ddgm/enemies.hpp"
#include "ddgm/json.hpp"
#include "ddgm/skills.hpp"
#include <random>
#include <sys/types.h>
#include <vector>

namespace ddgm {

struct Player;
struct Pawn;

// Declaring the functions to load and save the datas
nlohmann::json load();
void save(Player player, Pawn pawn);

// Declaring a function that returns the
// percentage of a given number
uint percu(uint n, uint perc);

// Declaring a function that, given the start
//  and the end of a range, creates a random number
//  among that range
uint generateRandom(uint start, uint end);

// Declaring a function to check IF a number
// is contained in a range
bool isInRange(uint n, uint start, uint end);

// Declaring the function that calculates
// the probability of an event to happen
bool casuality(uint perc);

uint totalDmg(uint dmg, float multiplier);

uint check_skill(uint end);

int controllo_int();

bool search_skill(std::vector<Skill::SkillType> vector, Skill::SkillType skill);

bool find_skill(std::vector<Skill> skillsVector, Skill skillToFind);

void show_skills(std::vector<Skill> skills);

class Enemy;

bool search_enemy(std::vector<Enemy> enemies, Enemy enemy);
} // namespace ddgm

#endif