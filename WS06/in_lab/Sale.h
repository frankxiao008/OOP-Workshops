//Workshop 6-Sale.h
//Name:		Saihong Xiao
//Student ID:	140777178
//Email:		sxiao15@myseneca.ca
//


#ifndef SICT_SALE_H
#define SICT_SALE_H
#include <vector>
#include "iProduct.h"

namespace sict {

	class Sale {

		std::vector<iProduct*> productvector;
	public:
		Sale();
		Sale(const char* file);
		~Sale();
		void display(std::ostream& os)const;
	};
}

#endif // !SICT_SALE_H