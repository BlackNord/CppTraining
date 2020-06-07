#pragma once

#include "../../Stroustruap_libs/Graph.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"
#include "../My_Classes/Box.h"

namespace myGraph_lib {
	class tBox : public Box {
	private:
		Graph_lib::Text t1;
	public:
		void set_text(const string& str) {
			t1.set_label(str);
		}

		string get_text() {
			return t1.label();
		}

		tBox(Point _point, int _weight, int _height, int _rad, const string& _text) : Box(_point, _weight, _height, _rad),
			t1{ Point{_point.x + (int)(0.3 * _weight), _point.y + (int)(0.9 * _height)}, _text } { }

		inline void draw_lines() const override;
		
	};

	void tBox::draw_lines() const {
		Box::draw_lines();
		fl_draw(t1.label().c_str(), t1.point(0).x, t1.point(0).y);
	}
}