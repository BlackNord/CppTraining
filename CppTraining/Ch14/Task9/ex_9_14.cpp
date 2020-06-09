#include "ex_9_14.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../My_Classes_14/Chess_board.h"

void ex_9_14() {
    Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_9_14" };

    myGraph_lib::Chess_board obj1;
    auto team = myGraph_lib::Chess_board::team::white;
    obj1.move_left_checker(team, 8);
    obj1.move_right_checker(team, 4);
    win.attach(obj1);

    win.wait_for_button();
}