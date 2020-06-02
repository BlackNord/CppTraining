#include "ex_15_14.h"
#include "../My_Classes_14/myIterator.h"

void ex_15_14() {
    vector<double> v_1 = { 1.1,2.2,3.3,4.4 };
    iterators::Vector_iterator vec_1(v_1);
    print(vec_1);

    list<double> l_1 = { 1.1,2.2,3.3,4.4 };
    iterators::List_iterator lst_1(l_1);
    print(lst_1);
}