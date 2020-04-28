#include "ex_12_13.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include <cmath>
#include <string_view>
#include <random>
#include <memory>

template<class Type>
Type read_value(const string_view message) {
	Type v;
	cout << message << endl;
	cin >> v;
	if (!cin) throw runtime_error("Numeric value is expected");
	return v;
}

double count_x(double x, double n, double m, double a = 100, double b = 100) {
	double y{ 0 };

	y = b * pow(abs(1 - pow(abs(x / a), m)), 1 / n);

	return y;
}

vector<Point> count_points(Point center, int N, double n, double m) {
	vector<Point> points{};
	double y{ 0 };

	double val = 200 / ((N/2)+1);

	for (int x = -100 + val; x <= 100-val; x += val) {
		y = count_x(x, n, m);
		points.push_back(Point(x + center.x, y + center.y));
		x = -x;
		y = -y;
		points.push_back(Point(x + center.x, y + center.y));
		x = -x;
	}

	return points;
}

void ex_12_13() {
	double a = 100, b = 100, n, m;
	int N{ 0 };
	//a = read_value<double>("Enter parametr a");
	if (a == 0) error("Bad a");
	//b = read_value<double>("Enter parametr b");
	if (b == 0) error("Bad b");
	m = read_value<double>("Enter parametr m");
	if (m < 0) error("Bad m");
	n = read_value<double>("Enter parametr n");
	if (n < 0) error("Bad n");
	N = read_value<int>("Enter number N");
	if (N < 0 or N % 2 != 0) error("Bad N");

	Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_12_13" };
	win.color(Graph_lib::Color::white);
	
	Graph_lib::Axis ox{ Graph_lib::Axis::x, Point{40, 375}, 1380, 50, "X" };
	ox.set_color(Graph_lib::Color::black);
	win.attach(ox);

	Graph_lib::Axis oy{ Graph_lib::Axis::y, Point{730, 710}, 670, 40, "Y" };
	oy.set_color(Graph_lib::Color::black);
	win.attach(oy);

	Point center(win.x_max() / 2, win.y_max() / 2);
	Graph_lib::Closed_polyline s_ellips;
	s_ellips.set_color(Graph_lib::Color::black);

	double y{ 0 };

	for (int x = -100; x <= 100; x++) {
		y = count_x(x, n, m);
		s_ellips.add(Point(x + center.x, y + center.y));
	}

	for (int x = -100; x <= 100; x++) {
		y = count_x(x, n, m);
		y = -y;
		s_ellips.add(Point(x + center.x, y + center.y));
	}
	
	win.attach(s_ellips);

	vector<Point> points = count_points(center, N, n, m);
	vector<unique_ptr<Graph_lib::Line>> lines{};

	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(0, 255);

	for (int i = 0; i < points.size(); i+=2) {
		int clr = dist(mt);

		Graph_lib::Color temp(clr);

		unique_ptr<Graph_lib::Line> l = make_unique<Graph_lib::Line>(points[i], points[i + 1]);
		l.get()->set_color(temp);
		lines.push_back(move(l));
	}

	for (const auto & u : lines) {
		win.attach(*u);
	}

	win.wait_for_button();
}