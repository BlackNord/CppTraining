#pragma once
#include "../../Stroustruap_libs/Graph.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

namespace myGraph_lib {
	class Immobile_Circle : public Graph_lib::Circle {
	public:
		Immobile_Circle(Point _point, int _radius) : Circle(_point, _radius) { }
		virtual void move(int x, int y) override;
	};
	void Immobile_Circle::move(int x, int y) {

	}
}