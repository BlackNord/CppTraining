#include "ex_12.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"

#include <cmath>
#include <corecrt_math_defines.h>

Point new_point(Point _old, Point center, int radius, double t) {
    Point new_p;

    new_p.x = center.x + radius * cos(t);
    new_p.y = center.y + radius * sin(t);

    return new_p;
}

void ex_12() {
    Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_12" };

    int radius{ 100 };

    Point center{ win.x_max()/2, win.y_max()/2 };

    Point p{ win.x_max() / 2, win.y_max() / 2 - radius };

    Graph_lib::Mark m1(p, 'X');
    m1.set_color(Graph_lib::Color::black);
    win.attach(m1);

    Graph_lib::Circle c1{ center, radius };
    c1.set_color(Graph_lib::Color::black);
    win.attach(c1);

    double t{ 0 };

    while (true) {
        win.wait_for_button();
        p = new_point(p, center, radius, t);
        t += M_PI/6;
        cout << p.x << " " << p.y << endl;
        m1.move(p.x - m1.point(0).x, p.y - m1.point(0).y); 
    }
}