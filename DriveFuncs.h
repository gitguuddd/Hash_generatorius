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
std::string random_string(S_LENGTH length);// generates a random string with chars from ranChars charset
char random_char();// generates a random char from ranChars charset
std::string fileInput(const std::string &fName, bool &inputFailed);//reads the whole content of input file, checks if input file is valid
void changeInput(std::string &input, const std::string &change);// Changes the input file
void runTest(const std::string &loc, const std::string &name,  std::ofstream &fv);// performs a small file test
void runSTests();//uses runTest to run small file tests
void konstitucija();// separately hashes every line of konstitucija and prints out the average hashing time
void SHACompare();// Compare MindeHash and SHA256, prints out results - VERY LONG TEST (-+5.5 hours)
void wordCompare();// hashes two different inputs, compares the hashes, counts collisions
std::string  stringToBin(const std::string & a);// converts string to a binary string
double bitCompare(const std::string & a, const std::string & b);//uses stringToBin to convert two hashes to binary strings, compares the two binary strings, calculates difference ratio
void bitTest();// performs the bitwise test, uses bitCompare
#endif //HASH_GEN_DRIVEFUNCS_H
