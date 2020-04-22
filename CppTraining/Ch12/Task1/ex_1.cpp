#include "ex_1.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"

using namespace std;

void ex_1() {
	Simple_window win{ Point {50, 50 }, 1000, 1000, "Ex_1" };

	Rectangle rec{ Point{200, 200}, 100, 50 };
	rec.set_color(Color::blue);

	win.attach(rec);

	Polygon pol;
	pol.add(Point{ 400, 400 });
	pol.add(Point{ 400, 500 });
	pol.add(Point{ 350, 500 });
	pol.add(Point{ 350, 400 });
	pol.set_color(Color::red);

	win.attach(pol);

	win.wait_for_button();
}