#include "ex_16_17.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../My_Classes/Regular_hexagon.h"

#include <random>

void ex_16_17() {
    Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_16_17" };

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, 255);

    Graph_lib::Vector_ref<myGraph_lib::Regular_hexagon> vr;

    int cent_x{ 0 }, cent_y{ 25 }, rad{ 50 }, p{ 0 };
    int distr = pow(0.75, 0.5) * rad;
    bool flag{ true };

    for (int k{ cent_y }, i{ 0 }; i < win.y_max(); k += rad * 2 - pow(pow(rad, 2) - pow(distr, 2), 0.5), ++i) {
        for (int j = cent_x + p; j <= win.x_max(); j += distr * 2) {
            vr.push_back(new myGraph_lib::Regular_hexagon(Point{ j, k }, rad));
            vr[vr.size() - 1].set_color(Graph_lib::Color::invisible);
            vr[vr.size() - 1].set_fill_color(Graph_lib::Color(dist(mt)));
            win.attach(vr[vr.size() - 1]);
        }
        if (flag) {
            p += distr;
            flag = false;
        }
        else {
            p -= distr;
            flag = true;
        }
    }

    win.wait_for_button();
}