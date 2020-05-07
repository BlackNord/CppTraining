#include "ex_4.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"

using namespace std;

namespace myGraph_lib {
	Point n(const Graph_lib::Rectangle& obj) {
		Point pon{ 0,0 };

		pon.x = obj.point(0).x + obj.width() / 2;
		pon.y = obj.point(0).y;

		return pon;
	}

	Point s(const Graph_lib::Rectangle& obj) {
		Point pon{ 0,0 };

		pon.x = obj.point(0).x + obj.width() / 2;
		pon.y = obj.point(0).y + obj.height();

		return pon;
	}

	Point e(const Graph_lib::Rectangle& obj) {
		Point pon{ 0,0 };

		pon.x = obj.point(0).x + obj.width();
		pon.y = obj.point(0).y + obj.height() / 2;

		return pon;
	}

	Point w(const Graph_lib::Rectangle& obj) {
		Point pon{ 0,0 };

		pon.x = obj.point(0).x;
		pon.y = obj.point(0).y + obj.height() / 2;

		return pon;
	}

	Point center(const Graph_lib::Rectangle& obj) {
		Point pon{ 0,0 };

		pon.x = obj.point(0).x + obj.width() / 2;
		pon.y = obj.point(0).y + obj.height() / 2;

		return pon;
	}

	Point ne(const Graph_lib::Rectangle& obj) {
		Point pon{ 0,0 };

		pon.x = obj.point(0).x + obj.width();
		pon.y = obj.point(0).y;

		return pon;
	}

	Point se(const Graph_lib::Rectangle& obj) {
		Point pon{ 0,0 };

		pon.x = obj.point(0).x + obj.width();
		pon.y = obj.point(0).y + obj.height();

		return pon;
	}

	Point sw(const Graph_lib::Rectangle& obj) {
		Point pon{ 0,0 };

		pon.x = obj.point(0).x;
		pon.y = obj.point(0).y + obj.height();

		return pon;
	}

	Point nw(const Graph_lib::Rectangle& obj) {
		Point pon{ 0,0 };

		pon.x = obj.point(0).x;
		pon.y = obj.point(0).y;

		return pon;
	}
}

void ex_4() {
	using namespace myGraph_lib;

	Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_4" };

	Graph_lib::Rectangle obj1(Point{ 250,250 }, 400, 400);

	Point test1 = n(obj1);
	cout << "nX: " << test1.x << endl;
	cout << "Y: " << test1.y << endl;

	Point test2 = s(obj1);
	cout << "sX: " << test2.x << endl;
	cout << "Y: " << test2.y << endl;

	Point test3 = e(obj1);
	cout << "eX: " << test3.x << endl;
	cout << "Y: " << test3.y << endl;

	Point test4 = w(obj1);
	cout << "wX: " << test4.x << endl;
	cout << "Y: " << test4.y << endl;

	Point test5 = center(obj1);
	cout << "cX: " << test5.x << endl;
	cout << "Y: " << test5.y << endl;

	Point test6 = ne(obj1);
	cout << "neX: " << test6.x << endl;
	cout << "Y: " << test6.y << endl;

	Point test7 = se(obj1);
	cout << "seX: " << test7.x << endl;
	cout << "Y: " << test7.y << endl;

	Point test8 = sw(obj1);
	cout << "swX: " << test8.x << endl;
	cout << "Y: " << test8.y << endl;

	Point test9 = nw(obj1);
	cout << "nwX: " << test9.x << endl;
	cout << "Y: " << test9.y << endl;

	obj1.set_color(Graph_lib::Color::black);
	win.attach(obj1);

	win.wait_for_button();
}