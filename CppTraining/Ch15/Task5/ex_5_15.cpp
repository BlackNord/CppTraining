#include "ex_5_15.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

double funct(int n) {
    double rez{ 0 };
    int zn{ 1 };

    for (int i{ 1 }; i <= n; i += 2) {
        rez += zn * int(1 / i);
        zn *= -1;
    }

    return rez;
}

void ex_5_15() {
    int height{ 600 };
    int width{ 600 };
    int length{ 400 };

    Simple_window win{ Point {20, 50 }, height, width, "Graphics" };

    Graph_lib::Axis ox{ Graph_lib::Axis::x, Point{(height - length)/2, width/2}, length, 20, "X" };
    ox.set_color(Graph_lib::Color::red);
    ox.label.set_color(Graph_lib::Color::black);
    ox.label.move(-120, -40);
    win.attach(ox);

    Graph_lib::Axis oy{ Graph_lib::Axis::y, Point{height/2, width - (width - length) / 2}, length, 20, "Y" };
    oy.set_color(Graph_lib::Color::red);
    oy.label.set_color(Graph_lib::Color::black);
    oy.label.move(-10, 40);
    win.attach(oy);

    Point orig{ height / 2 , width / 2 };
    double r_min{ -10 }, r_max{ 11 };
    int number_of_points{ 400 };

    Graph_lib::Open_polyline op1;

    for (int i{ 0 }; i < 10; ++i) {
        op1.add(Point(orig.x + int(i * 20), orig.y - int(funct(i) * 20)));
        op1.set_color(Graph_lib::Color::black);

        win.attach(op1);
        win.wait_for_button();
        win.detach(op1);
    }
}