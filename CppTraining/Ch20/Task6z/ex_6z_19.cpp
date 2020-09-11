#include "ex_6z_19.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

template <typename Iter1, typename Iter2>
Iter2 mcopy(Iter1 f1, Iter1 e1, Iter2 f2) {
	if (f1 == e1){
		error("List is empty");
	}
	Iter2 j = f2;
	for (Iter1 i = f1; i != e1; ++i, ++j) {
		*j = *i;
	}
	return f2;
}

void ex_6z_19() {
	vector<int> obj1 = { 1,2,3,4,5 };
	int arr[5] = { 0 };

	mcopy(obj1.begin(), obj1.end(), arr);

	for (auto k : arr) {
		cout << k << ' ';
	}
	cout << endl;
}