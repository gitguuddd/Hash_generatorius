//
// Created by Mindaugas K on 9/13/2019.
//

#ifndef HASH_GEN_HASHFUNCS_H
#define HASH_GEN_HASHFUNCS_H

#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>
#define DEFAULT_INPUT "da79bc151a0f3d87ba2ae91a33743075" //md5 salted hash with a salt of my exact birth date
#define CHARACTER_SET "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

std::string charToInt(const std::string &str);

void divideString(std::vector<int> &vect, std::string &str);

void leftRotate(std::string &s, int d);

void rightRotate(std::string &s, int d);

void deNullnShift(std::vector<std::string> &vect);

int fixRange(char a);

void convertRange(int oldMin, int oldMax, int newMin, int newMax, char &a);


std::string vectToString(const std::vector<std::string> & vect);

template<typename T>
std::vector<std::string> toHex(const std::vector<T> vect) {
    std::vector<std::string> ret;
    std::string out;
    std::stringstream stream;
    stream << std::setfill('0') << std::setw(sizeof(T) * 2)
           << std::hex;
    for (int a:vect) {
        stream << a;
        ret.push_back(stream.str());
        stream.clear();
        stream.str(std::string());
    }
    return ret;
}

#endif //HASH_GEN_HASHFUNCS_H
