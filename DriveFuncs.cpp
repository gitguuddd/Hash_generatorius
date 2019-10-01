//
// Created by Mindaugas K on 9/29/2019.
#include "DriveFuncs.h"
#include "iostream"
std::string fileInput(const std::string &fName, bool &inputFailed) {
    std::ifstream fd(fName);
    if(!fd.fail())
        inputFailed= false;
    std::stringstream sstr;
    sstr << fd.rdbuf();
    return sstr.str();
}
void changeInput(std::string &input, const std::string &change){
    bool inputFailed = true;
    std::string temp=fileInput(change,inputFailed);
    if(!inputFailed)
    input=change;
    else
        std::cout<<"Nepavyko atidaryti "<<change<<" failo skaitymui \n";

}
//

