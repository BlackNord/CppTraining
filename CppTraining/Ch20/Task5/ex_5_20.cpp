#include "ex_5_20.h"
#include "MyVector.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

void ex_5_20() {
	MyVector<char> myVec;

	myVec.push_back('a');
	myVec.push_back('b');
	myVec.push_back('c');
	myVec.push_back('d');

	cout << myVec << endl;

	cin >> myVec;

	cout << myVec << endl;
}