#include "ex_6.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../My_Classes/tBox.h"
#include "../My_Classes/Arrow.h"

void ex_6() {
    Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_6" };

    myGraph_lib::tBox b0{ Point{30,40}, 100, 30, 20, "Point.h"};
    b0.set_color(Graph_lib::Color::black);
    win.attach(b0);

    myGraph_lib::tBox b1{ Point{30,200}, 140, 40, 20, "Graph.h" };
    b1.set_color(Graph_lib::Color::black);
    win.attach(b1);

    myGraph_lib::tBox b2{ Point{10,350}, 100, 30, 20, "Graph.cpp" };
    b2.set_color(Graph_lib::Color::black);
    win.attach(b2);

    myGraph_lib::tBox b3{ Point{150,300}, 100, 30, 20, "Windows.cpp" };
    b3.set_color(Graph_lib::Color::black);
    win.attach(b3);

    myGraph_lib::tBox b4{ Point{180,370}, 140, 40, 20, "Simple_window.h" };
    b4.set_color(Graph_lib::Color::black);
    win.attach(b4);

    myGraph_lib::tBox b5{ Point{90,480}, 140, 40, 20, "chapter12.cpp" };
    b5.set_color(Graph_lib::Color::black);
    win.attach(b5);

    myGraph_lib::tBox b6{ Point{310,170}, 140, 40, 20, "Window.h" };
    b6.set_color(Graph_lib::Color::black);
    win.attach(b6);

    myGraph_lib::tBox b7{ Point{390,265}, 140, 40, 20, "GUI.h" };
    b7.set_color(Graph_lib::Color::black);
    win.attach(b7);

    myGraph_lib::tBox b8{ Point{390,360}, 100, 30, 20, "GUI.cpp" };
    b8.set_color(Graph_lib::Color::black);
    win.attach(b8);

    myGraph_lib::tBox b9{ Point{420,60}, 100, 30, 20, "FLTK" };
    b9.set_color(Graph_lib::Color::black);
    win.attach(b9);

    myGraph_lib::tBox b10{ Point{230,40}, 100, 30, 20, "Headers" };
    b10.set_color(Graph_lib::Color::black);
    win.attach(b10);

	myGraph_lib::Arrow l1{ Point{100,200}, Point{80,90} };
	l1.set_color(Graph_lib::Color::black);
	win.attach(l1);

	myGraph_lib::Arrow l2{ Point{100,200}, Point{470, 110} };
	l2.set_color(Graph_lib::Color::black);
	win.attach(l2);

    myGraph_lib::Arrow l3{ Point{440,360}, Point{460, 320} };
    l3.set_color(Graph_lib::Color::black);
    win.attach(l3);

    myGraph_lib::Arrow l4{ Point{60,350}, Point{100, 260} };
    l4.set_color(Graph_lib::Color::black);
    win.attach(l4);

    myGraph_lib::Arrow l5{ Point{160,480}, Point{100, 260} };
    l5.set_color(Graph_lib::Color::black);
    win.attach(l5);

    myGraph_lib::Arrow l6{ Point{160,480}, Point{250, 430} };
    l6.set_color(Graph_lib::Color::black);
    win.attach(l6);

    myGraph_lib::Arrow l7{ Point{200,300}, Point{400, 230} };
    l7.set_color(Graph_lib::Color::black);
    win.attach(l7);

    myGraph_lib::Arrow l8{ Point{400, 170}, Point{280, 90} };
    l8.set_color(Graph_lib::Color::black);
    win.attach(l8);

    myGraph_lib::Arrow l9{ Point{420, 80}, Point{280, 90} };
    l9.set_color(Graph_lib::Color::black);
    win.attach(l9);

    myGraph_lib::Arrow l10{ Point{460, 265}, Point{380, 230} };
    l10.set_color(Graph_lib::Color::black);
    win.attach(l10);

    win.wait_for_button();
}