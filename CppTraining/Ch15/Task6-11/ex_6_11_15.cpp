#include "ex_6_11_15.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include <vector>

namespace myGraph_lib {
    class Bargrame : public Graph_lib::Shape{
    private:
        vector<double> vec;
        Point orig;
        Graph_lib::Open_polyline op;
        Graph_lib::Vector_ref<Graph_lib::Text> txt;
        Graph_lib::Vector_ref<Graph_lib::Text> val_t;
        int scale;

    public:
        Bargrame(const vector<double>& _vec, const vector<string>& _val, Point _orig, int _scale) : vec{ _vec }, orig{ _orig }, scale{ _scale } {
            if (_vec.size() != _val.size()) error("check values");

            int cur_pos_x{ orig.x + 1 }, fix_stepx{ 50 };
            int cur_pos_y{ orig.y };
            int label_pos{ 0 };

            for (int i{ 0 }; i < vec.size(); ++i) {
                op.add(Point{ cur_pos_x, cur_pos_y });
                cur_pos_y = orig.y - vec[i] * scale;
                op.add(Point{ cur_pos_x, cur_pos_y });
                txt.push_back(new Graph_lib::Text{ Point{cur_pos_x, cur_pos_y}, _val[i] });
                val_t.push_back(new Graph_lib::Text{ Point{orig.x - 20, cur_pos_y}, to_string(int(vec[i])) });
                cur_pos_x += fix_stepx;
                op.add(Point{ cur_pos_x, cur_pos_y });
                cur_pos_y = orig.y;
                op.add(Point{ cur_pos_x, cur_pos_y });
                
            }
        }

        virtual void draw_lines() const override {
            op.draw_lines();
            for (int i{ 0 }; i < txt.size(); ++i) {
                txt[i].draw_lines();
                val_t[i].draw_lines();
            }
        }
    };
}

void ex_6_11_15() {
    int height{ 600 };
    int width{ 600 };
    int length{ 400 };
    int num_of_steps{ 20 };

    Simple_window win{ Point {20, 50 }, height, width, "Gistogramms" };

    Graph_lib::Axis ox{ Graph_lib::Axis::x, Point{(height - length)/2, width - (width - length) / 2}, length, num_of_steps, "X" };
    ox.set_color(Graph_lib::Color::red);
    ox.label.set_color(Graph_lib::Color::black);
    ox.label.move(240, 0);
    win.attach(ox);

    Graph_lib::Axis oy{ Graph_lib::Axis::y, Point{(height - length) / 2, width - (width - length) / 2}, length, num_of_steps, "Y" };
    oy.set_color(Graph_lib::Color::red);
    oy.label.set_color(Graph_lib::Color::black);
    oy.label.move(-10, 40);
    win.attach(oy);

    Point orig{ (height - length) / 2 , width - (width - length) / 2 };
    
    vector<double> num = { 7, 9, 23, 17, 6, 1 };
    vector<string> val = { "170", "175", "180", "185", "190", "195" };

    myGraph_lib::Bargrame gsg1(num, val, orig, 10);
    gsg1.set_color(Graph_lib::Color::black);
    win.attach(gsg1);

    win.wait_for_button();
}