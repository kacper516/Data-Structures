#pragma once

#include <iostream>
#include <math.h>

/// @brief This function will use native string matching algorithm to search for pattern
/// @param T string with text
/// @param p string with pattern we search for
void naiveStringMatching(std::string T, std::string p);

/// @brief Helping function for Rabin Karp algorithm
/// @param p string with pattern we search for
/// @param T string with text
/// @param s shift value
/// @return true if we find pattern in this part of text
bool compare(std::string p, std::string T, int s);

/// @brief This function will use Rabin Karp algorithm to search for pattern
/// @param T string with text
/// @param p string with pattern we search for
void RabinKarp(std::string T, std::string p);

/// @brief This function will use Boyer Moore algorithm to search for pattern
/// @param T string with text
/// @param p string with pattern we search for
void BoyerMoore(std::string T, std::string p);
