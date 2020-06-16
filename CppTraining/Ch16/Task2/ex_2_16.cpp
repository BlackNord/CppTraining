#include "ex_2_16.h"
#include "../My_classes_16/Colored_button.h"

void ex_2_16() {
    Colored_button win{ Point{ 10,10 }, 600, 600, "ex_5" };
    win.wait_for_button();
}