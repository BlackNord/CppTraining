#include "ex_2.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../../Ch13/My_classes/Box.h"

using namespace std;

void ex_2() {
	Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_2" };

	myGraph_lib::Box b(Point{ 100, 100 }, 300, 300, 50);
	b.set_color(Graph_lib::Color::black);
	win.attach(b);

	win.wait_for_button();
}