#include "ex_9_14.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../My_Classes_14/Chess_board.h"

void ex_9_14() {
    Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_9_14" };

    myGraph_lib::Chess_board obj1;
    win.attach(obj1);

    win.wait_for_button();
}