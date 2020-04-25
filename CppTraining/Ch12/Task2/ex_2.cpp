#include "ex_2.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"

using namespace std;

void ex_2() {
	Simple_window win{ Point {50, 50 }, 600, 600, "Ex_2" };

	Graph_lib::Rectangle rec{ Point{100, 100}, 100, 30 };
	rec.set_color(Graph_lib::Color::red);
	win.attach(rec);
	
	Graph_lib::Text t{ Point{130, 120}, "Howdo!" };
	t.set_color(Graph_lib::Color::black);
	win.attach(t);

	win.wait_for_button();
}