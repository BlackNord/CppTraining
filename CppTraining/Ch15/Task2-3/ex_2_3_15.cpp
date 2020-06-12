#include "ex_2_3_15.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

struct Funct : Graph_lib::Shape {
private:
    double r1, r2, xscale, yscale;
    Point xy;
    int count, perception;
    string percept(const string& _str, int pers) {
        string str;

        int i{ 0 };
        for (; i < _str.length(); ++i) {
            str.push_back(_str[i]);
            if (_str[i] == '.') {
                break;
            }
        }

        for (int j{ i+1 }; j < i + pers; ++j) {
            str.push_back(_str[j]);
        }

        return str;
    }
public:
    Funct(Graph_lib::Fct f, double _r1, double _r2, Point _xy, int _count, double _xscale, double _yscale, int _perception) {
        if (_r2 - _r1 <= 0) error("bad graphing range");
        if (_count <= 0) error("non-positive graphing count");
        if (_perception < 0 or _perception > 8) error("non-positive graphing count");

        r1 = _r1;
        r2 = _r2;
        xscale = _xscale;
        yscale = _yscale;
        xy = _xy;
        count = _count;
        perception = _perception;

        double dist = (r2 - r1) / count;
        double r = r1;

        double temp;
        string str_temp;

        for (int i = 0; i < count; ++i) {
            temp = f(r);
            str_temp = to_string(temp);
            str_temp = percept(str_temp, perception);
            temp = atof(str_temp.c_str()); 
            add(Point(xy.x + int(r * xscale), xy.y - int(temp * yscale)));
            r += dist;
        }
    }

    Point get_xy() { return xy; }
    int get_count() { return count; }
    double get_r1() { return r1; }
    double get_r2() { return r2; }
    double get_xscale() { return xscale; }
    double get_yscale() { return yscale; }
};

void ex_2_3_15() {
    int height{ 600 };
    int width{ 600 };
    int length{ 400 };

    Simple_window win{ Point {20, 50 }, height, width, "Graphics of the functions" };

    Graph_lib::Axis ox{ Graph_lib::Axis::x, Point{(height - length)/2, width/2}, length, 20, "X" };
    ox.set_color(Graph_lib::Color::red);
    ox.label.set_color(Graph_lib::Color::black);
    ox.label.move(-120, -40);
    win.attach(ox);

    Graph_lib::Axis oy{ Graph_lib::Axis::y, Point{height/2, width - (width - length) / 2}, length, 20, "Y" };
    oy.set_color(Graph_lib::Color::red);
    oy.label.set_color(Graph_lib::Color::black);
    oy.label.move(-10, 40);
    win.attach(oy);

    Point orig{ height / 2 , width / 2 };
    double r_min{ -10 }, r_max{ 11 };
    int number_of_points{ 400 };

    Funct f1{ sin, r_min, r_max, orig, number_of_points, 20, 20, 5};
    f1.set_color(Graph_lib::Color::black);
    win.attach(f1);

    win.wait_for_button();
}