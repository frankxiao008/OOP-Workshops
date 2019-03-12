// Workshop 2 - Copy and Move Semantics
// TimeKeeper.cpp
// Saihong Xiao
// 140777178
// 2019/01/22
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include "TimeKeeper.h"
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
		for (int i = 0; i < recordNum; i++) {
			os << record[i].messAge;
			os << std::right << std::fixed << std::setw(6) << duration_cast<milliseconds>(record[i].dura).count() << " ";
			os << record[i].timeUnit << std::endl;
		}
	}
}