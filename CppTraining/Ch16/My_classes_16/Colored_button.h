#pragma once
#include "../My_classes_16/My_window.h"
#include "../../Stroustruap_libs/GUI.h"

class Colored_button : public My_window {
private:
    Graph_lib::Vector_ref<Graph_lib::Rectangle> r;
    Graph_lib::Vector_ref<Graph_lib::Button> b;

    void setting(Graph_lib::Vector_ref<Graph_lib::Rectangle> &r, int index) {
        for (int i{ 0 }; i < r.size(); ++i) {
            r[i].set_color(Graph_lib::Color::dark_red);
            r[i].set_fill_color(Graph_lib::Color::dark_red);
        }
        r[index].set_color(Graph_lib::Color::green);
        r[index].set_fill_color(Graph_lib::Color::green);
    }
    void c_b1() {
        setting(r, 0);
        redraw();
    }
    void c_b2() {
        setting(r, 1);
        redraw();
    }
    void c_b3() {
        setting(r, 2);
        redraw();
    }
    void c_b4() {
        setting(r, 3);
        redraw();
    }
public:
    Colored_button(Point xy, int w, int h, const string& title) : My_window(xy, w, h, title) {
        b.push_back(new Graph_lib::Button{ Point{ x_max() / 2 - 50, y_max() / 2 - 50 }, 50, 50, "b1",
            [](Graph_lib::Address, Graph_lib::Address pw) {
                Graph_lib::reference_to<Colored_button>(pw).c_b1();
            }
        });
        r.push_back(new Graph_lib::Rectangle(Point{ x_max() / 2 - 50, y_max() / 2 - 50 }, 50, 50));
        b.push_back(new Graph_lib::Button{ Point{ x_max() / 2 + 50, y_max() / 2 - 50 }, 50, 50, "b2",
            [](Graph_lib::Address, Graph_lib::Address pw) {
                Graph_lib::reference_to<Colored_button>(pw).c_b2();
            }
        });
        r.push_back(new Graph_lib::Rectangle(Point{ x_max() / 2 + 50, y_max() / 2 - 50 }, 50, 50));
        b.push_back(new Graph_lib::Button{ Point{ x_max() / 2 - 50, y_max() / 2 + 50 }, 50, 50, "b3",
            [](Graph_lib::Address, Graph_lib::Address pw) {
                Graph_lib::reference_to<Colored_button>(pw).c_b3();
            }
        });
        r.push_back(new Graph_lib::Rectangle(Point{ x_max() / 2 - 50, y_max() / 2 + 50 }, 50, 50));
        b.push_back(new Graph_lib::Button { Point{ x_max() / 2 + 50, y_max() / 2 + 50 }, 50, 50, "b4",
            [](Graph_lib::Address, Graph_lib::Address pw) {
                Graph_lib::reference_to<Colored_button>(pw).c_b4();
             }
        });
        r.push_back(new Graph_lib::Rectangle(Point{ x_max() / 2 + 50, y_max() / 2 + 50 }, 50, 50));

        for (int i{ 0 }; i < r.size(); ++i) {
            r[i].set_color(Graph_lib::Color::dark_red);
            r[i].set_fill_color(Graph_lib::Color::dark_red);
            attach(r[i]);
        }

        for (int i{ 0 }; i < b.size(); ++i) {
            attach(b[i]);
        }
    }
};