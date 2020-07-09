#pragma once
#include "../My_classes_16/My_window.h"
#include "../../Stroustruap_libs/GUI.h"

class Colored_button : public My_window {
private:
    Graph_lib::Button b1;
    Graph_lib::Button b2;
    Graph_lib::Button b3;
    Graph_lib::Button b4;

    Graph_lib::Rectangle r1;
    Graph_lib::Rectangle r2;
    Graph_lib::Rectangle r3;
    Graph_lib::Rectangle r4;

    void set_one(Graph_lib::Rectangle &obj) {
        obj.set_color(Graph_lib::Color::green);
        obj.set_fill_color(Graph_lib::Color::green);
    }
    void set_all(Graph_lib::Rectangle& obj1, Graph_lib::Rectangle& obj2, Graph_lib::Rectangle& obj3) {
        obj1.set_color(Graph_lib::Color::dark_red);
        obj1.set_fill_color(Graph_lib::Color::dark_red);
        obj2.set_color(Graph_lib::Color::dark_red);
        obj2.set_fill_color(Graph_lib::Color::dark_red);
        obj3.set_color(Graph_lib::Color::dark_red);
        obj3.set_fill_color(Graph_lib::Color::dark_red);
    }
    void c_b1() {
        set_one(r1);
        set_all(r2, r3, r4);
        redraw();
    }
    void c_b2() {
        set_one(r2);
        set_all(r1, r3, r4);
        redraw();
    }
    void c_b3() {
        set_one(r3);
        set_all(r1, r2, r4);
        redraw();
    }
    void c_b4() {
        set_one(r4);
        set_all(r1, r2, r3);
        redraw();
    }
public:
    Colored_button(Point xy, int w, int h, const string& title) :
        My_window(xy, w, h, title),
        b1{ Point{ x_max() / 2 - 50, y_max() / 2 - 50 }, 50, 50, "b1",
            [](Graph_lib::Address, Graph_lib::Address pw) {
                Graph_lib::reference_to<Colored_button>(pw).c_b1();
            }
        },
        r1(Point{ x_max() / 2 - 50, y_max() / 2 - 50 }, 50, 50),
        b2{ Point{ x_max() / 2 + 50, y_max() / 2 - 50 }, 50, 50, "b2",
            [](Graph_lib::Address, Graph_lib::Address pw) {
                Graph_lib::reference_to<Colored_button>(pw).c_b2();
            }
        },
        r2(Point{ x_max() / 2 + 50, y_max() / 2 - 50 }, 50, 50),
        b3{ Point{ x_max() / 2 - 50, y_max() / 2 + 50 }, 50, 50, "b3",
            [](Graph_lib::Address, Graph_lib::Address pw) {
                Graph_lib::reference_to<Colored_button>(pw).c_b3();
            }
        },
        r3(Point{ x_max() / 2 - 50, y_max() / 2 + 50 }, 50, 50),
       b4{ Point{ x_max() / 2 + 50, y_max() / 2 + 50 }, 50, 50, "b4",
            [](Graph_lib::Address, Graph_lib::Address pw) {
                Graph_lib::reference_to<Colored_button>(pw).c_b4();
            }
       },
       r4(Point{ x_max() / 2 + 50, y_max() / 2 + 50 }, 50, 50) {
            r1.set_color(Graph_lib::Color::dark_red);
            r1.set_fill_color(Graph_lib::Color::dark_red);
            attach(b1);
            attach(r1);

            r2.set_color(Graph_lib::Color::dark_red);
            r2.set_fill_color(Graph_lib::Color::dark_red);
            attach(b2);
            attach(r2);

            r3.set_color(Graph_lib::Color::dark_red);
            r3.set_fill_color(Graph_lib::Color::dark_red);
            attach(b3);
            attach(r3);

            r4.set_color(Graph_lib::Color::dark_red);
            r4.set_fill_color(Graph_lib::Color::dark_red);
            attach(b4);
            attach(r4);
      }
};