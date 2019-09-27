//
// Created by Mindaugas K on 9/13/2019.
//
#include "HashFuncs.h"
#include "MindeHash.h"
#include <iostream>

std::string MindeHash::m_string;
std::string MindeHash::m_hash;

std::string fileInput(std::ifstream &in) {
    std::stringstream sstr;
    sstr << in.rdbuf();
    return sstr.str();
}



std::string charToInt(std::string str) {
    std::string sub;
    for (const char a:str)
        sub += std::to_string(abs((int) a));
    return sub;
}

void divideString(std::vector<int> &vect, std::string str) {
    std::string sub;
    int len = str.length();
    if (str.length() < 6) {
        for (int i = 0; i < 6 - len; i++)
            str.append(std::to_string(i));
    } else if (str.length() % 6 != 0) {
        int mod = str.length() % 6;
        for (int i = 0; i < 6 - mod; i++)
            str.append(std::to_string(i));
    }
    for (int i = 0; i < str.length() / 6; i++) {
        sub = str.substr((uint8_t) (i * 6), 6);
        vect.push_back(std::stoi(sub));
    }
}

void leftrotate(std::string &s, int d) {
    reverse(s.begin(), s.begin() + d);
    reverse(s.begin() + d, s.end());
    reverse(s.begin(), s.end());
}

void rightrotate(std::string &s, int d) {
    leftrotate(s, s.length() - d);
}

void deNullnShift(std::string &s) {
    std::size_t pos;
    while (s.find('0') != std::string::npos) {
        pos = s.find('0');
        if (pos % 2 == 0) {
            s.erase(s.begin() + pos);
            rightrotate(s, pos);
        } else if (pos % 2 != 0) {
            s.erase(s.begin() + pos);
            leftrotate(s, pos);
        }
    }
}

char charCompare(const char a, const char b) {
    if (a < b)
        return b;
    else if (a >= b)
        return a;

}

void cutnCypher(std::string &s) {
    std::string key = s.substr(64);
    s.erase(64, key.length());
    int keyMult = 0;
    int trueIndex;
    for (int i = 0; i < key.length(); i++) {
        trueIndex = i - keyMult * 64;
        s[trueIndex] = static_cast<char>(((int) (s[trueIndex]) + (int) (key[i])) /
                                         2+((int)(s[trueIndex])%10+(int)(key[i])%10)); /*char is sum of the chars found in main hash and key*/
        /*s[trueIndex]=charCompare(s[trueIndex],key[i]); char is the returned char of charCompare between main hash and key*/
        std::abs((int) (s[trueIndex]) % 2) == 0 ? rightrotate(s, trueIndex) : leftrotate(s, trueIndex);
        keyMult = i / 64;
    }
    s.erase(std::remove(s.begin(), s.end(), '\\'), s.end());
    if (s.length() < 64) {
        MindeHash::genHash2();
    }

}


