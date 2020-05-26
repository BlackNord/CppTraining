#include "ex_4_14.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../My_Classes_14/Immobile_Circle.h"

using namespace std;

void ex_4_14() {
    Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_4_14" };

    myGraph_lib::Immobile_Circle c1(Point{ 100,100 }, 50);
    c1.set_color(Graph_lib::Color::black);
    c1.move(500, 500);              // don't work
    win.attach(c1);

    win.wait_for_button();
}