#include "ex_1_14.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../My_Classes_14/Frowny.h"
#include "../My_Classes_14/Smiley.h"
#include "../My_Classes_14/Frowny_h.h"
#include "../My_Classes_14/Smiley_h.h"

using namespace std;

void ex_1_14() {
    Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_1_14" };

    //myGraph_lib::Fronwy f1(Point{ 300,300 }, 50);
    myGraph_lib::Fronwy_h f1(Point{ 300,300 }, 50);
    f1.set_col(Graph_lib::Color::black);
    win.attach(f1);

    //myGraph_lib::Smiley f2(Point{ 600,300 }, 50);
    myGraph_lib::Smiley_h f2(Point{ 600,300 }, 50);
    f2.set_col(Graph_lib::Color::black);
    win.attach(f2);

    win.wait_for_button();
}