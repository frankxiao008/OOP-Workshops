#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "TaxableProduct.h"

namespace sict {

	TaxableProduct::TaxableProduct(const int productnum, const double productcost, char taxstatus) :Product(productnum, productcost) {
		taxtype = taxstatus;
	}

	double TaxableProduct::price() const {
		double taxrate = taxtype == 'H' ? HST : PST;
		return Product::price()*(1 + taxrate);
	}


	void TaxableProduct::display(std::ostream& os) const {
		Product::display(os);
		os << " " << (taxtype == 'H' ? "HST" : "PST");
	}

	//Read a record from the file
	iProduct* readRecord(std::ifstream& file) {
		iProduct* pro = nullptr;

		int num; double cost;
		file >> num >> cost;
		char code = file.get();
		if (code == ' ') {
			file >> code;
			if (code == 'H' || code == 'P') {
				pro = new TaxableProduct(num, cost, code);
			}
		}else {
			pro = new Product(num, cost);
		}

		return pro;
	}
}
