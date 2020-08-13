#include "ex_11_18.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"
#include "skip_list.h"

void ex_11_18() {
    skiplst::skip_list l1(0.5, 5);
    
    for (int i{ 0 }; i < 5; ++i) {
        l1.insert(i, "test");
    }

    l1.print();
    cout << endl;

    l1.erase(4);

    l1.print();
    cout << endl;

    cout << l1.find(2) << endl;
}