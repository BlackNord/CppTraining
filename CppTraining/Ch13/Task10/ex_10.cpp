#include "ex_10.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../My_Classes/Regular_polygon.h"

void ex_10() {
    Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_10" };

    myGraph_lib::Regular_polygon obj1(Point{ 730, 375 }, 8, 50);
    obj1.set_color(Graph_lib::Color::black);
    win.attach(obj1);

    win.wait_for_button();
}