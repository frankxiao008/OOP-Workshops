// Workshop 9 - Multi-Threading
// SecureData.cpp
// Chris Szalwinski after Cornel Barna
// modified by Saihong Xiao  140777178
// 2019/03/28

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace sict {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs) {
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key) {

		/*auto f = std::bind(converter, text, key, nbytes, Cryptor());

		std::thread t1(f);
		std::thread t2(f);*/
		thread t1(converter, text, key, nbytes, Cryptor());
		thread t2(converter, text, key, nbytes, Cryptor());


		encoded = !encoded;
		
		t1.join();
		t2.join();
		//converter(text, key, nbytes, Cryptor());
		
		
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			// TODO: open a binary file for writing
			ofstream myfile;
			myfile.open(file, ios::out | ios::binary);
			

			// TODO: write data into the binary file
			//         and close the file
			myfile.write(text, nbytes);
			text[nbytes - 1] = '\0';
			myfile.close();
			delete[] text;
			nbytes = 0;
			encoded = false;
		}
	}

	void SecureData::restore(const char* file, char key) {
		// TODO: open binary file for reading
		if (nbytes != 0) {
			delete[] text; nbytes = 0;
		}
		ifstream myfile(file, ios::in | ios::binary | ios::ate );

		// TODO: - allocate memory here for the file content
		
		nbytes = (int)myfile.tellg() + 1;
		text = new char[nbytes];

		// TODO: - read the content of the binary file
		myfile.seekg(0, ios::beg);
		myfile.read(text, nbytes);


		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
