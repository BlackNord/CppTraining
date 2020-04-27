#include "ex_5.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"

using namespace std;

void ex_5() {
	Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_5" };
	
	Graph_lib::Polygon p1;
	p1.add(Point{ 100, 20 });
	p1.add(Point{ 1090, 20 });
	p1.add(Point{ 1090, 720 });
	p1.add(Point{ 100, 720 });
	p1.set_color(Graph_lib::Color::red);
	p1.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 20));

	win.attach(p1);

	win.wait_for_button();
}