#pragma once

#include "../../Stroustruap_libs/Graph.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"
#include <cmath>
#include <corecrt_math_defines.h>

namespace myGraph_lib {
    class Regular_polygon : public Graph_lib::Polygon {
    private:
        int R_0;
        int x_t, y_t;
        int angle;
        int num_side;
    public:
        Regular_polygon(Point center, int _num_side, int _r) : R_0{ _r }, num_side{ _num_side }, x_t{ 0 }, y_t{ 0 }, angle{ 0 } {
            for (int i{ 0 }; i < num_side; ++i) {
                x_t = center.x + R_0 * sin(angle * M_PI / 180);
                y_t = center.y + R_0 * cos(angle * M_PI / 180);
                angle = angle + 360 / num_side;
                add(Point{ x_t, y_t });
            }
        }
    };
}