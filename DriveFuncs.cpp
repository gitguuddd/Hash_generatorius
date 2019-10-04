//
// Created by Mindaugas K on 9/29/2019.
#include "DriveFuncs.h"
Timer t;
long long seed=std::chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);
std::uniform_int_distribution<S_LENGTH> dist(0, ranChrs.length()-1);
std::uniform_int_distribution<int> dist2(0,4);
std::string random_string(S_LENGTH length){
    std::string s;
    s.reserve(length);
    while(length--)
        s+=ranChrs[dist(mt)];
    return s;

}
char random_char(){

    return ranChrs[dist(mt)];

}
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
void runTest(const std::string &loc, const std::string &name,  std::ofstream &fv){
    bool inputFailed=true;
    std::string s=fileInput(loc+name,inputFailed);
    if(inputFailed)
        std::cout<<"Ivestis is "<<name<<" nepavyko\n";
    else
    {
        MindeHash::genHash(s);
        MindeHash::clearSumKey();
        MindeHash::clearKey();
        fv<<"fileName: "<<name<<"  hash: "<<MindeHash::getHash()<<"\n";
    }
}
void runSTests(){
    std::ofstream fv("Output.txt");
    std::string location="../test_texts/";
    std::string fName="small1.txt";
    runTest(location,fName,fv);
    fName="small2.txt";
    runTest(location,fName,fv);
    fName="big1.txt";
    runTest(location,fName,fv);
    fName="big2.txt";
    runTest(location,fName,fv);
    fName="bigdiff1.txt";
    runTest(location,fName,fv);
    fName="bigdiff2.txt";
    runTest(location,fName,fv);
    fName="empty.txt";
    runTest(location,fName,fv);
}
void konstitucija(){
    std::string line;
    double sumTime=0;
    std::ifstream fd("../test_texts/konstitucija.txt");
    if(fd.fail())
        std::cout<<"Nepavyko perskaityti konstitucija.txt failo\n";
    else{
        while(std::getline(fd,line)){
            t.reset();
            MindeHash::genHash(line);
            sumTime+=t.elapsed();
            MindeHash::clearSumKey();
            MindeHash::clearKey();
        }
        std::cout<<"Konstitucijos eilutes suhashuotos per vidutiniskai "<<sumTime<<" s.\n";
    }

}
void SHACompare(){
    std::string s;
double sumT1=0;
double sumT2=0;
double sumT3=0;
double sumT4=0;
double SUMT=0;
double sumT12=0;
double sumT22=0;
double sumT32=0;
double sumT42=0;
double SUMT2=0;
for(int i=1;i<=100000;i++){
    s=random_string((unsigned int) i);
    t.reset();
    sha256(s);
    if(i<25000)
        sumT1+=t.elapsed();
    else if(i>=25000&&i<50000)
        sumT2+=t.elapsed();
    else if(i>=50000&&i<75000)
        sumT3+=t.elapsed();
    else if(i>=75000&&i<=100000)
        sumT4+=t.elapsed();
    SUMT+=t.elapsed();
    t.reset();
    MindeHash::genHash(s);
    if(i<25000)
        sumT12+=t.elapsed();
    else if(i>=25000&&i<50000)
        sumT22+=t.elapsed();
    else if(i>=50000&&i<75000)
        sumT32+=t.elapsed();
    else if(i>=75000&&i<=100000)
        sumT42+=t.elapsed();
    SUMT2+=t.elapsed();
    MindeHash::clearKey();
    MindeHash::clearSumKey();
    if(i%5000==0)
        std::cout<<"Iveikta "<<i/1000<<"%  testo \n";
}
std::ofstream fv("Lyginimo_Output.txt");
fv<<"0-25000 ilgio eilutes buvo vidutiniskai uzhashuotos per: sha256 - "<<sumT1/25000<<"s. MindeHash - "<<sumT12/25000<<"s.\n";
fv<<"25000-50000 ilgio eilutes buvo vidutiniskai uzhashuotos per: sha256 - "<<sumT2/25000<<"s. MindeHash - "<<sumT22/25000<<"s.\n";
fv<<"50000-75000 ilgio eilutes buvo vidutiniskai uzhashuotos per: sha256 - "<<sumT3/25000<<"s. MindeHash - "<<sumT32/25000<<"s.\n";
fv<<"75000-100000 ilgio eilutes buvo vidutiniskai uzhashuotos per: sha256 - "<<sumT4/25000<<"s. MindeHash - "<<sumT42/25000<<"s.\n";
fv<<"Testas su sha256 uztruko - "<<SUMT<<"s. testas su MindeHash uztruko - "<<SUMT2<<"s. \n";

}
void wordCompare(){
    int collisions =0;
    std::string a;
    std::string b;
    std::string ahash;
    std::string bhash;
    for(int i=1;i<=1000000;i++){
        a=random_string(5);
        b=random_string(5);
        MindeHash::genHash(a);
        ahash=MindeHash::getHash();
        MindeHash::clearSumKey();
        MindeHash::clearKey();
        MindeHash::genHash(b);
        bhash=MindeHash::getHash();
        MindeHash::clearSumKey();
        MindeHash::clearKey();
        if (ahash==bhash)
            collisions++;
        if(i%50000==0)
            std::cout<<"Iveikta "<<i/10000<<"%  testo \n";

    }
    std::cout<<"Total collisions : "<<collisions<<"\n";
}
std::string stringToBin(const std::string & a){
    std::string binaryString;
    for (char _char : a) {
        binaryString +=std::bitset<8>(_char).to_string();
    }
    return binaryString;
}
double bitCompare(const std::string & a, const std::string & b){
    double ratio=0;
    std::string aBin=stringToBin(a);
    std::string bBin=stringToBin(b);
    for(int i=0;i<aBin.length();i++){
        if(aBin[i]!=bBin[i])
            ratio++;
    }
    return ratio/aBin.length();

}
void bitTest(){
std::string a;
std::string b;
std::vector<double> ratios;
std::string ahash;
std::string bhash;
for(int i=1;i<=100000;i++){
    a=random_string(5);
    b=a;
    while(b==a)
        b[dist2(mt)]=random_char();
    MindeHash::genHash(a);
    ahash=MindeHash::getHash();
    MindeHash::clearSumKey();
    MindeHash::clearKey();
    MindeHash::genHash(b);
    bhash=MindeHash::getHash();
    MindeHash::clearSumKey();
    MindeHash::clearKey();
    ratios.push_back(bitCompare(ahash,bhash)*100);
    if(i%5000==0)
        std::cout<<"Iveikta "<<i/1000<<"% testo\n";
}
std::cout<<"Minimalus skirtingumas: "<<*std::min_element(ratios.begin(), ratios.end())<<"%\n";
std::cout<<"Maksimalus skirtingumas: "<<*std::max_element(ratios.begin(), ratios.end())<<"%\n";
std::cout<<"Vidutinis skirtingumas: "<<std::accumulate(ratios.begin(),ratios.end(),0.0)/ratios.size()<<"%\n";
}
//
