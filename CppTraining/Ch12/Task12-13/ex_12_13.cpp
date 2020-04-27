#include "ex_12_13.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include <cmath>

double spellips(double x) {
	double y{ 0 };
	double a = 2;
	double b = 5;
	double m = 3;
	double n = 4;

	y = (pow(abs(1 - pow(abs(x / a), m)), 1/n))*b;

	return y;
}

void ex_12_13() {
	Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_12_13" };
	win.color(Graph_lib::Color::white);
	
	Graph_lib::Axis ox{ Graph_lib::Axis::x, Point{40, 375}, 1380, 50, "X" };
	ox.set_color(Graph_lib::Color::black);
	win.attach(ox);

	Graph_lib::Axis oy{ Graph_lib::Axis::y, Point{730, 710}, 670, 40, "Y" };
	oy.set_color(Graph_lib::Color::black);
	win.attach(oy);

	

	win.wait_for_button();
}