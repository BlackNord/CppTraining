#pragma once
#include "../../Stroustruap_libs/Graph.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"
#include "Frowny.h"
#include "../../Ch13/My_Classes/Arc.h"

namespace myGraph_lib {
	class Fronwy_h : public Fronwy {
	private:
		Graph_lib::Line l1;
		myGraph_lib::Arc a1;
	public:
		Fronwy_h(Point _point, int _radius) : Fronwy(_point, _radius), 
			l1{ Point{_point.x - _radius, _point.y - _radius}, Point{_point.x + _radius, _point.y - _radius} }, 
			a1{ Point{_point.x, _point.y - _radius}, _radius/2, _radius/2, 0, 180 } { }
		inline void draw_lines() const override;
		inline void set_col(Graph_lib::Color col) override;
	};

	void Fronwy_h::draw_lines() const {
		Fronwy::draw_lines();
		a1.draw_lines();
		fl_line(l1.point(0).x, l1.point(0).y, l1.point(1).x, l1.point(1).y);
	}

	void Fronwy_h::set_col(Graph_lib::Color col) {
		Fronwy::set_col(col);
		l1.set_color(col);
		a1.set_color(col);
	}
}