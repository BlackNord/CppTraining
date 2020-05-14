#include "ex_14.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../My_Classes/Right_triangle.h"

#include <random>

void ex_14() {
    Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_14" };

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, 255);

    myGraph_lib::Right_triangle rt1(Point{ 700, 300 }, 50, -70);
    rt1.set_color(Graph_lib::Color::invisible);
    rt1.set_fill_color(Graph_lib::Color(dist(mt)));
    win.attach(rt1);

    myGraph_lib::Right_triangle rt2(Point{ 700, 300 }, 50, 70);
    rt2.set_color(Graph_lib::Color::invisible);
    rt2.set_fill_color(Graph_lib::Color(dist(mt)));
    win.attach(rt2);

    myGraph_lib::Right_triangle rt3(Point{ 700, 350 }, -50, -70);
    rt3.set_color(Graph_lib::Color::invisible);
    rt3.set_fill_color(Graph_lib::Color(dist(mt)));
    win.attach(rt3);

    myGraph_lib::Right_triangle rt4(Point{ 700, 350 }, -50, 70);
    rt4.set_color(Graph_lib::Color::invisible);
    rt4.set_fill_color(Graph_lib::Color(dist(mt)));
    win.attach(rt4);

    myGraph_lib::Right_triangle rt5(Point{ 700, 300 }, -50, -70);
    rt5.set_color(Graph_lib::Color::invisible);
    rt5.set_fill_color(Graph_lib::Color(dist(mt)));
    win.attach(rt5);

    myGraph_lib::Right_triangle rt6(Point{ 700, 300 }, -50, 70);
    rt6.set_color(Graph_lib::Color::invisible);
    rt6.set_fill_color(Graph_lib::Color(dist(mt)));
    win.attach(rt6);

    myGraph_lib::Right_triangle rt7(Point{ 630, 350 }, 50, 70);
    rt7.set_color(Graph_lib::Color::invisible);
    rt7.set_fill_color(Graph_lib::Color(dist(mt)));
    win.attach(rt7);

    myGraph_lib::Right_triangle rt8(Point{ 770, 350 }, 50, -70);
    rt8.set_color(Graph_lib::Color::invisible);
    rt8.set_fill_color(Graph_lib::Color(dist(mt)));
    win.attach(rt8);

    win.wait_for_button();
}