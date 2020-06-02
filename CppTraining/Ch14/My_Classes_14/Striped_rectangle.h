#pragma once
#include "../../Stroustruap_libs/Graph.h"

namespace myGraph_lib {
	class Striped_rectangle : public Graph_lib::Rectangle {
	private:
		Graph_lib::Lines lins;
	public:
		Striped_rectangle(Point _p, int _h, int _w) : Rectangle(_p, _h, _w) {}

		void set_striped(int step) {
			for (int y = point(0).y + step; y != point(0).y + height(); y += step) {
				lins.add(Point{point(0).x, y}, Point{ point(0).x + width()-1, y });
			}
		}

		virtual void draw_lines() const override {
			Rectangle::draw_lines();
			lins.draw_lines();
		}
	};
}