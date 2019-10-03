//
// Created by Mindaugas K on 9/29/2019.
//

#ifndef HASH_GEN_DRIVEFUNCS_H
#define HASH_GEN_DRIVEFUNCS_H
#include <string>
#include <chrono>
#include <iostream>
#include <random>
#include <sstream>
#include <fstream>
#include <bitset>
#include "Timer.h"
#include "MindeHash.h"
#include "sha256.h"

extern Timer t;
#define S_LENGTH std::string::size_type
static std::string ranChrs = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
extern long long seed;
extern std::mt19937 mt;
extern std::uniform_int_distribution<S_LENGTH> dist;
extern std::uniform_int_distribution<int> dist2;
std::string random_string(S_LENGTH length);
char random_char();
std::string fileInput(const std::string &fName, bool &inputFailed);
void changeInput(std::string &input, const std::string &change);
void runTest(const std::string &loc, const std::string &name,  std::ofstream &fv);
void runSTests();
void konstitucija();
void SHACompare();
void wordCompare();
std::string  stringToBin(const std::string & a);
double bitCompare(const std::string & a, const std::string & b);
void bitTest();
#endif //HASH_GEN_DRIVEFUNCS_H
