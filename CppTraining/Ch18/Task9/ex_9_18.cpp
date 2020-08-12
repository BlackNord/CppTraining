#include "ex_9_18.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

void stack_test() {
	cout << "Stack\n";

	char stack[10];
	for (int i{ 0 }; i < 10; ++i) {
		stack[i] = 'w';
	}
	stack[9] = '\0';

	for (int i{ 0 }; i < 10; ++i) {
		cout << &stack + i << endl;
	}
}

void static_test() {
	cout << "Static\n";

	static char stat[10];
	for (int i{ 0 }; i < 10; ++i) {
		stat[i] = 'w';
	}
	stat[9] = '\0';

	for (int i{ 0 }; i < 10; ++i) {
		cout << &stat + i << endl;
	}
}

void dynamic_test() {
	cout << "Dynamic\n";

	int n{ 10 };
	char* dynamic = new char[n];

	for (int i{ 0 }; i < n; ++i) {
		dynamic[i] = 'w';
	}
	dynamic[n - 1] = '\0';

	for (int i{ 0 }; i < n; ++i) {
		cout << &dynamic + i << endl;
	}

	delete[] dynamic;
}

void ex_9_18() {
	stack_test();
	dynamic_test();
	static_test();
}