//
// Created by Mindaugas K on 9/13/2019.
//

#ifndef HASH_GEN_MINDEHASH_H
#define HASH_GEN_MINDEHASH_H

#include "HashFuncs.h"

void cutnCypher(std::string &s);

class MindeHash {
private:
    static std::string m_string;
    static std::string m_hash;

    static void genHash2() {
        std::vector<int> vect;
        m_hash = charToInt(m_hash);
        divideString(vect, m_hash);
        m_hash = toHex(vect);
        deNullnShift(m_hash);
        m_hash.length() >= 64 ? cutnCypher(m_hash) : genHash2();
    }

public:
    MindeHash() = delete;

    friend void cutnCypher(std::string &s);

    static void genHash() {
        std::vector<int> vect;
        m_hash = charToInt(m_string);
        divideString(vect, m_hash);
        m_hash = toHex(vect);
        deNullnShift(m_hash);
        m_hash.length() >= 64 ? cutnCypher(m_hash) : genHash2();
    }

    static void setString(std::string &input) {
        m_string = input;
    }

    static std::string getHash() {
        return m_hash;
    }

    static std::string getString() {
        return m_string;
    }
};

#endif //HASH_GEN_MINDEHASH_H
