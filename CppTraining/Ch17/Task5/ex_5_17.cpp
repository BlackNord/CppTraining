#include "ex_5_17.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

int findx(const char* s, const char* x) {
	int begin{ 0 };

	int size_s{ 0 };
	for (; s[size_s] != '\0'; ++size_s);

	int size_x{ 0 };
	for (; x[size_x] != '\0'; ++size_x);

	for (int i{ 0 }; i != size_s; ++i) {
		for (int k{ 0 }; ; ++k) {
			begin = i;
			if (s[i + k] != x[k]) {
				break;
			}
			if (k == size_x-1) return begin;
		}
	}

	return -1;
}

int find_x(const char* s, const char* x) {
	for (int str{ 0 }; s[str]; ++str) {
		for (int ex{ 0 };; ++ex) {
			if (!x[ex]) return str; 
			if (s[str + ex] != x[ex]) break;
		}
	}
	return -1;
}

void ex_5_17() {
	char first[] = { "Hello, world!" };
	char second[] = { "lo" };
	char third[] = { "wor" };
	char fourth[] = { "wore" };

	cout << find_x(first, second) << endl;
	cout << find_x(first, third) << endl;
	cout << find_x(first, fourth) << endl;
}