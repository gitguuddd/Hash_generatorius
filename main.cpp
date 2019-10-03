//
// Created by Mindaugas K on 9/13/2019.
//
#include "MindeHash.h"
#include "DriveFuncs.h"
#include <iostream>

int main(int argc, char *argv[]) {
    std::string input; //input string
    std::string check; //variable which holds the first argument (input file name)
    std::string change; // variable used to store input file name used in changeInput function
    std::string FILE="placeholder"; // input file name
    bool inputFailed=true; // successful input stream open flag
    int readCount = 0; // count for how many simultaneous times the current input file was read
    int choice = 0; // user menu choice
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

    while (choice == 0) {
        printf("Input string ilgis - %d\n", input.size());
        printf("Pasirinkite ka norite daryti \n");
        printf("1. Nuskaityti teksta nuo input failo \n");
        printf("2. Sugeneruoti hash'a \n");
        printf("3. Pakeisti input failo pavadinima \n ");
        printf("4. Mazu failu testai\n");
        printf("5. Konstitucijos testas\n");
        printf("6. SHA-256 ir MindeHash lyginimas\n");
        printf("7. MindeHash collision test \n");
        printf("8. MindeHash bit test \n");
        printf("9. Baigti darba \n");
        std::cin >>
                 choice;
        if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9) {
            do {
                std::cin.clear();
                std::cin.ignore(256, '\n');
                printf("Ivestas netinkamas pasirinkimas, bandykite is naujo\n");
                std::cin >>
                         choice;
            } while (choice != 1 && choice != 2 && choice != 3&& choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9);
        }

        switch (choice) {

            case 1:
                    input = fileInput(FILE,inputFailed);
                        if(inputFailed){
                        input.clear();
                        std::cout<<"Input failas nerastas/nepavyko jo atidaryti \n";
                        }
                    choice = 0;
                    break;

            case 2:
                MindeHash::genHash(input);
                MindeHash::clearKey();
                MindeHash::clearSumKey();
                std::cout << "Sugeneruotas Hash: " <<

                          MindeHash::getHash()

                          << "\n";
                choice = 0;
                break;
            case 3:
                std::cout <<"Iveskite naujo input failo pavadinima (su .txt galune): ";
                std::cin>>change;
                changeInput(FILE,change);
                choice=0;
                break;
            case 4:
                runSTests();
                choice=0;
                break;
            case 5:
                konstitucija();
                choice=0;
                break;
            case 6:
                SHACompare();
                return 0;
            case 7:
                wordCompare();
                choice=0;
                break;
            case 8:
                bitTest();
                choice=0;
                break;
            case 9:
                return 0;
            default:
                break;
        }

    }

}

