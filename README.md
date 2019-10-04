# Hash_generatorius

---
## Link to the requirements of the task
[Hash-generator](https://github.com/blockchain-group/Blockchain-technologijos/blob/master/pratybos/1uzduotis-Hashavimas.md)
## Install instructions
1. Clone repository ```$ git clone https://github.com/gitguuddd/Hash_generatorius.git``` or ```$ git clone git@github.com:gitguuddd/Hash_generatorius.git``` if you're using SSH
1. cd to ```Hash_Generatorius``` main directory
2. Compile the program using CMakeLists.txt (cmake. , make)
3. cd to ```build``` folder
4. If you'll want to read from a text file add the text file to build folder
5. Start the program by running a line in this format ```./Hash_Gen.exe <Input file name.txt> <rest of arguments>...```, follow terms of use
---
## Terms of use

- If you plan to use input from an external file - add your file (name.txt) as the first command line argument after Hash_Gen.exe
- If you wish to use both input from command line arguments and external file YOU MUST separate the first argument (filename) after Hash_Gen.exe from other following arguments by the use of whitespace
- After you start the program you will be greeted with a menu that looks like this:
```Pasirinkite ka norite daryti
   1. Nuskaityti teksta nuo input failo
   2. Sugeneruoti hash'a
   3. Pakeisti input failo pavadinima
   4. Mazu failu testai
   5. Konstitucijos testas
   6. SHA-256 ir MindeHash lyginimas
   7. MindeHash collision test
   8. MindeHash bit test
   9. Baigti darba
   ``` 
- Choose the first option to read the input file or re-read a the current input file after modification
- Choose the second option to generate hash from input
- Choose the third option to change input file
- Choose the fourth option to run the first experimental test
- Choose the fifth option to run the second experimental test
- Choose the sixth option to run the advanced comparison of ```Mindehash``` and ```SHA256```
- Choose the seventh option to run the third experimental test
- Choose the eighth option to run the fourth experimental test
- Choose the ninth option to end the program
---

## Pros of MindeHash

- Quite fast even when working with large texts (bee movie script - over 44000 chars long)
- The hash changes drastically even with minor alterations of inputs (there are exceptions ,check cons)
- Input size does not matter
- Output is always 64 chars long
- MindeHash is deterministic
- Very hard to decode because of several unique functions
- No need to re-run the program to read different files, you can use menu functions instead
- Even small alterations will drastically alter the output of large inputs
---
## Cons of MindeHash

- Due to usage of placeholder chars (if input length is smaller than 6 chars or if it doesnt divide by 5) there is a minuscule chance of collusion
- When working with large inputs that differ in only 1 symbol the similarity ratio may jump from 0.4 to 0.8 and higher


---
## Experimental analysis and results of hash function comparison

- Documentation of the experimental research-analysis of ```MindeHash``` can be found [here](ANALYSIS.md)
- Results of ```MindeHash```'s battle in hash function comparisons can be found [here](https://github.com/dqmis/hashrank) and [here](https://github.com/AugustinasMK/TheHashRacer)

---
## Changelog
[v0.1.3](https://github.com/gitguuddd/Hash_generatorius/releases/tag/v0.1.3) - (2019-10-04)

**Added**
- Comments defining what each function does
- Advanced SHA256 - MindeHash comparison results in Analysis.md

**Changed**
- ```bitCompare```  function changed to calculate the ratios of difference instead of similarity
- Changed the results of bitWise test in Analysis.md according to the change mentioned above

---
[v0.1.2](https://github.com/gitguuddd/Hash_generatorius/releases/tag/v0.1.2) - (2019-10-03)

**Added**

- New drive functions used in the experimental-analysis of ```MindeHash```
- Analysis.md file

**Changed**
- README


---
[v0.1.1](https://github.com/gitguuddd/Hash_generatorius/releases/tag/v0.1.1) - (2019-10-01)

**Added**
- ```fixRange() and convertRange()``` functions for conversion of non-numeral and non-alphabetical characters
- ```m_pKey and m_sKey``` - precursor key and sum key - two keys generated from the initial input after it was converted to string of ascii codes, and code snippets that utilize these two keys to compress input in a meaningful way
- ```changeInput()``` - function created to change input file without restarting the program
- ```vectToString()``` function used to convert a vector to a string
- Some MindeHash.h member functions used to check the state of ```m_pKey and m_sKey``` and clear them if needed
- Default input used when empty input is given
- Comments near ambiguous/difficult parts of the code 

**Changed**

- ```deNullnShift()``` now works with a vector of quintuplets instead of one large string
- ```cutnCypher()``` has essentially become the cornerstone function of this hash after implementing both aforementioned keys as well as```fixRange() and convertRange()``` functions inside it
- Functions that are only responsible for ease of use of the algorithm have been moved to ```DriveFuncs.h and DriveFuncs.cpp``` files
- ```MindeHash``` class is now more self-reliable and can be used with minimal external code
- README

**Removed**

- ```charCompare()``` function
- Redundant getters and setters in ```MindeHash``` class
---
[v0.1](https://github.com/gitguuddd/Hash_generatorius/releases/tag/v0.1) - (2019-09-25)

**Added**
- Initial functionality
- README file
 
---
## Program structure
- ```HashFuncs.h and HashFuncs.cpp``` contain functions found in ```MindeHash``` class
- ```MindeHash.h``` contains main body of MindeHash class
- ```DriveFuncs.h and DriveFuncs.cpp``` contain helper functions for the ```MindeHash``` class
- ```sha256.h and sha256.cpp``` contain an implementation of sha256 hash function in c++. This implementation is used in advanced comparison of ```MindeHash``` and sha256
- ```Timer.h``` contains the timer class
