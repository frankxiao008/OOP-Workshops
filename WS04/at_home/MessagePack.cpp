// Workshop 4 - Containers
// MessagePack.cpp
// Saihong Xiao
// 140777178
// sxiao15@myseneca.ca
// 2019/02/05

<<<<<<< HEAD
#include <utility>
#include "MessagePack.h"

namespace sict {
	//default constructor
	//
	MessagePack::MessagePack() {
		number = 0;
		message = nullptr;
	}
	//The two parameters constructor
	//
	MessagePack::MessagePack( Message** ms, int num) {
		number = 0;
		if (num >= 0 && ms != nullptr) {
			message = new Message* [num];
			for (int i = 0; i < num; i++) {
				if (!ms[i]->empty()) {
					//message[i] = const_cast<Message*>(ms[i]);
					message[number] = new Message;
					*message[number] = *ms[i];
					number++;
				}
			}
		/*	for (int i = number - 1; i < num; i++)
				message[i] = nullptr;*/
		}
		else {
			*this = MessagePack();
		}

	}
	// copy constructor
	//
	MessagePack::MessagePack(const MessagePack& msgpack) {
		*this = msgpack;
	}
	//move constructor
	//
	MessagePack::MessagePack(MessagePack&& msgpack) {
		*this = std::move(msgpack);
	}
	//assignment operator
	//
	MessagePack& MessagePack:: operator = (const MessagePack& msgpack) {
		if (this != &msgpack) {
			for(size_t i=0; i<number; i++)
			delete message[i];
			delete[] message;
			number = msgpack.number;
			message = new Message*[number];

			for (size_t i = 0; i < number; i++) {
				message[i] = new Message;	
				*(message[i]) = *(msgpack.message[i]);
			}
		}
		return *this;
	}
	//move-assignment operator
	//
	MessagePack& MessagePack::operator = (MessagePack&& msgpack) {
		if (this != &msgpack) {
			delete[] message;
			number = msgpack.number;
			message = msgpack.message;
			msgpack.number = 0;
			msgpack.message = nullptr;
		}
		return *this;
	}
	//destructor
	//
	MessagePack::~MessagePack() {
		delete[] message;
	}
	//Display functoin
	//
	void MessagePack::display(std::ostream& os) const {
		for (size_t i = 0; i < number; i++) {
			message[i]->display(os);
		}
	}
	//return the number of message objects
	//
	size_t MessagePack::size() const {
		return number;
	}
	//No-friend output helper function
	//
	std::ostream& operator<<(std::ostream& os, const MessagePack& msgpack) {
		msgpack.display(os);
		return  os;
	}
	
=======
#include "MessagePack.h"

namespace sict {

>>>>>>> 191f4c53c87b82fb772e8bc8bc95a0fc8d79117c
}
