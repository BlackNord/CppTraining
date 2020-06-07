#include "ex_11_14_14.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../../Ch14/My_Classes_14/Binary_tree.h"
#include "../../Ch13/My_Classes/Arrow.h"

using namespace std;

void ex_11_14_14() {
    Simple_window win{ Point {20, 50 }, 1460, 750, "Ex_11_14_14" };

    myGraph_lib::Binary_tree<Graph_lib::Line> tree(6);
    tree.set_color(Graph_lib::Color::black);
    win.attach(tree);

    win.wait_for_button();
}