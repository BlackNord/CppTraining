#include "ex_5_7_18.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

string cat_dog(const string& str1, const string& str2, const string& r) {
	return str1 + r + str2;
}

char* c_cat_dog(const char* str1, const char* str2, const char* r) {
	int size_1{ 0 };
	for (; str1[size_1]; ++size_1);

	int size_2{ 0 };
	for (; str2[size_2]; ++size_2);

	int size_r{ 0 };
	for (; r[size_r]; ++size_r);

	char* ns = new char[size_1 + size_2 + size_r + 1];

	int counter{ 0 };
	for (int i{ 0 }; i < size_1; ++i, ++counter) {
		ns[counter] = str1[i];
	}

	for (int i{ 0 }; i < size_r; ++i, ++counter) {
		ns[counter] = r[i];
	}

	for (int i{ 0 }; i < size_2; ++i, ++counter) {
		ns[counter] = str2[i];
	}
	ns[size_1 + size_2 + size_r] = '\0';

	return ns;
}

void ex_5_7_18() {
	cout << cat_dog("cat", "dog", "!") << endl;

	char* temp1 = c_cat_dog("one", "two", "+");
	cout << temp1 << endl;
	delete[] temp1;

	char* temp2 = c_cat_dog("all", "noone", "~");
	cout << temp2 << endl;
	delete[] temp2;
}