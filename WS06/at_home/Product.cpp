//Workshop 6-Product.cpp
//Name:		Saihong Xiao
//Student ID:	140777178
//Email:		sxiao15@myseneca.ca


#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "Product.h"

extern int FW;


namespace sict {
	

	Product::Product() :productNum{ 0 }, itemPrice{0}{
		
	}

	Product::Product(const int num, const double p) {
		if (num > 0 && p >= 0) {
		productNum= num;
		itemPrice = p;
		}
		else {
			*this = Product();
		}
	}

	double Product::price() const {
		return itemPrice;
	}


	bool Product::empty()const {
		return productNum == 0 ? true : false;			
	}

	Product::~Product() {

	}
	//
	void Product::display(std::ostream& os) const {
		
	//	os << std::ios::fixed << std::setprecision(2);
		os << std::setw(FW) << productNum;
		os.setf(std::ios::fixed);
		os.precision(2); 
		os<<std::setw(FW) << itemPrice ;
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& p) {
		p.display(os);
		return os;
	}

	//iProduct* readRecord(std::ifstream& file) {
 //  
	//	iProduct* pro = nullptr;
	//if (file.is_open()) {
	//
	//		int num; double cost;
	//		file >> num >> cost;
	//		pro = new Product(num, cost);

	//	}
	//	else {
	//		std::string error = "The file object is not in a good condition";
	//		throw error;
	//	}
	//		
	//	return pro;
	//}

}