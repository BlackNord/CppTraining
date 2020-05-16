#pragma once

#include "../../Stroustruap_libs/Graph.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

#include <cmath>
#include <corecrt_math_defines.h>

namespace myGraph_lib {
	class Star : public Graph_lib::Closed_polyline {
	private:
		Point center;
		int number_ver;
		int rv{ 70 };
		int ro{ 100 };
	public:
		Star(Point _center, int _number_ver) : center{ _center }, number_ver{ _number_ver } {
			if (number_ver < 2) error("bad number of vers");

			float a = 0;
			Point p;
			int x = center.x;
			int y = center.y;

			for (int i = 1; i < number_ver * 2 + 1; i++) {
				if (!(i % 2)) {
					p.x = x + rv / 2 * cos(a * M_PI / 180);
					p.y = y - rv / 2 * sin(a * M_PI / 180);
				}
				else {
					p.x = x + ro * cos(a * M_PI / 180);
					p.y = y - ro * sin(a * M_PI / 180);
				}

				a = a + 180 / number_ver;
				add(p);
			}
		}
	};
}