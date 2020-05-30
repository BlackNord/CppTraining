#pragma once

#include "../../Stroustruap_libs/Graph.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"
#include <cmath>
#include <corecrt_math_defines.h>

namespace myGraph_lib {
    class Octagon : public Graph_lib::Shape {
    private:
        int R_0;
        int x_t, y_t;
        int angle;
        int num_side = 8;
    public:
        Octagon(Point center, int _r) : R_0{ _r }, x_t{ 0 }, y_t{ 0 }, angle{ 0 } {
            for (int i{ 0 }; i < num_side; ++i) {
                x_t = center.x + R_0 * sin(angle * M_PI / 180);
                y_t = center.y + R_0 * cos(angle * M_PI / 180);
                angle = angle + 360 / num_side;
                add(Point{ x_t, y_t });
            }
        }
        void draw_lines() const override;
    };

    void Octagon::draw_lines() const {
        if (fill_color().visibility()) {
            fl_color(fill_color().as_int());
            fl_begin_complex_polygon();
            for (int i = 0; i < number_of_points(); ++i) {
                fl_vertex(point(i).x, point(i).y);
            }
            fl_end_complex_polygon();
            fl_color(color().as_int());   
        }

        if (color().visibility()) {
            Shape::draw_lines();
            fl_line(point(number_of_points() - 1).x, point(number_of_points() - 1).y, point(0).x, point(0).y);
        }
    }
}