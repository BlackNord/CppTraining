#include "ex_8_14.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../My_Classes_14/Octagon.h"

using namespace std;

void ex_8_14() {
    Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_8_14" };

    myGraph_lib::Octagon o1(Point{ 200, 200 }, 50);
    o1.set_color(Graph_lib::Color::blue);
    win.attach(o1);

    myGraph_lib::Octagon o2(Point{ 700, 200 }, 60);
    o2.move(50, 50);
    o2.set_fill_color(o1.color());
    win.attach(o2);
    
    myGraph_lib::Octagon o3(Point{ 900, 200 }, 50);
    o3.set_color(o2.fill_color());
    win.attach(o3);

    win.wait_for_button();
}