//Workshop 6-Product.h
//Name:		Saihong Xiao
//Student ID:	140777178
//Email:		sxiao15@myseneca.ca
//

#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H

#include "iProduct.h"
namespace sict {

	class Product :public iProduct {
		int productNum;
		double itemPrice;
	public:
		Product();
		Product(const int, const double);
		double price() const;
		bool empty() const;
		void display(std::ostream& os) const;
		~Product();
	};
}

#endif // !SICT_PRODUCT_H
