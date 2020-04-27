#include "ex_4.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"

using namespace std;

void ex_4() {
	Simple_window win{ Point {50, 50 }, 600, 600, "Ex_4" };

	Graph_lib::Rectangle r1{ Point{10,10}, 30, 30 };
	r1.set_fill_color(Graph_lib::Color::white);
	win.attach(r1);

	Graph_lib::Rectangle r2{ Point{40,10}, 30, 30 };
	r2.set_fill_color(Graph_lib::Color::red);
	win.attach(r2);

	Graph_lib::Rectangle r3{ Point{70,10}, 30, 30 };
	r3.set_fill_color(Graph_lib::Color::white);
	win.attach(r3);

	Graph_lib::Rectangle r4{ Point{10,40}, 30, 30 };
	r4.set_fill_color(Graph_lib::Color::red);
	win.attach(r4);

	Graph_lib::Rectangle r5{ Point{40,40}, 30, 30 };
	r5.set_fill_color(Graph_lib::Color::white);
	win.attach(r5);

	Graph_lib::Rectangle r6{ Point{70,40}, 30, 30 };
	r6.set_fill_color(Graph_lib::Color::red);
	win.attach(r6);

	Graph_lib::Rectangle r7{ Point{10,70}, 30, 30 };
	r7.set_fill_color(Graph_lib::Color::white);
	win.attach(r7);

	Graph_lib::Rectangle r8{ Point{40,70}, 30, 30 };
	r8.set_fill_color(Graph_lib::Color::red);
	win.attach(r8);

	Graph_lib::Rectangle r9{ Point{70,70}, 30, 30 };
	r9.set_fill_color(Graph_lib::Color::white);
	win.attach(r9);

	win.wait_for_button();
}