#include "ex_15_20.h"
#include "pvector.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

void ex_15_20() {
    char* test1 = new char('c');

    cout << *test1 << endl;

    if (true) {     // for testing
        pvector<char*> obj;
        obj.push_back(test1);
        cout << *obj[0] << endl;
    }

    cout << *test1 << endl;
}