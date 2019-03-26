// Workshop 4 - Containers
// Message.h
// Saihong Xiao
// 140777178
// sxiao15@myseneca.ca
// 2019/02/05

#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H
#include <string>

namespace sict {
	class Message {
		std::string User;
		std::string Reply;
		std::string Tweet;
	public:
		Message();
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os)const;


	};
	
}


#endif // !SICT_MESSAGE_H


