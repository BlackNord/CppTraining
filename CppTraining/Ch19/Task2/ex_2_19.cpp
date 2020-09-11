#include "ex_2_19.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

template<typename T, typename U>
T sm(const vector<T>& vec1, const vector<U>& vec2) {
	T sum{ 0 };
	if (vec1.size() > vec2.size()) {
		int i{ 0 };
		for (; i < vec2.size(); ++i) {
			sum += vec1[i] * vec2[i];
		}

		for (; i < vec1.size(); ++i) {
			sum += vec1[i];
		}
	}
	else {
		int i{ 0 };
		for (; i < vec1.size(); ++i) {
			sum += vec1[i] * vec2[i];
		}

		for (; i < vec2.size(); ++i) {
			sum += vec2[i];
		}
	}
	return sum;
}

void ex_2_19() {
	vector<double> vec1 = { 1.1, 2.2, 3.3 };
	vector<int> vec2 = { 1, 2, 3, 4, 5};

	cout << sm(vec1, vec2) << endl;
}