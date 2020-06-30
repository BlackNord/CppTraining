#include "ex_6_16.h"
#include "../My_classes_16/Clock.h"

void ex_6_16() {
    Clock cl1(Point{ 10,10 });
    cl1.wait_for_button();
}