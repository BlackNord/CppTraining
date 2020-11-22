#include "ex_16_20.h"
#include "ovector.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

void ex_16_20() {
    char* test1 = new char('c');

    ovector<char*> obj;
    obj.push_back(test1);

    cout << obj[0] << endl;
}