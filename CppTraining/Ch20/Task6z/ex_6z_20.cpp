#include "ex_6z_20.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

template <typename Iter1, typename Iter2>
Iter2 myCopy(Iter1 f1, Iter1 e1, Iter2 f2) {
	if (f1 == e1) {
		error("List is empty");
	}

	Iter2 f = f2;

	for (Iter1 i = f1; i != e1; ++i, ++f) {
		*f = *i;
	}

	return f2;
}

void ex_6z_20() {
	vector<int> vec = { 1,3,2,4,5 };
	int arr[5] = { 0 };

	myCopy(vec.begin(), vec.end(), arr);

	for (const auto& k : arr) {
		cout << k << ' ';
	}
	cout << endl;

	vector<int>::iterator it = find(vec.begin(), vec.end(), 3);

	auto position = std::distance(vec.begin(), it);

	if (it != vec.end())
		cout << "Element is found in vector: " << *it << " with position " << position << endl;
	else
		cout << "Element is not found in vector" << endl;

}