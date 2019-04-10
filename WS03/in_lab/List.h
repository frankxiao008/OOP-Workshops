

#define _CRT_SECURE_NO_WARNINGS

#ifndef SICT_LIST_H
#define SICT_LIST_H

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
			
					return a[i];
				
			}
			void operator+=(const T& t) {
				if (num < N) {

					a[num] = t;
					num++;
				}
			}

	};
}



#endif // !SICT_LIST_H
