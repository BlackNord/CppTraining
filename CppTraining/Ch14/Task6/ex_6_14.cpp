#include "ex_6_14.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../My_Classes_14/Striped_circle.h"

using namespace std;

void ex_6_14() {
    Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_6_14" };

    myGraph_lib::Striped_circle c1(Point{ 200, 200 }, 50);
    c1.set_striped(4);
    c1.set_color(Graph_lib::Color::black);
    win.attach(c1);

    win.wait_for_button();
}