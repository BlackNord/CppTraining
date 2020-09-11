#include "ex_1_19.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

template<typename T>
vector<T> f(const vector<T> & vec1, const vector<T>& vec2) {
	vector<T> temp;
	if (vec1.size() > vec2.size()) {
		temp = vec1;
		for (int i{ 0 }; i < vec2.size(); ++i) {
			temp[i] = vec1[i] + vec2[i];
		}
	}
	else {
		temp = vec2;
		for (int i{ 0 }; i < vec1.size(); ++i) {
			temp[i] = vec1[i] + vec2[i];
		}
	}
	return temp;
}

void ex_1_19() {
	vector<int> obj1 = { 1,2,3 };
	vector<int> obj2 = { 5,6,6,7,8 };
	vector<int> result = f<int>(obj1, obj2);

	for (auto k : result) {
		cout << k << " ";
	}

	cout << endl;
}