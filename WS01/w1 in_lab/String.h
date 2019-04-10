// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
//Student id: 140777178
//Name:		Saihong(Frank) Xiao
//Email:		sixao15@myseneca.ca
//Date:			2019/01/14
// String.h
#ifndef SICT_STR_H
#define SICT_STR_H

#include<iostream>

namespace sict {
	const int MAX = 3;
	class String {
		char code[MAX + 1];

	public:
		String();
		
		String(const char* s);
		
		void display(std::ostream& os) const;

	};

	std::ostream&operator<<(std::ostream& os, String& s);

}
	
#endif
