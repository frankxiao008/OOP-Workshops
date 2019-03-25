// Workshop 4 - Containers
// Message.cpp
// Saihong Xiao
// 140777178
// sxiao15@myseneca.ca
// 2019/02/05


#include <iostream>
#include <string>
#include "Message.h"

namespace sict {

	//Defaultor constructor
	//
	Message::Message() :User(), Reply(), Tweet() {

	}
	//Constructor with one argument
	//
	Message::Message(const std::string& str) {
		std::size_t found = str.find(' ');
		if (found != std::string::npos) {
			User = str.substr(0, found);

			if (str.find('@', found + 1) == found + 1) {
				size_t length = str.find(' ', found + 2) - (found + 2);
				Reply = str.substr(found + 2, length);
				found = str.find(' ', found + 2);
			}

			Tweet = str.substr(found + 1);

		}
		else {
			*this = Message();
		}

	}
	// query function for the empty state of the Message object
	//
	bool Message::empty() const {
		return (User.empty() || Tweet.empty()) ? true : false;

	}
	//
	//
	void Message::display(std::ostream& os)const {
		if (!empty()) {
			os << "User  : " << User << std::endl;
			if (!Reply.empty())
				os << "Reply : " << Reply << std::endl;
			os << "Tweet : " << Tweet << std::endl;
		}
	}


}




