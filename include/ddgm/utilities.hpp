#ifndef DDGM_UTILITIES_HPP
#define DDGM_UTILITIES_HPP

// #include "ddgm/enemies.hpp"
#include "ddgm/json.hpp"
#include "ddgm/skills.hpp"
// #include "ddgm/items.hpp"
// #include <iostream>
// #include <random>
#include <sys/types.h>
#include <vector>

namespace ddgm {

struct Player;
struct Pawn;
struct Enemy;
struct Item;

// Declaring the functions to load and save the datas
nlohmann::json load();
void save(Player &player, Pawn &pawn);

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

// function to check if single element is in list
template <typename T> inline bool isIn(T src, std::vector<T> list) {
  for (T x : list)
    if (x == src)
      return 1;
  return 0;
}

// function to check if elements in a list are in another list
template <typename T>
inline bool isIn(std::vector<T> src, std::vector<T> list) {
  for (T x : list)
    for (T y : src)
      if (x == y)
        return 1;
  return 0;
}

inline bool isIn(std::string src,
                 std::vector<std::pair<std::string, uint>> vec) {
  for (uint i = 0; i < vec.size(); i++) {
    if (vec[i].first == src)
      return true;
  }
  return false;
}

bool is_enemy_in_list(std::vector<std::string> enemies_names,
                      std::vector<Enemy> enemies);

// Declaring the function that calculates
// the probability of an event to happen
bool casuality(uint perc);

uint totalDmg(uint dmg, float multiplier);

uint check_skill(uint end);

bool search_skill(std::vector<Skill::SkillType> vector, Skill::SkillType skill);

std::vector<std::pair<std::string, uint>>
normalize_inventory(const std::vector<Item> &player_inventory);

void choose_item(Player &player, Pawn &pawn, std::vector<Enemy> enemies);

void choose_item(Player &player, Pawn &pawn, Enemy &enemy);

bool find_skill(std::vector<Skill> skillsVector, Skill skillToFind);

void show_skills(std::vector<Skill> skills);

class Enemy;

bool search_enemy(std::vector<Enemy> enemies, Enemy enemy);
} // namespace ddgm

#endif