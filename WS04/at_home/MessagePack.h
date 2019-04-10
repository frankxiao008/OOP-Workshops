// Workshop 4 - Containers
// MessagePack.h
// Saihong Xiao
// 140777178
// sxiao15@myseneca.ca
// 2019/02/07

#ifndef SICT_MESSAGEPACK_H
#define SICT_MESSAGEPACK_H

#include "Message.h"

namespace sict {

	class MessagePack {
<<<<<<< HEAD
		Message** message=nullptr;
		size_t number=0;

	public:

		MessagePack();
		MessagePack( Message** ms, int num );
=======
		Message* message;

	public:
		MessagePack();
>>>>>>> 191f4c53c87b82fb772e8bc8bc95a0fc8d79117c
		MessagePack(const MessagePack&);
		MessagePack( MessagePack&&);
		MessagePack& operator = (const MessagePack&);
		MessagePack& operator = (MessagePack&&);
		~MessagePack();

		void display(std::ostream& os) const;
		size_t size() const;

	};

	std::ostream& operator<<(std::ostream& os, const MessagePack& msgpack);
}
#endif
