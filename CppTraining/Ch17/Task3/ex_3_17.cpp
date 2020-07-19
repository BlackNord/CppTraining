#include "ex_3_17.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

void to_lower(char* s) {
    while (true) {
        if (*s == '\0')
            break;
        if (*s >= 'A' and *s <= 'Z') {
            *s = *s + ('a' - 'A');
        }
        *s++;
    }
}

void ex_3_17() {
	char str[] = { "HelLo, World!" };
	cout << str << endl;
	to_lower(str);
	cout << str << endl;
}