#include "ex_4_17.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

char* str_dup(const char* s) {
	int size{ 0 };
	for (; s[size]; ++size);

	char* n = new char[size + 1];

	int i{ 0 };
	for (; i < size; ++i) {
		n[i] = s[i];
	}
	n[size] = '\0';

	return n;
}

void ex_4_17() {
	char str[] = { "Hello, World!" };
	cout << str << endl;
	cout << str_dup(str) << endl;
}