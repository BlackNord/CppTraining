#include "ex_4_15.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

double sin_cos(double x) {
    return sin(x) + cos(x);
}

double sin2_cos2(double x) {
    return sin(x) * sin(x) + cos(x) * cos(x);
}

void ex_4_15() {
    int height{ 600 };
    int width{ 600 };
    int length{ 400 };

    Simple_window win{ Point {20, 50 }, height, width, "Graphics of the functions" };

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

    Graph_lib::Function f1{ sin, r_min, r_max, orig, number_of_points, 20, 20 };
    f1.set_color(Graph_lib::Color::black);
    win.attach(f1);

    Graph_lib::Function f2{ cos, r_min, r_max, orig, number_of_points, 20, 20 };
    f2.set_color(Graph_lib::Color::dark_blue);
    win.attach(f2);

    Graph_lib::Function f3{ sin_cos, r_min, r_max, orig, number_of_points, 20, 20 };
    f3.set_color(Graph_lib::Color::black);
    win.attach(f3);

    Graph_lib::Function f4{ sin2_cos2, r_min, r_max, orig, number_of_points, 20, 20 };
    f4.set_color(Graph_lib::Color::black);
    win.attach(f4);

    win.wait_for_button();
}