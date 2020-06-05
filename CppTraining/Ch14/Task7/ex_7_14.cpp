#include "ex_7_14.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../My_Classes_14/Striped_closed_polyline.h"

using namespace std;

void ex_7_14() {
    Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_7_14" };

    myGraph_lib::Striped_closed_polyline p1;
    p1.add(Point{ 50, 50 });
    p1.add(Point{ 250, 200 });
    p1.add(Point{ 400, 180 });
    p1.add(Point{ 450, 100 });
    p1.set_striped(5);
    p1.set_color(Graph_lib::Color::black);
    win.attach(p1);

    win.wait_for_button();
}