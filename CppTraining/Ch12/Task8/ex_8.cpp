#include "ex_8.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"

void ex_8() {
	Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_8" };
	
	Graph_lib::Circle c1{ Point {60, 60}, 30 };
	c1.set_color(Graph_lib::Color::blue);
	c1.set_style(Graph_lib::Line_style{ Graph_lib::Line_style::solid, 5});
	win.attach(c1);

	Graph_lib::Circle c2{ Point {130, 60}, 30 };
	c2.set_color(Graph_lib::Color::black);
	c2.set_style(Graph_lib::Line_style{ Graph_lib::Line_style::solid, 5 });
	win.attach(c2);

	Graph_lib::Circle c3{ Point {200, 60}, 30 };
	c3.set_color(Graph_lib::Color::red);
	c3.set_style(Graph_lib::Line_style{ Graph_lib::Line_style::solid, 5 });
	win.attach(c3);

	Graph_lib::Circle c4{ Point {100, 90}, 30 };
	c4.set_color(Graph_lib::Color::dark_yellow);
	c4.set_style(Graph_lib::Line_style{ Graph_lib::Line_style::solid, 5 });
	win.attach(c4);

	Graph_lib::Circle c5{ Point {170, 90}, 30 };
	c5.set_color(Graph_lib::Color::dark_green);
	c5.set_style(Graph_lib::Line_style{ Graph_lib::Line_style::solid, 5 });
	win.attach(c5);

	win.wait_for_button();
}