// Workshop 5 - Functions
// w5.cpp
// Chris Szalwinski
// 2019/02/10

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "KVPair.h"
#include "KVList.h"
#include "Taxable.h"
using namespace sict;

float HST = 0.13f;
int fieldWidth = 10;

template <typename L, typename T, typename K, typename V>
L createList(char* filename) {
    std::ifstream file(filename);
    if (!file) {
		throw "Unable to open the file.";
        L list(0);
		
        return std::move(list);
        
    }
    
    
    int no_records = 0;
    do {
        char c = file.get();
        if (file.good() && c == '\n') no_records++;
    } while (!file.eof());
    file.clear();
    file.seekg(std::ios::beg);
    L list(no_records);
    do {
        K key;
        V value;
        file >> key;
        if (file) {
            file >> value;
            file.ignore();
            list.push_back(T(key, value));
        }
    } while (file);
    
    return std::move(list);
}

int main(int argc, char* argv[]) {
    std::cout << "Command Line : ";
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << ' ';
    }
    std::cout << std::endl;
    
    // check for command line errors
    if (argc != 3) {
        std::cerr << argv[0]  << ": missing file operand\n";
        exit(1);
    }
    
    // set for fixed, 2-decimal point output
    std::cout << std::fixed << std::setprecision(2);
    
    // process price list file
    try {
        KVList<KVPair<std::string, float>> priceList = createList<
        KVList<KVPair<std::string, float>>,
        KVPair<std::string, float>,
        std::string,
        float>
        (argv[1]);
        std::cout << "\nPrice List with G+S Taxes Included\n==================================\n";
        std::cout << "Description:      Price Price+Tax\n";
        priceList.display(std::cout, Taxable(HST));
        
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;


    }
    
    try {
        KVList<KVPair<int, float>> gradeList = createList<
        KVList<KVPair<int, float>>, KVPair<int, float>, int, float>(argv[2]);
        std::cout << "\nStudent List Letter Grades Included\n==================================\n";
        std::cout << "Student No :      Grade    Letter\n";
        
        auto gradeConvertor = [=](float grade)->std::string {
            std::string gradeletter;
            if (grade >= 90)
                gradeletter = "A+";
            else if (grade >= 85)
                gradeletter = "A ";
            else if (grade >= 80)
                gradeletter = "A-";
            else if (grade >= 77)
                gradeletter = "B+";
            else if (grade >= 73)
                gradeletter = "B ";
            else if (grade >= 70)
                gradeletter = "B-";
            else if (grade >= 67)
                gradeletter = "C+";
            else if (grade >= 63)
                gradeletter = "C ";
            else if (grade >= 60)
                gradeletter = "C-";
            else if (grade >= 55)
                gradeletter = "D+";
            else if (grade >= 50)
                gradeletter = "D ";
            else
                gradeletter = "F ";
            return gradeletter;
        };
        
        gradeList.display(std::cout, gradeConvertor);
    }
    catch (const char * msg) {
        std::cerr << msg << std::endl;
    }
    
    
}
