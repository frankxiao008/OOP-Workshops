// Workshop 2 - Copy and Move Semantics
// Text.h
// Chris Szalwinski
// 2019/01/22

#ifndef SICT_TEXT_H
#define SICT_TEXT_H
#include <string>

namespace sict {
	class Text {
		size_t m;
		std::string fileName;
		std::string* strArray;
		

	public:
		Text();
		Text(const char* t);
		Text(const Text& t);
		Text & operator=(const Text & t);
		~Text();
		size_t size()const;
	};

}

#endif