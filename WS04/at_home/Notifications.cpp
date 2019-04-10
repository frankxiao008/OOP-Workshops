// Workshop 4 - Containers
// Notifications.cpp
// Saihong Xiao
// 140777178
// sxiao15@myseneca.ca
// 2019/02/07


<<<<<<< HEAD

=======
>>>>>>> 191f4c53c87b82fb772e8bc8bc95a0fc8d79117c
#include "Notifications.h"

namespace sict {

<<<<<<< HEAD
	Notifications::Notifications() {
		msgptrptr= nullptr;
		Max = 0u;
		currentNum=0u;
	}
	Notifications::Notifications(int num) {
		if (num > 0) {
			msgptrptr = new const Message*[num];
			Max = num;
			currentNum = 0u;
		}
		else
			*this = Notifications();
	}

	Notifications::Notifications(const Notifications& notification) {
		*this = notification;

	}


	Notifications::Notifications( Notifications&& notification) {
		*this = std::move(notification);
	}
	
	Notifications& Notifications::operator=(const Notifications& notification) {
		if (this != &notification) {
			delete[] msgptrptr;
			Max = notification.Max;
			currentNum = notification.currentNum;
			msgptrptr = new const Message*[Max];
			for (size_t i = 0; i < Max; i++) {
				msgptrptr[i] = notification.msgptrptr[i];
			}		
		}
		return *this;
	}


	Notifications& Notifications::operator=(Notifications&& notification) {
		if (this != &notification) {
			delete[] msgptrptr;
			Max = notification.Max;
			currentNum = notification.currentNum;
			msgptrptr = notification.msgptrptr;
			notification.msgptrptr = nullptr;
			notification.Max = 0;
			notification.currentNum = 0;


		}
		return *this;

	}

	Notifications& Notifications::operator+=(const Message& msg) {
		if (currentNum < Max && !msg.empty()) {
			msgptrptr[currentNum++] = &msg;
		}
		return *this;
	}
	
	Notifications& Notifications::operator-=(const Message& msg) {
		bool found = false;
		size_t i;
		for (i=0 ; i < currentNum && !found; i++) {
			if (msgptrptr[i] == &msg)
				found = true;
		}
		for (; i < currentNum; i++)
			msgptrptr[i - 1] = msgptrptr[i];
		if (currentNum) {
			msgptrptr[currentNum - 1] = nullptr;
			currentNum--;
		}
		return *this;
	}
	

	void Notifications::diplay(std::ostream& os) const {
		for (size_t i = 0; i < currentNum; i++) {
			msgptrptr[i]->display(os);
		}
	}

	size_t Notifications::size() const {
		return currentNum;
	}


	std::ostream& operator<<(std::ostream& os, Notifications& notification) {
		notification.diplay(os);
		return os;
	}
=======
>>>>>>> 191f4c53c87b82fb772e8bc8bc95a0fc8d79117c
}