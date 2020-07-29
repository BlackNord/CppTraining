#include "ex_1z_18.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"
#include "../../Ch17/Task1z/ex_1z_17.h"

int fact(int num) {
	if (num < 0) return 0; 
	if (num == 0) return 1; 
	else return num * fact(num - 1);
}

void f_a(int* arr, int arr_size) {
	int* p = new int[arr_size];

	for (int i{ 0 }; i < arr_size; ++i) {
		p[i] = arr[i];
	}

	print_array(cout, p, arr_size);

	delete[] p;
}

void f_v(const vector<int>& vec) {
	vector<int> lv;

	for (const auto& temp : vec) {
		lv.push_back(temp);
	}

	print_vector(lv);

	vector<int> lv2 = lv;

	print_vector(lv2);
}

void ex_1z_18() {
	int ga[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
	f_a(ga, 10);

	int la[10];
	for (int i{ 0 }; i < 10; ++i) {
		la[i] = fact(i);
	}
	f_a(la, 10);

	//--

	vector<int> gv = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
	f_v(gv);

	vector<int> vv;
	for (int i{ 0 }; i < 10; ++i) {
		vv.push_back(fact(i));
	}
	f_v(vv);
}