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

int strcmp_18(const char* str1, const char* str2) {
	while (*str1 && *str2) {
		if (*str1 < *str2) return -1;
		if (*str1 > *str2) return 1;
		++str1; ++str2;
	}
	return *str1 ? -1 : *str2 ? 1 : 0;
}

void ex_1_4_18() {
	char first[] = { "Hello, world!" };
	char second[] = { "lo" };
	char third[] = { "wor" };
	char fourth[] = { "wore" };

	cout << find_x_18(first, second) << endl;
	cout << find_x_18(first, third) << endl;
	cout << find_x_18(first, fourth) << endl;

	cout << strcmp_18(first, second) << endl;
	cout << strcmp_18("lo", "lo") << endl;

	char str[] = { "Hello, World!" };
	cout << str << endl;
	char* temp = str_dup_18(str);
	cout << temp << endl;
	delete[] temp;

	//--

	char fake[1] = { '1' };
	char* fp = str_dup_18(fake);
	cout << fp << endl;
	delete[] fp;

	char not_fake[2] = { "2" };		// \0 - automatic
	char* nfp = str_dup_18(not_fake);
	cout << nfp << endl;
	delete[] nfp;
}