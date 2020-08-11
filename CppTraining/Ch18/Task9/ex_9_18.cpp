#include "ex_9_18.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

void stack_test() {
	cout << "Stack\n";
	int n{ 10 };
	char* stack = new char[n];

	for (int i{ 0 }; i < n; ++i) {
		stack[i] = 'w';
	}
	stack[n - 1] = '\0';

	for (int i{ 0 }; i < n; ++i) {
		cout << &stack + i << endl;
	}

	delete[] stack;
}

void static_test() {

}

void dynamic_test() {

}

void ex_9_18() {
	stack_test();
}