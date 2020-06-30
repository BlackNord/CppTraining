#include "ex_7_16.h"
#include "../My_classes_16/Plane.h"

void ex_7_16() {
    Plane win{ Point{ 10,10 }, 1200, 600 };
    win.wait_for_button();
}