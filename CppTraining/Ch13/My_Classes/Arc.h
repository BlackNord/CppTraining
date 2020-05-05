#pragma once
#include "../../Stroustruap_libs/Graph.h"
namespace myGraph_lib {
	class Arc : public Graph_lib::Ellipse {
	public:
		Arc(Point _point, int _weight, int _height, int _from, int _to) : Ellipse(_point, _weight, _height), from{ _from }, to{ _to } {}
		inline void draw_lines() const override;
	private:
		int from;
		int to;
	};

	void Arc::draw_lines() const {
		fl_arc(point(0).x, point(0).y, major() * 2, minor() * 2, from, to);
	}
}