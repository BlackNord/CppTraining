#include "ex_10_18.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

bool is_palindrom_c(const char s[], int n) {
	for (int i{ 0 }, k{ n - 1 }; i < n; ++i, --k) {
		if (s[i] != s[k]) return false;
	}
	return true;
}

void ex_10_18() {
	constexpr int max = 128;

	for (char s[max+2]; fgets(s, max+2, stdin); ) {		// +2 for '\0' and for one control-searching symbol
		if (static_cast<int>(strlen(s)) > max) {
			cout << "Error: out of range\n";
			return;
		}
		else {
			cout << " is";
			if (!is_palindrom_c(s, strlen(s)-1)) cout << " not";	// -1 "put off" '\0'
			cout << " a palindrome\n";
		}
	}
}