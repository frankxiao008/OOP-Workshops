
#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H
#include <iostream>

namespace sict {
	template<typename L, typename V >
		class LVPair {
		
			L Lable;
			V Value;
		
	public:
		LVPair(): Lable(), Value(){  }

		LVPair(const L& label, const V& value) {
			Lable = label;
			Value = value;
		}
		
		void display(std::ostream& os) const {
			os << Lable << " : " << Value << std::endl;
		}

		

	};
	
	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}
}

#endif // !SICT_LIST_H
