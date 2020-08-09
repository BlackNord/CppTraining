#include "ex_8_18.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

bool is_palindrome_s(const string& str) {
	string temp{ str };
	reverse(temp.begin(), temp.end());
	if (temp != str) return false;
	return true;
} 

bool is_palindrome_c(const char s[], int n) {
	for (int i{ 0 }, k{ n-1 }; i < n; ++i, --k) {
		if (s[i] != s[k]) return false;
	}
	return true;
}
istream& read_word(istream& is, char* buffer, int max) {
	is.width(max); 
	is >> buffer; 
	return is;
}

bool is_palindrome_p(const char* first, const char* last) {
	if (first < last) {
		if (*first != *last) return false;
		return is_palindrome_p(first + 1, last - 1);
	}
	return true;
}

void ex_8_18() {
	constexpr int max = 128;

	for (char s[max]; read_word(cin, s, max); ) {
		cout << s << " is";
		if (!is_palindrome_p(&s[0] ,&s[strlen(s) - 1])) cout << " not";
		cout << " a palindrome\n";
	}
	 
	/*for (char s[max]; read_word(cin, s, max); ) {
		cout << s << " is";
		if (!is_palindrome_c(s, strlen(s))) cout << " not";
		cout << " a palindrome\n";
	}*/

	/*for (string s; cin >> s; ) {
		cout << s << " is";
		if(!is_palindrome_s(s)) cout << " not";
		cout << " a palindrome\n";
	}*/
}