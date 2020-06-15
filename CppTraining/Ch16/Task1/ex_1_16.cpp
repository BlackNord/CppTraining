#include "ex_1_16.h"
#include "../../Stroustruap_libs/GUI.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../My_classes_16/My_window.h"

void ex_1_16() {
    My_window win{ Point{ 10,10 }, 600, 600, "ex_1" };
    win.wait_for_button();
}