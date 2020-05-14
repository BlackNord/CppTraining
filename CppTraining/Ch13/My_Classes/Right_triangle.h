#pragma once

#include "../../Stroustruap_libs/Graph.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"
#include <cmath>
#include <corecrt_math_defines.h>

namespace myGraph_lib {
    class Right_triangle : public Graph_lib::Polygon {
    private:
        Point p;
        int kt1, kt2;
    public:
        Right_triangle(Point _p, int _kt1, int _kt2) : p{ _p }, kt1{ _kt1 }, kt2{ _kt2 } {
            Point p1{ p.x, p.y - kt1};
            Point p2{ p.x + kt2, p.y };

            add(p);
            add(p1);
            add(p2);
        }
    };
}