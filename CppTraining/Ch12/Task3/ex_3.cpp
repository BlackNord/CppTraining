#include "ex_3.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"

using namespace std;

void ex_3() {
	Simple_window win{ Point {50, 50 }, 600, 600, "Ex_3" };

	Graph_lib::Text t{ Point{ 100, 150 }, "V.V.A." };
	t.set_font(Graph_lib::Font::times_bold);
	t.set_font_size(150);
	t.set_color(Graph_lib::Color::black);
	win.attach(t);

	Graph_lib::Line l1{ Point{ 100, 300 }, Point{ 150, 450 } };
	l1.set_color(Graph_lib::Color::black);
	l1.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 5));
	win.attach(l1);
	Graph_lib::Line l2{ Point{ 150, 450 }, Point{ 200, 300 } };
	l2.set_color(Graph_lib::Color::black);
	l2.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 5));
	win.attach(l2);

	Graph_lib::Line l3{ Point{ 220, 300 }, Point{ 270, 450 } };
	l3.set_color(Graph_lib::Color::red);
	l3.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 5));
	win.attach(l3);
	Graph_lib::Line l4{ Point{ 270, 450 }, Point{ 320, 300 } };
	l4.set_color(Graph_lib::Color::red);
	l4.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 5));
	win.attach(l4);

	Graph_lib::Line l5{ Point{ 340, 450 }, Point{ 390, 300 } };
	l5.set_color(Graph_lib::Color::green);
	l5.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 5));
	win.attach(l5);
	Graph_lib::Line l6{ Point{ 390, 300 }, Point{ 440, 450 } };
	l6.set_color(Graph_lib::Color::green);
	l6.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 5));
	win.attach(l6);
	Graph_lib::Line l7{ Point{ 365, 375 }, Point{ 415, 375 } };
	l7.set_color(Graph_lib::Color::green);
	l7.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 5));
	win.attach(l7);

	win.wait_for_button();
}