#pragma once
#include "../../Stroustruap_libs/Graph.h"
#include <vector>

namespace myGraph_lib {
	class Striped_closed_polyline : public Graph_lib::Closed_polyline {
	private:
		Graph_lib::Lines lins;
		vector<Point> points;
	public:
		Striped_closed_polyline() : Closed_polyline() {}

		void set_striped(int step) {
			if (number_of_points() == 0) return;
			int y_min{ numeric_limits<int>::max() }, y_max{ numeric_limits<int>::min() };
			int x{ 0 };

			for (int i{ 0 }; i < number_of_points(); ++i) {
				if (point(i).y > y_max) y_max = point(i).y;
				if (point(i).y < y_min) y_min = point(i).y;
			}
			
			int k{ 0 };				// counter for lines
			int g{ 1 };
			for (int y{ y_min + step }; y < y_max; y += step) {		// down
				if (y > point(g).y) {
					k++;
					g++;
				}
				if (k == number_of_points() - 1) g = 0;
				x = (-y + point(k).y) * (point(g).x - point(k).x) / (-point(g).y + point(k).y) + point(k).x;
				points.push_back(Point{ x,y });
			}

			for (int y{ y_max - step }; y > y_min; y -= step) {		// up
				if (y < point(g).y) {
					k++;
					g++;
				}
				if (k == number_of_points() - 1) g = 0;
				x = (-y + point(k).y) * (point(g).x - point(k).x) / (-point(g).y + point(k).y) + point(k).x;
				
				points.push_back(Point{ x,y });
			}

			for (int i{ 0 }; i < points.size()/2-1; ++i) {
				lins.add(points[i], points[points.size() - i - 1]);
			}

			for (int i{ 0 }; i < points.size() - 1; ++i) {
				cout << points[i].x << " " << points[i].y << endl;
			}
		}

		virtual void draw_lines() const override {
			Closed_polyline::draw_lines();
			lins.draw_lines();
		}
	};
}