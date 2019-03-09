// Workshop 2 - Copy and Move Semantics
// TimeKeeper.cpp
// Chris Szalwinski
// 2019/01/22
#define _CRT_SECURE_NO_WARNINGS
#include "Timekeeper.h"
using namespace std::chrono;


namespace sict {

	
	Timekeeper::Timekeeper() :recordNum(0u),
		startTime(), endTime(), record{ nullptr }{}



	void Timekeeper::start() {
		startTime = std::chrono::steady_clock::now();

	}

	void Timekeeper::stop() {
		 endTime = std::chrono::steady_clock::now();
	}

	void Timekeeper::recordEvent(const char* des) {


		record[recordNum].messAge = des;
		record[recordNum].dura = endTime - startTime;
		record[recordNum].timeUnit = "seconds";
		recordNum++;


	}


	void Timekeeper::report(std::ostream& os)const {
		os << "Execution Times:" << std::endl;
		for (int i = 0; i < recordNum; i++)
			os << duration_cast<milliseconds>(record[recordNum].dura).count() << record[recordNum].timeUnit << std::endl;

	}
}