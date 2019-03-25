// Workshop 4 - Containers
// Notifications.h
// Saihong Xiao
// 140777178
// sxiao15@myseneca.ca
// 2019/02/07


#ifndef SICT_NOTIFY_H
#define SICT_NOTIFY_H

#include"Message.h"
namespace sict {
	class Notifications {
	
		const Message** msgptrptr=nullptr;
		size_t Max = 0u;
		size_t currentNum = 0u;
	public:
		Notifications();
		Notifications(int num);
		Notifications(const Notifications&);
		Notifications(Notifications&& );
		Notifications& operator=(const Notifications&);
		Notifications& operator=(Notifications&&);
		Notifications& operator+=(const Message& msg);
		Notifications& operator-=(const Message& msg);
		void diplay(std::ostream& os) const;
		size_t size() const;

	};
	std::ostream& operator<<(std::ostream&, Notifications&);


}
#endif


