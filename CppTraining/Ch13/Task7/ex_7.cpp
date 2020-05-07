#include "ex_7.h"
#include <omp.h>
#include <thread>
#include <mutex>
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"

mutex m1;

using namespace std;

void th_1(Simple_window & win, Graph_lib::Vector_ref<Graph_lib::Circle> & vr, int cellSize) {

    for (int g = 0; g < 256; ++g) {
        for (int b = 0; b < 256; ++b) {
            vr.push_back(new Graph_lib::Circle(Point(b, g), cellSize));
            vr[vr.size() - 1].set_fill_color(fl_rgb_color(0, g, b));
            vr[vr.size() - 1].set_color(Graph_lib::Color::invisible);
            m1.lock();
            win.attach(vr[vr.size() - 1]);
            m1.unlock();
        }
    }
}

void th_2(Simple_window& win, Graph_lib::Vector_ref<Graph_lib::Circle>& vr, int cellSize) {
    for (int r = 0; r < 256; ++r) {
        for (int b = 256+2; b < 256 * 2; ++b) {
            vr.push_back(new Graph_lib::Circle(Point(b, r), cellSize));
            vr[vr.size() - 1].set_fill_color(fl_rgb_color(r, 0, b));
            vr[vr.size() - 1].set_color(Graph_lib::Color::invisible);
            m1.lock();
            win.attach(vr[vr.size() - 1]);
            m1.unlock();
        }
    }
}

void th_3(Simple_window& win, Graph_lib::Vector_ref<Graph_lib::Circle>& vr, int cellSize) {
    for (int g = 0; g < 256; ++g) {
        for (int r = 256 * 2 + 2; r < 256 * 3; ++r) {
            vr.push_back(new Graph_lib::Circle(Point(r, g), cellSize));
            vr[vr.size() - 1].set_fill_color(fl_rgb_color(r, g, 0));
            vr[vr.size() - 1].set_color(Graph_lib::Color::invisible);
            m1.lock();
            win.attach(vr[vr.size() - 1]);
            m1.unlock();
        }
    }
}

void ex_7() {
	Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_7" };

    Graph_lib::Vector_ref<Graph_lib::Circle> vr1;
    Graph_lib::Vector_ref<Graph_lib::Circle> vr2;
    Graph_lib::Vector_ref<Graph_lib::Circle> vr3;

    int cellSize{ 2 };
    
    thread th1(th_1, ref(win), ref(vr1), cellSize);
    thread th2(th_2, ref(win), ref(vr2), cellSize);
    thread th3(th_3, ref(win), ref(vr3), cellSize);
    /*thread th1([&win, &vr1, &cellSize]() {th_2(win, vr1, cellSize); });
    thread th2([&win, &vr2, &cellSize]() {th_2(win, vr2, cellSize); });
    thread th3([&win, &vr3, &cellSize]() {th_3(win, vr3, cellSize); });*/

    th1.join();
    th2.join();
    th3.join();

    win.wait_for_button();
}