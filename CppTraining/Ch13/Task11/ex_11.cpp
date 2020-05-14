#include "ex_11.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"

void ex_11() {
    Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_11" };

    Graph_lib::Axis ox{ Graph_lib::Axis::x, Point{530, win.y_max() / 2}, 400, 20, "X" };
    ox.set_color(Graph_lib::Color::black);
    win.attach(ox);

    Graph_lib::Axis oy{ Graph_lib::Axis::y, Point{win.x_max() / 2, 520}, 300, 10, "Y" };
    oy.set_color(Graph_lib::Color::black);
    win.attach(oy);

    Point center(win.x_max() / 2, win.y_max() / 2);

    Graph_lib::Ellipse obj(center, 150, 100);
    obj.set_color(Graph_lib::Color::black);
    win.attach(obj);

    int f = pow(pow(150, 2) - pow(100, 2), 0.5);

    Point f1{ win.x_max() / 2 - f, win.y_max() / 2 };
    Point f2{ win.x_max() / 2 + f, win.y_max() / 2 };

    Graph_lib::Mark m1(f2, 'F');
    m1.set_color(Graph_lib::Color::black);
    win.attach(m1);

    Graph_lib::Mark m2(f1, 'F');
    m2.set_color(Graph_lib::Color::black);
    win.attach(m2);

    Point t{ win.x_max() / 2 - 120 , win.y_max() / 2 - 60};

    Graph_lib::Mark m3(t, 'T');
    m3.set_color(Graph_lib::Color::black);
    win.attach(m3);

    Graph_lib::Line l1(t, f2);
    l1.set_color(Graph_lib::Color::black);
    win.attach(l1);

    Graph_lib::Line l2(t, f1);
    l2.set_color(Graph_lib::Color::black);
    win.attach(l2);

    win.wait_for_button();
}