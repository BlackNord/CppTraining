#pragma once

#include "../../Stroustruap_libs/Graph.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"
#include <set>

namespace myGraph_lib {
    struct mPoint {
        int x, y;
        mPoint(int xx, int yy) : x(xx), y(yy) { }
        mPoint() :x(0), y(0) { }

        bool operator <(const mPoint& obj) const {
            return this->x < obj.x and this->y < obj.y;
        }

        bool operator !=(const mPoint& obj) const {
            return this->x != obj.x and this->y != obj.y;
        }
    };

    class Poly : public Graph_lib::Shape {
    private:
        vector<mPoint> vc;
    public:
        template<typename... T>
        Poly(mPoint first, ...) {
            set<mPoint> vr;

            int counter{ 1 };

            va_list uk_arg;
            va_start(uk_arg, first);
            vr.insert(first);

            mPoint temp;

            while ((temp = va_arg(uk_arg, mPoint)) != mPoint{ -1,-1 }) {
                vr.insert(temp);
                counter++;
            }

            va_end(uk_arg);
  
            int set_s = vr.size();

            if (counter != set_s) error("Wrong figure");
            
            for (const auto & u : vr) {
                vc.push_back(mPoint{ u.x, u.y });
            }
        }

        inline void draw_lines() const override;
    };

    void Poly::draw_lines() const {
        fl_line(vc[0].x, vc[0].y, vc[vc.size()-1].x, vc[vc.size()-1].y);
        for (int i{ 1 }; i < vc.size(); ++i) {
            fl_line(vc[i].x, vc[i].y, vc[i-1].x, vc[i-1].y);
        }
    }
}