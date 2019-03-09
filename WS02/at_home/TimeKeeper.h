// Workshop 2 - Copy and Move Semantics
// Timekeeper.h
// Saihong Xiao
// Saihong Xiao
// 140777178
// 2019/01/22

#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H
#include <chrono>
#include <string>
namespace sict { 
	const int MAX = 10;
	
	class Timekeeper {
		int recordNum;
		std::chrono::steady_clock::time_point startTime;    
			std::chrono::steady_clock::time_point endTime;    
	
		struct {
			 const char * messAge;
			 const char * timeUnit;
			std::chrono::steady_clock::duration dura;
		} record[MAX];
		
	public:
		Timekeeper();
		void start();
		void stop();
		void recordEvent(const char* des);
		void report(std::ostream& os)const;
	};
	
}

#endif