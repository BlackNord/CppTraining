#include "ex_3_16.h"
#include "../../Stroustruap_libs/GUI.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../My_classes_16/My_window_move.h"

void ex_3_16() {
    My_window_move win{ Point {20, 50 }, 1460, 750, "ex_3" };
    win.wait_for_button();
}