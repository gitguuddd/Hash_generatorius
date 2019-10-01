//
// Created by Mindaugas K on 9/29/2019.
//

#ifndef HASH_GEN_DRIVEFUNCS_H
#define HASH_GEN_DRIVEFUNCS_H
#include <string>
#include <sstream>
#include <fstream>
std::string fileInput(const std::string &fName, bool &inputFailed);
void changeInput(std::string &input, const std::string &change);
#endif //HASH_GEN_DRIVEFUNCS_H
