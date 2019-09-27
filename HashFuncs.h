//
// Created by Mindaugas K on 9/13/2019.
//

#ifndef HASH_GEN_HASHFUNCS_H
#define HASH_GEN_HASHFUNCS_H

#include <string>
#include <iomanip>
#include <sstream>
#include <cassert>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <locale>
#include <codecvt>
#include <vector>



std::string fileInput(std::ifstream &in);

std::string charToInt(std::string str);

void divideString(std::vector<int> &vect, std::string str);

void leftrotate(std::string &s, int d);

void rightrotate(std::string &s, int d);

void deNullnShift(std::string &s);

char charCompare(const char a, const char b);

template<typename T>
std::string toHex(const std::vector<T> &vect) {
    std::stringstream stream;
    stream << std::setfill('0') << std::setw(sizeof(T) * 2)
           << std::hex;
    for (int a:vect)
        stream << a;
    return stream.str();
}

#endif //HASH_GEN_HASHFUNCS_H
