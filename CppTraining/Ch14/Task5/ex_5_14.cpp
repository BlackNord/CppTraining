#include "ex_5_14.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../My_Classes_14/Striped_rectangle.h"

using namespace std;

void ex_5_14() {
    Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_5_14" };

    myGraph_lib::Striped_rectangle obj1(Point{ 100,100 }, 200, 100);
    obj1.set_color(Graph_lib::Color::black);
    obj1.set_striped(4);
    win.attach(obj1);

    win.wait_for_button();
}