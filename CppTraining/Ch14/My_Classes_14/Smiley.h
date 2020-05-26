#pragma once
#include "../../Stroustruap_libs/Graph.h"
#include "../../Ch13/My_Classes/Arc.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

namespace myGraph_lib {
	class Smiley : public Graph_lib::Circle {
	private:
		Graph_lib::Circle left;
		Graph_lib::Circle right;
		myGraph_lib::Arc happy;
	public:
		Smiley(Point _point, int _radius) : happy(_point, _radius / 2, _radius / 2, 240, 300),
			Circle(_point, _radius),
			left{ Point{_point.x - _radius / 4, _point.y - _radius / 4}, _radius * 0.1 },
			right{ Point{_point.x + _radius / 4, _point.y - _radius / 4}, _radius * 0.1 } {
			left.set_color(color());
			right.set_color(color());
		}
		inline void draw_lines() const override;
		virtual void set_col(Graph_lib::Color col);
	};

	void Smiley::draw_lines() const {
		Circle::draw_lines();
		left.draw_lines();
		right.draw_lines();
		happy.draw_lines();
	}

	void Smiley::set_col(Graph_lib::Color col) {
		Graph_lib::Shape::set_color(col);
		left.set_color(col);
		right.set_color(col);
		happy.set_color(col);
	}
}