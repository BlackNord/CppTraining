#include "ex_5_20.h"
#include "MyVector.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

void ex_5_20() {
	MyVector<char> myVec1;

	myVec1.push_back('a');
	myVec1.push_back('b');
	myVec1.push_back('c');
	myVec1.push_back('d');

	std::cout << myVec1 << std::endl;

	std::cin >> myVec1;

	std::cout << myVec1 << std::endl;

	MyVector<char> myVec2;
	myVec2.push_back('n');

	myVec1 = myVec2;

	std::cout << myVec1 << std::endl;
}