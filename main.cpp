//
// Created by Mindaugas K on 9/13/2019.
//
#include "MindeHash.h"
#include <iostream>

int main(int argc, char *argv[]) {
    std::string input;
    std::string check;
    std::string sub;
    std::string FILE="lol";
    bool inputFailed=true;
    int readcount = 0;
    int choice = 0;
    if (argc >= 2) {
        check = argv[1];
        if (check.find(".txt") != std::string::npos) {
            std::cout << "input failo vardas rastas \n";
            FILE = argv[1];
            if (argc > 2) {
                for (int i = 2; i < argc; i++)
                    input += argv[i];
            }
        } else {
            std::cout << "input failo vardas nerastas \n";
            for (int i = 1; i < argc; i++)
                input += argv[i];
        }
    } else {
        std::cout << " input failo vardas nerastas\n";
    }

    std::ifstream in;

    while (choice == 0) {
        printf("Input string ilgis (be tarpu) - %d\n", input.size());
        printf("Pasirinkite ka norite daryti \n");
        printf("1. Nuskaityti teksta nuo input.txt failo \n");
        printf("2. Sugeneruoti hash'a \n");
        printf("3. Baigti darba \n");
        std::cin >>
                 choice;
        if (choice != 1 && choice != 2 && choice != 3) {
            do {
                std::cin.clear();

                std::cin.ignore(256, '\n');
                printf("Ivestas netinkamas pasirinkimas, bandykite is naujo\n");
                std::cin >>
                         choice;
            } while (choice != 1 && choice != 2 && choice != 3);
        }

        switch (choice) {

            case 1:
                if (readcount == 0) {
                    try{
                        in.open(FILE);
                        inputFailed=false;
                    }
                    catch(...){
                        std::cout<<"Nerastas/nenurodytas input failas\n";
                        break;
                    }
                    if(!inputFailed){
                    input = fileInput(in);
                    choice = 0;
                    readcount++;
                    break;}
                } else {
                    std::cout << "Failas jau buvo perskaitytas \n";
                    choice = 0;
                    break;
                }
            case 2:
                if (input.

                        empty()

                        ) {
                    printf("Ivesties string'as negali buti tuscias \n");
                    choice = 0;
                    break;
                }
                MindeHash::setString(input);

                MindeHash::genHash();

                std::cout << "Sugeneruotas Hash: " <<

                          MindeHash::getHash()

                          << "\n";
                choice = 0;
                break;
            case 3:
                return 0;
            default:
                break;
        }

    }

}

