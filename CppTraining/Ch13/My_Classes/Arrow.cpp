#include "Arrow.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"

void myGraph_lib::Arrow::draw_lines() const {
	fl_line(point(0).x, point(0).y, point(1).x, point(1).y);
	fl_line(p1.x, p1.y, point(1).x, point(1).y);
	fl_line(p2.x, p2.y, point(1).x, point(1).y);
}

Point myGraph_lib::Arrow::new_point(Point _old, double angle) {
	Point new_p;

	new_p.x = (_old.x * cos(angle) + _old.y * sin(angle)) * 0.15 + point(1).x;
	new_p.y = (_old.x * sin(angle) - _old.y * cos(angle)) * 0.15 + point(1).y;

	return new_p;
}