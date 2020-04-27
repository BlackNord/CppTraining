#include "ex_7.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"

void ex_7() {
	Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_7" };
	
	Graph_lib::Polygon p1;
	p1.add(Point{ 400, 500 });
	p1.add(Point{ 600, 500 });
	p1.add(Point{ 600, 350 });
	p1.add(Point{ 400, 350 });
	p1.set_color(Graph_lib::Color::black);
	win.attach(p1);

	Graph_lib::Line l1{ Point{ 600, 350 } , Point{ 500, 270 } };
	l1.set_color(Graph_lib::Color::black);
	win.attach(l1);

	Graph_lib::Line l2{ Point{ 500, 270 } , Point{ 400, 350 } };
	l2.set_color(Graph_lib::Color::black);
	win.attach(l2);

	Graph_lib::Rectangle r1{ Point{420, 430}, 50, 71 };
	r1.set_color(Graph_lib::Color::black);
	win.attach(r1);

	Graph_lib::Rectangle r2{ Point{500, 380}, 65, 65 };
	r2.set_color(Graph_lib::Color::black);
	win.attach(r2);

	win.wait_for_button();
}