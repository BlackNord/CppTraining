#pragma once
#include "../../Stroustruap_libs/Graph.h"
#include "Arc.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

namespace myGraph_lib {
	class Box : public Graph_lib::Shape {
	private:
		Point point;
		int weight;
		int height;
		int rad;
	public:
		Point get_point() { return point; }
		int get_weight() { return weight; }
		int get_height() { return height; }
		int get_rad() { return rad; }
		Box(Point _point, int _weight, int _height, int _rad) : point{ _point }, weight{ _weight }, height{ _height } { 
			if (_rad > weight or _rad > height) error("Bad rad");
			else rad = _rad;
		}
		inline void draw_lines() const override;
	};

	void Box::draw_lines() const {
		fl_arc(point.x, point.y, rad*2, rad*2, 90, 180);
		fl_line(point.x, point.y + rad, point.x, point.y + height);
		fl_line(point.x + rad, point.y, point.x + rad + weight, point.y);
		fl_arc(point.x + weight, point.y, rad*2, rad*2, 0, 90);
		fl_line(point.x + weight + rad*2, point.y + rad, point.x + rad*2 + weight, point.y + height);
		fl_line(point.x + rad, point.y + height + rad, point.x + rad + weight, point.y + height + rad);
		fl_arc(point.x + weight, point.y + height - rad, rad * 2, rad * 2, 270, 360);
		fl_arc(point.x, point.y + height - rad, rad * 2, rad * 2, 180, 270);
	}
}