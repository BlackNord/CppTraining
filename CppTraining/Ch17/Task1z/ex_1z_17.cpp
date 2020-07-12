#include "ex_1z_17.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

void print_array(ostream& os, int* a, int n) {
	for (int i{ 0 }; i < n; ++i) {
		os << a[i] << " ";
	}
	os << endl;
}

void print_vector(const vector<int>& vec) {
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void ex_1z_17() {
	int* a = new int[10];

	for (int i{ 0 }; i < 10; ++i) {
		a[i] = i + 1;
	}

	print_array(cout, a, 10);

	delete[] a;

	vector<int> vec;

	for (int i{ 0 }; i < 10; ++i) {
		vec.push_back(i + 1);
	}

	print_vector(vec);

	int* p = new int(7);
	int** ptr_p;
	ptr_p = &p;

	cout << ptr_p << " " << *ptr_p << " " << **ptr_p << endl;

	delete p;

	int* arr1 = new int[7];
	for (int i{ 0 }; i < 7; ++i) {
		arr1[i] = i + 1;
	}

	int* arr2 = new int[7];
	for (int i{ 0 }; i < 7; ++i) {
		arr2[i] = i + 2;
	}

	print_array(cout, arr1, 7);
	print_array(cout, arr2, 7);

	int* temp = nullptr;
	temp = arr1;
	arr1 = arr2;
	arr2 = temp;

	print_array(cout, arr1, 7);
	print_array(cout, arr2, 7);

	delete[] arr1;
	delete[] arr2;
}