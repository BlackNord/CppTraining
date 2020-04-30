#define _USE_MATH_DEFINES

#include "ex_11.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include <cmath>
#include <memory>

template<class Type>
Type read_value(const string_view message) {
    Type v;
    cout << message << endl;
    cin >> v;
    if (!cin) throw runtime_error("Numeric value is expected");
    return v;
}

void ex_11() {
    int N = read_value<int>("Enter number of polygons");

	Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_11" };
	
	Point center(win.x_max() / 2, win.y_max() / 2);

    int R_0{ 50 };
    int x_t{ 0 }, y_t{ 0 };
    int angle = 0;                          // The angle of the regular polygon

    vector<unique_ptr<Graph_lib::Polygon>> pols{};

    for (int k{ 3 }; k < N+3; ++k) {
        unique_ptr<Graph_lib::Polygon> pol = make_unique<Graph_lib::Polygon>();

        x_t = 0;
        y_t = 0;
        angle = 0;

        for (int i{ 0 }; i < k; ++i) {
            x_t = center.x + R_0 * cos(angle * M_PI / 180);
            y_t = center.y + R_0 * sin(angle * M_PI / 180);
            angle = angle + 360 / k;            // Increase the angle by the angle of the regular polygon

            pol->add(Point{ x_t, y_t });
        }

        R_0 += 25; 

        pol->set_color(Graph_lib::Color::black);
        pols.push_back(move(pol));
    }

    for (const auto& u : pols) {
        win.attach(*u);
    }

	win.wait_for_button();
}