// Workshop  - tempplate
// List.h
// Saihong Xiao
// 140777178
// 2019/02/02




#ifndef SICT_LIST_H
#define SICT_LIST_H
#include "LVPair.h"

namespace sict {
	template <typename T, size_t N>
		class List {
			size_t num=0;
			T a[N];
		public:
			size_t size()const {
				return num;
			}

			const T& operator[](size_t i)const {
				//if (i < N)
					return a[i];
				
			}
			void operator+=(const T& t) {
				if (num < N) {

					a[num] = t;
					num++;
				}
			}
	};

	//template for the lVList derived class
	//
	template<typename T, typename L, typename V, size_t N>
	class LVList : public List<T, N> {
		
	public:
		V accumulate(const L& label) const {
			
			V SumValue = SummableLVPair<L, V>::getInitialValue();				
				for(size_t i=0; i<((List<T, N>&)*this).size(); i++){
					SumValue =(*this)[i].sum(label, SumValue);
				}		
			return SumValue;
		}		
	};

}



#endif // !SICT_LIST_H
