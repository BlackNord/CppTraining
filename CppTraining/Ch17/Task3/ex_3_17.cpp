#include "ex_3_17.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

void to_lower(char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (*s == '\0')
            break;
        if (*s == ' ') {
            *s++;
        }
        if ((int)(*s) >= 65 and (int)(*s) <= 90) {
            *s = (char)((int)(*s) + 32);
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