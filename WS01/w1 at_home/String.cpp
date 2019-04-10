// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
//Student id: 140777178
//Name:		Saihong(Frank) Xiao
//Email:		sixao15@myseneca.ca
//Date:			2019/01/14
//String.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "String.h"


extern const int INITIAL;

namespace sict {

	//The default constructor
	String::String() {
		code = nullptr;
	}

	//The one argument constructor function
	//
	String::String(const char * s) {
		if (s != nullptr) {		
			code = new char[strlen(s)+1];
			strcpy(code, s);
			
		}
		else {
			code = nullptr;
		}

	}

	//The destructor function
	//
	String::~String() {
		delete[] code;
	}


	//The display function for String class
	//
	void String::display(std::ostream& os) const {
		os << code;
	}


	//The helper function
	//
	std::ostream& operator<<(std::ostream& os, String& s) {
		static int itemno = INITIAL;
		std::cout << itemno << ": ";
		s.display(os);
		itemno++;
		
		return os;

	}



}
