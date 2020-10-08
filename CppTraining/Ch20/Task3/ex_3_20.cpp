#include "ex_3_20.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

bool isStrPalindrome(const string& str) {
	string newStr{ str };
	reverse(newStr.begin(), newStr.end());
	if (newStr != str)
		return false;
	return true;
}

bool isCStrPalindrome(const char str[], int n) {
	for (int i{ 0 }, k{ n - 1 }; i < n; ++i, --k) {
		if (str[i] != str[k])
			return false;
	}
	return true;
}

istream& readWord(istream& is, char* buffer, int max) {
	is.width(max);
	is >> buffer;
	return is;
}

bool isPStrPalindrome(const char* first, const char* last) {
	if (first < last) {
		if (*first != *last) 
			return false;
		return isPStrPalindrome(first + 1, last - 1);
	}
	return true;
}

void ex_3_20() {
	constexpr int SIZE{ 128 };

	// WARNING! Endless cycles for testing

	for (char str[SIZE]; readWord(cin, str, SIZE); ) {
		cout << str << " is";
		if (!isPStrPalindrome(&str[0], &str[strlen(str) - 1]))
			cout << " not";
		cout << " a palindrome\n";
	}

	for (char str[SIZE]; readWord(cin, str, SIZE); ) {
		cout << str << " is";
		if (!isCStrPalindrome(str, strlen(str)))
			cout << " not";
		cout << " a palindrome\n";
	}

	for (string str; cin >> str; ) {
		cout << str << " is";
		if(!isStrPalindrome(str))
			cout << " not";
		cout << " a palindrome\n";
	}
}