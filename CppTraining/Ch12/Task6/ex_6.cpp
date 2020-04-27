#include "ex_6.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"

using namespace std;

void ex_6_1() {
	Simple_window win{ Point {20, 50 }, 500, 500, "Ex_6_1" };
	
	Graph_lib::Rectangle r1{ Point{1,1}, 600, 600 };
	r1.set_fill_color(Graph_lib::Color::white);
	win.attach(r1);

	win.wait_for_button();
}

void ex_6_2() {
	Simple_window win{ Point {20, 50 }, 3000, 3000, "Ex_6_2" };

	win.wait_for_button();
}