//Workshop 6-Sale.cpp
//Name:		Saihong Xiao
//Student ID:	140777178
//Email:		sxiao15@myseneca.ca
//



#include <iostream>
#include <fstream>
#include <iomanip>
#include "Sale.h"
#include "iProduct.h"



extern int FW;

namespace sict {
	

	Sale::Sale() :productvector {} {

	}

	Sale::Sale(const char* file) {

		std::ifstream fileSource(file);  

		//std::ifstream fileSource(file, std::ios::out);

		

		if (!fileSource.is_open())
			throw "fail to opem the file!";
		else {
			  while (!fileSource.eof()) {
				  productvector.push_back(readRecord(fileSource));
			  }

		}			
	
	}

	Sale::~Sale() {
		for (auto i : productvector)
			delete i;
	}

	void Sale::display(std::ostream& os)const {
		double total=0.0;
		std::cout << std::setw(FW) << "Product No" << std::setw(FW) << "Cost" << std::endl;
		for (auto i : productvector ) {
			if (!(i->empty())) {

				i->display(os);
				total += i->price();
			}
		};

	
		os << std::setw(FW) << "Total"  <<std::setprecision(2) <<std::setw(FW) <<total << std::endl;
		os.unsetf(std::ios::fixed);


	}
}