// Workshop 2 - Copy and Move Semantics
// Text.cpp
// Chris Szalwinski
// 2019/01/22
#include <fstream>
#include "Text.h"

namespace sict {
	//default constructor
	Text::Text(){
		m = 0u;
		fileName = '\0';
		strArray = nullptr;
	}



	//one argument constructor
	Text::Text(const char * t):m(0u), fileName(t) { 
	
		
		if (!fileName.empty()) {
			std::ifstream fin(fileName);

			while (fin.is_open()) {
				while (!fin.eof()) {
					std::string tep;
					std::getline(fin, tep);
					m++;
				}
				fin.clear();
				fin.seekg(0);
				strArray = new std::string[m];
				std::string line;
				for (auto i = 0u; i < m; i++) {
				
					std::getline(fin,strArray[i]);
				}
				fin.close();
			}
		}
		else {
			strArray = nullptr;
		}

	}
//Copy constructor
//
	Text::Text(const Text& t) {
		this->m = t.m;
		strArray = nullptr;
		*this = t;
	}




//Copy assignment operator
//
	Text& Text::operator=(const Text& t) {
		this->fileName = t.fileName;
		this->m = t.m;

		if (this != &t) {
			delete[] strArray;
			this->strArray = new std::string[m];
			for (auto i = 0u; i < m; i++)
				this->strArray[i] = t.strArray[i];
		}
		return *this;
	}

//destructor
//
	Text::~Text() {
		delete[] strArray;
	}

	//Query function return the number of records
	size_t Text::size() const {
		return m;
	}


}
