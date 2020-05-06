#pragma once
#include "../../Stroustruap_libs/Graph.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"
#include <cmath>

namespace myGraph_lib {
	class Arrow : public Graph_lib::Line {
	private:
		Point p1, p2;
		double angl{ 3.14 - 0.5 };		// 30 grad
	public:
		Arrow(Point _start, Point _end) : Line(_start, _end) {
			Point direction{ _end.x - _start.x, _start.y - _end.y };
			p1 = new_point(direction, angl);
			p2 = new_point(direction, -angl);
		}
		void draw_lines() const override;
		Point new_point(Point, double);
	};
}