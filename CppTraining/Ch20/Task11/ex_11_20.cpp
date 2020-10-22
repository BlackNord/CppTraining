#include "ex_11_20.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

template<typename T>
void printVec(const vector<T>& vec) {
	for (const auto& k : vec) {
		cout << k << " ";
	}
	cout << endl;
}

void pullVec(vector<double>& vec) {
	for (int i{ 0 }; i < 10; ++i) {
		vec.push_back((double)i);
	}
}

void pullList(list<double>& list) {
	for (int i{ 10 }; i < 21; ++i) {
		list.push_back((double)i);
	}
}

void ex_11_20() {
	vector<double> myVec{};

	pullVec(myVec);

	printVec<double>(myVec);

	list<double> myList{};

	pullList(myList);

	copy(myList.begin(), myList.end(), std::back_inserter(myVec));

	printVec<double>(myVec);
}