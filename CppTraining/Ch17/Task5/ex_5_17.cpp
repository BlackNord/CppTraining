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

void ex_5_17() {
	char first[] = { "Hello, world!" };
	char second[] = { "lo" };
	char third[] = { "wor" };
	char fourth[] = { "wore" };

	cout << findx(first, second) << endl;
	cout << findx(first, third) << endl;
	cout << findx(first, fourth) << endl;
}