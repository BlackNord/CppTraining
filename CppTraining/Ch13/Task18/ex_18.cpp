#include "ex_18.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../My_Classes/Poly.h"

void ex_18() {
    using namespace myGraph_lib;
    Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_18" };

    Poly p1(mPoint{ 100, 150 }, mPoint{ 200, 280 }, mPoint{ 310, 300 }, mPoint{ -1, -1 });
    p1.set_color(Graph_lib::Color::black);
    win.attach(p1);

    win.wait_for_button();
}