#include "ex_14_20.h"
#include "MyList.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

void ex_14_20() {
    MyList<int> A(3);

    A.input();
    A.input();
    A.input();

    A.popEnd();
    A.popFront();
    
    MyList<int> B = A;
    MyList<int> C(B);

    C.print();
    cout << C[0] << endl;
}