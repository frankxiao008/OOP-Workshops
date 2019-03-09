//Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface.
//Student id: 140777178
//Name:		Saihong(Frank) Xiao
//Email:		sixao15@myseneca.ca
//Date:			2019/01/14
// w1.cpp

#include "process.h"
#include "String.h"

using namespace sict;
extern const int INITIAL =3;

	int main(int argc, char *argv[]) {

		int return_value = 0;
		
		if (argc >1 ) {
			std::cout << "Command Line : ";
			std::cout << argv[0] <<" "<<argv[1]<<" "<<argv[2]<<" " << std::endl;

			for (int i = 1; i < argc; i++)
				process(argv[i]);
		}
		else {
			std::cout << "***Insufficient number of arguments***" <<std::endl;
			return_value= 1;
		}
		
		return return_value;
	}



