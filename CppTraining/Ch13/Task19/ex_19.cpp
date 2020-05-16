#include "ex_19.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../My_Classes/Star.h"

void ex_19() {
    Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_19" };

    myGraph_lib::Star s1{ Point{win.x_max()/2, win.y_max()/2}, 5 };
    s1.set_color(Graph_lib::Color::black);
    s1.set_fill_color(Graph_lib::Color::red);
    win.attach(s1);

    win.wait_for_button();
}