#include "ex_5.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"

using namespace std;

namespace myGraph_lib {
	Point n_c(const Graph_lib::Circle& obj) {
		Point pon{ 0,0 };

		pon.x = obj.center().x;
		pon.y = obj.center().y - obj.radius();

		return pon;
	}

	Point n_e(const Graph_lib::Ellipse& obj) {
		Point pon{ 0,0 };

		pon.x = obj.center().x;
		pon.y = obj.center().y - obj.minor();

		return pon;
	}

	Point s_c(const Graph_lib::Circle& obj) {
		Point pon{ 0,0 };

		pon.x = obj.center().x;
		pon.y = obj.center().y + obj.radius();

		return pon;
	}

	Point s_e(const Graph_lib::Ellipse& obj) {
		Point pon{ 0,0 };

		pon.x = obj.center().x;
		pon.y = obj.center().y + obj.minor();

		return pon;
	}

	Point e_c(const Graph_lib::Circle& obj) {
		Point pon{ 0,0 };

		pon.x = obj.center().x + obj.radius();
		pon.y = obj.center().y;

		return pon;
	}

	Point e_e(const Graph_lib::Ellipse& obj) {
		Point pon{ 0,0 };

		pon.x = obj.center().x + obj.major();
		pon.y = obj.center().y;

		return pon;
	}

	Point w_c(const Graph_lib::Circle& obj) {
		Point pon{ 0,0 };

		pon.x = obj.center().x - obj.radius();
		pon.y = obj.center().y;

		return pon;
	}

	Point w_e(const Graph_lib::Ellipse& obj) {
		Point pon{ 0,0 };

		pon.x = obj.center().x - obj.major();
		pon.y = obj.center().y;

		return pon;
	}

	Point center_c(const Graph_lib::Circle& obj) {
		Point pon{ 0,0 };

		pon.x = obj.center().x;
		pon.y = obj.center().y;

		return pon;
	}

	Point center_e(const Graph_lib::Ellipse& obj) {
		Point pon{ 0,0 };

		pon.x = obj.center().x;
		pon.y = obj.center().y;

		return pon;
	}

	Point ne_c(const Graph_lib::Circle& obj) {
		Point pon{ 0,0 };

		pon.x = obj.center().x + obj.radius();
		pon.y = obj.center().y - obj.radius();

		return pon;
	}

	Point ne_e(const Graph_lib::Ellipse& obj) {
		Point pon{ 0,0 };

		pon.x = obj.center().x + obj.major();
		pon.y = obj.center().y - obj.minor();

		return pon;
	}

	Point se_c(const Graph_lib::Circle& obj) {
		Point pon{ 0,0 };

		pon.x = obj.center().x + obj.radius();
		pon.y = obj.center().y + obj.radius();

		return pon;
	}

	Point se_e(const Graph_lib::Ellipse& obj) {
		Point pon{ 0,0 };

		pon.x = obj.center().x + obj.major();
		pon.y = obj.center().y + obj.minor();

		return pon;
	}

	Point sw_c(const Graph_lib::Circle& obj) {
		Point pon{ 0,0 };

		pon.x = obj.center().x - obj.radius();
		pon.y = obj.center().y + obj.radius();

		return pon;
	}

	Point sw_e(const Graph_lib::Ellipse& obj) {
		Point pon{ 0,0 };

		pon.x = obj.center().x - obj.major();
		pon.y = obj.center().y + obj.minor();

		return pon;
	}

	Point nw_c(const Graph_lib::Circle& obj) {
		Point pon{ 0,0 };

		pon.x = obj.center().x - obj.radius();
		pon.y = obj.center().y - obj.radius();

		return pon;
	}

	Point nw_e(const Graph_lib::Ellipse& obj) {
		Point pon{ 0,0 };

		pon.x = obj.center().x - obj.major();
		pon.y = obj.center().y - obj.minor();

		return pon;
	}
}

void ex_5() {
	using namespace myGraph_lib;

	Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_5" };

	Graph_lib::Circle obj1(Point{ 100,100 }, 50);

	Point test1 = n_c(obj1);
	cout << "n_cX: " << test1.x << endl;
	cout << "Y: " << test1.y << endl;

	obj1.set_color(Graph_lib::Color::black);
	win.attach(obj1);

	win.wait_for_button();
}