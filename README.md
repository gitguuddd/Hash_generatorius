# Hash_generatorius

---
## Link to the requirements of the task
[Hash-generator](https://github.com/blockchain-group/Blockchain-technologijos/blob/master/pratybos/1uzduotis-Hashavimas.md)
## Install instructions
1. Clone repository ```$ git clone https://github.com/gitguuddd/Hash_generatorius.git``` or ```$ git clone git@github.com:gitguuddd/Hash_generatorius.git``` if you're using SSH
1. cd to ```Hash_Generatorius``` main directory
2. Compile the program using CMakeLists.txt
3. If you'll want to read from a text file add the text file to build folder
4. Run the program (Hash_Gen.exe), follow the terms of use
---
## Terms of use

- If you plan to use input from an external file - add your file (name.txt) as the first command line argument after Hash_Gen.exe
- If you wish to use both input from command line arguments and external file YOU MUST separate the first argument (filename) after Hash_Gen.exe from other following arguments by the use of whitespace
- You can read the input file only once (for now)
- After you start the program you will be greeted with a menu that looks like this:
```Pasirinkite ka norite daryti
   1. Nuskaityti teksta nuo input.txt failo
   2. Sugeneruoti hash'a
   3. Baigti darba
   ``` 
- Choose the first option to read the input file
- Choose the second option to generate hash from input
- Choose the third option to close the program
---

## Pros of MindeHash

- Quite fast even when working with large texts (bee movie script - over 44000 chars long)
- The hash changes drastically even with minor alterations of inputs (there are exceptions ,check cons)
- Input size does not matter
- Output is always 64 chars long
- MindeHash is deterministic
- Very hard to decode because of several unique functions
---
## Cons of MindeHash

- Due to usage of placeholder chars (if input length is smaller than 6 chars or if it doesnt divide by 6) there is a minuscule chance of collusion
- Larger inputs often require bigger differences for eg 3-5 different chars from previous input
- To open a file you must close and open the program
---
## Changelog
[v0.1](https://github.com/gitguudddd/Hash_generatorius/releases/tag/v0.1) - (2019-09-25)

**Added**
- Initial functionality
- README file
 
