#include "ex_5_16.h"
#include "../My_classes_16/MoveFigure.h"

void ex_5_16() {
    MoveFigure win{ Point{ 10,10 }, 600, 600, "ex_5" };
    win.wait_for_button();
}