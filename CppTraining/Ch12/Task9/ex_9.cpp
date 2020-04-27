#include "ex_9.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"

void ex_9() {
	Simple_window win{ Point {20, 50 }, 550, 550, "Cat" };
	
	Graph_lib::Image i1{ Point {20, 20}, "Resourses/1.jpg" };
	win.attach(i1);

	win.wait_for_button();
}