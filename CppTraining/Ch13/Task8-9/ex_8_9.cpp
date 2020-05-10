#include "ex_8_9.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../My_Classes/Regular_hexagon.h"

void ex_8_9() {
    Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_8_9" };

    Graph_lib::Vector_ref<myGraph_lib::Regular_hexagon> vc;

    int cent_x{ 300 }, cent_y{ 300 }, rad{ 50 }, p{ 0 };
    int dist = pow(0.75, 0.5) * rad;
   
    for (int k{ cent_y }, i{ 0 }; i < 2; k += rad * 2 - pow(pow(rad, 2) - pow(dist, 2), 0.5), ++i) {
        for (int i = cent_x + p; i <= cent_x * 2; i += dist * 2) {
            vc.push_back(new myGraph_lib::Regular_hexagon(Point{ i, k }, rad));
            vc[vc.size() - 1].set_color(Graph_lib::Color::black);
            win.attach(vc[vc.size() - 1]);
        }
        p += dist;
    }

    win.wait_for_button();
}