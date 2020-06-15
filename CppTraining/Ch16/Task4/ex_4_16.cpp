#include "ex_4_16.h"
#include "../My_classes_16/GraphMenu.h"

void ex_4_16() {
    GraphMenu win{ Point {20, 50 }, 1460, 750, "ex_4" };
    win.wait_for_button();
}