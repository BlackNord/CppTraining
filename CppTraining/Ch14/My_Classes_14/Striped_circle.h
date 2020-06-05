#pragma once
#include "../../Stroustruap_libs/Graph.h"

namespace myGraph_lib {
	class Striped_circle : public Graph_lib::Circle {
	private:
		Graph_lib::Lines lins;
	public:
		Striped_circle(Point _p, int _r) : Circle(_p, _r) {}

		void set_striped(int step) {
			int temp_x;
			for (int y = center().y - radius() + step; y != center().y + radius(); y += step) {
				temp_x = pow(pow(radius(), 2) - pow(y - center().y, 2), 0.5) + center().x;
				lins.add(Point{ center().x - (temp_x - center().x), y }, Point{ temp_x, y });
			}
		}

		virtual void draw_lines() const override {
			Circle::draw_lines();
			lins.draw_lines();
		}
	};
}