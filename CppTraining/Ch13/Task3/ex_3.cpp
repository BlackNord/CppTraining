#include "ex_3.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../../Ch13/My_classes/Arrow.h"

using namespace std;

void ex_3() {
	Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_3" };

	myGraph_lib::Arrow obj1(Point{ 150,150 }, Point{ 50, 150 });
	obj1.set_color(Graph_lib::Color::black);
	win.attach(obj1);

	myGraph_lib::Arrow obj2(Point{ 300,300 }, Point{ 400, 200 });
	obj2.set_color(Graph_lib::Color::black);
	win.attach(obj2);

	myGraph_lib::Arrow obj3(Point{ 400,15 }, Point{ 400, 150 });
	obj3.set_color(Graph_lib::Color::black);
	win.attach(obj3);

	myGraph_lib::Arrow obj4(Point{ 500,20 }, Point{ 550, 150 });
	obj4.set_color(Graph_lib::Color::black);
	win.attach(obj4);

	myGraph_lib::Arrow obj5(Point{ 480,300 }, Point{ 320, 500 });
	obj5.set_color(Graph_lib::Color::black);
	win.attach(obj5);

	win.wait_for_button();
}