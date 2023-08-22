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

// Declaring a function to check IF a number
// is contained in a range
bool isInRange(uint n, uint start, uint end);

// Declaring the function that calculates
// the probability of an event to happen
bool casuality(uint perc);

uint totalDmg(uint dmg, float multiplier);

uint check_skill(uint start, uint end);

} // namespace ddgm

#endif