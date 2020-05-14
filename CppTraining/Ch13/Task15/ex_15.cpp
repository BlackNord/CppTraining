#include "ex_15.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../My_Classes/Right_triangle.h"

#include <random>

void ex_15() {
    Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_15" };

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, 255);

    Graph_lib::Vector_ref<myGraph_lib::Right_triangle> vr;

    for (int y{ 0 }; y < win.y_max(); y += 50) {
        for (int x{ 0 }; x < win.x_max(); x += 50) {
            vr.push_back(new myGraph_lib::Right_triangle(Point{ 0 + x, 50 + y }, 50, 50));
            vr.push_back(new myGraph_lib::Right_triangle(Point{ 50 + x, 0 + y }, -50, -50));

            vr[vr.size() - 1].set_color(Graph_lib::Color::invisible);
            vr[vr.size() - 1].set_fill_color(Graph_lib::Color(dist(mt)));
            win.attach(vr[vr.size() - 1]);

            vr[vr.size() - 2].set_color(Graph_lib::Color::invisible);
            vr[vr.size() - 2].set_fill_color(Graph_lib::Color(dist(mt)));
            win.attach(vr[vr.size() - 2]);
        }
    }

    win.wait_for_button();
}