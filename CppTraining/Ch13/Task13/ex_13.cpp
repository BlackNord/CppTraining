#include "ex_13.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"

void ex_13() {
    Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_13" };

    Graph_lib::Vector_ref<Graph_lib::Rectangle> vr;
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            vr.push_back(new Graph_lib::Rectangle{ Point{i * 20, j * 20}, 20, 20 });
            vr[vr.size() - 1].set_fill_color(Graph_lib::Color{ i * 16 + j });
            vr[vr.size() - 1].set_color(Graph_lib::Color{ i * 16 + j });
            win.attach(vr[vr.size() - 1]);
        }
    }

    win.wait_for_button();
}