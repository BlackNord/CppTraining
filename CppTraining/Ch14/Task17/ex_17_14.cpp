#include "ex_17_14.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../../Ch13/My_Classes/tBox.h"

using namespace std;

void ex_17_14() {
    Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_17_14" };

    myGraph_lib::tBox b1(Point{ 400, 20 }, 80, 20, 10, "exception");
    b1.set_color(Graph_lib::Color::black);
    win.attach(b1);

    myGraph_lib::tBox b2(Point{ 30, 100 }, 100, 20, 10, "runtime_error");
    b2.set_color(Graph_lib::Color::black);
    win.attach(b2);

    myGraph_lib::tBox b3(Point{ 180, 100 }, 80, 20, 10, "bad_alloc");
    b3.set_color(Graph_lib::Color::black);
    win.attach(b3);

    myGraph_lib::tBox b4(Point{ 310, 100 }, 80, 20, 10, "bad_typeid");
    b4.set_color(Graph_lib::Color::black);
    win.attach(b4);

    myGraph_lib::tBox b5(Point{ 440, 100 }, 110, 20, 10, "bad_exception");
    b5.set_color(Graph_lib::Color::black);
    win.attach(b5);

    myGraph_lib::tBox b6(Point{ 600, 100 }, 80, 20, 10, "bad_cast");
    b6.set_color(Graph_lib::Color::black);
    win.attach(b6);

    myGraph_lib::tBox b7(Point{ 730, 100 }, 80, 20, 10, "logic_failure");
    b7.set_color(Graph_lib::Color::black);
    win.attach(b7);

    myGraph_lib::tBox b8(Point{ 20, 170 }, 110, 20, 10, "overflow_error");
    b8.set_color(Graph_lib::Color::black);
    win.attach(b8);

    myGraph_lib::tBox b9(Point{ 160, 170 }, 90, 20, 10, "range_error");
    b9.set_color(Graph_lib::Color::black);
    win.attach(b9);

    myGraph_lib::tBox b10(Point{ 280, 170 }, 120, 20, 10, "underflow_error");
    b10.set_color(Graph_lib::Color::black);
    win.attach(b10);

    myGraph_lib::tBox b11(Point{ 490, 170 }, 100, 20, 10, "domain_error");
    b11.set_color(Graph_lib::Color::black);
    win.attach(b11);

    myGraph_lib::tBox b12(Point{ 650, 170 }, 140, 20, 10, "invalid_argument");
    b12.set_color(Graph_lib::Color::black);
    win.attach(b12);

    myGraph_lib::tBox b13(Point{ 835, 170 }, 80, 20, 10, "lenght_error");
    b13.set_color(Graph_lib::Color::black);
    win.attach(b13);

    myGraph_lib::tBox b14(Point{ 950, 170 }, 100, 20, 10, "out_of_range");
    b14.set_color(Graph_lib::Color::black);
    win.attach(b14);

    Graph_lib::Line l1(Point{440, 50}, Point{80, 100});
    l1.set_color(Graph_lib::Color::black);
    win.attach(l1);

    Graph_lib::Line l2(Point{ 440, 50 }, Point{220,100});
    l2.set_color(Graph_lib::Color::black);
    win.attach(l2);

    Graph_lib::Line l3(Point{ 440, 50 }, Point{350,100});
    l3.set_color(Graph_lib::Color::black);
    win.attach(l3);

    Graph_lib::Line l4(Point{ 440, 50 }, Point{495,100});
    l4.set_color(Graph_lib::Color::black);
    win.attach(l4);

    Graph_lib::Line l5(Point{ 440, 50 }, Point{640,100});
    l5.set_color(Graph_lib::Color::black);
    win.attach(l5);

    Graph_lib::Line l6(Point{ 440, 50 }, Point{770,100});
    l6.set_color(Graph_lib::Color::black);
    win.attach(l6);

    Graph_lib::Line l7(Point{ 80, 130 }, Point{75,170});
    l7.set_color(Graph_lib::Color::black);
    win.attach(l7);

    Graph_lib::Line l8(Point{ 80, 130 }, Point{205,170});
    l8.set_color(Graph_lib::Color::black);
    win.attach(l8);

    Graph_lib::Line l9(Point{ 80, 130 }, Point{340,170});
    l9.set_color(Graph_lib::Color::black);
    win.attach(l9);

    Graph_lib::Line l10(Point{ 770, 130 }, Point{580,170});
    l10.set_color(Graph_lib::Color::black);
    win.attach(l10);

    Graph_lib::Line l11(Point{ 770, 130 }, Point{720,170});
    l11.set_color(Graph_lib::Color::black);
    win.attach(l11);

    Graph_lib::Line l12(Point{ 770, 130 }, Point{875,170});
    l12.set_color(Graph_lib::Color::black);
    win.attach(l12);

    Graph_lib::Line l13(Point{ 770, 130 }, Point{1000,170});
    l13.set_color(Graph_lib::Color::black);
    win.attach(l13);

    win.wait_for_button();
}