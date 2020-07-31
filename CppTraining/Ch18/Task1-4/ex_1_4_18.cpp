#include "ex_1_4_18.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

char* str_dup_18(const char* s) {
	int size{ 0 };
	for (; *(s+size); ++size);

	char* n = new char[size + 1];

	int i{ 0 };
	for (; i < size; ++i) {
		*(n+i) = *(s+i);
	}
	*(n+size) = '\0';

	return n;
}

int find_x_18(const char* s, const char* x) {
	for (int str{ 0 }; *(s + str); ++str) {
		for (int ex{ 0 };; ++ex) {
			if (!*(x + ex)) return str;
			if (*(s + str + ex) != *(x + ex)) break;
		}
	}
	return -1;
}

void ex_1_4_18() {
	char first[] = { "Hello, world!" };
	char second[] = { "lo" };
	char third[] = { "wor" };
	char fourth[] = { "wore" };

	cout << find_x_18(first, second) << endl;
	cout << find_x_18(first, third) << endl;
	cout << find_x_18(first, fourth) << endl;

	char str[] = { "Hello, World!" };
	cout << str << endl;
	cout << str_dup_18(str) << endl;
}