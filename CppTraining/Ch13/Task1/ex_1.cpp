#include "ex_1.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../../Ch13/My_classes/Arc.h"

using namespace std;

void ex_1() {
	Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_1" };

	myGraph_lib::Arc obj1(Point{100, 100}, 50, 30, 0, 260);
	obj1.set_color(Graph_lib::Color::black);
	win.attach(obj1);

	win.wait_for_button();
}