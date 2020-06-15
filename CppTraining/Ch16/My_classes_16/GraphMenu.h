#pragma once

#include "../../Stroustruap_libs/GUI.h"
#include "../../Ch13/My_Classes/Regular_polygon.h"

class GraphMenu : public Graph_lib::Window {
public:
    GraphMenu(Point xy, int w, int h, const string& title) : Window(xy, w, h, title),
        quit_button{ Point{ x_max() - 70, 0 }, 70, 20, "Quit",
            [](Graph_lib::Address, Graph_lib::Address pw) {
                Graph_lib::reference_to<GraphMenu>(pw).quit();
            }
    },
        graph_menu{ Point{ x_max() / 2, 0 }, 70, 20, Graph_lib::Menu::vertical, "figures" },
                x{ Point{ x_max() - 310, 0 }, 50, 20, "next x:" },
                y{ Point{ x_max() - 210, 0 }, 50, 20, "next y:" },
                button_pushed(false)
            {
                attach(x);
                attach(y);
                attach(quit_button);
                graph_menu.attach(new Graph_lib::Button{ Point{ 0, 0 }, 0, 0, "Circle", cb_circle });
                graph_menu.attach(new Graph_lib::Button{ Point{ 0, 0 }, 0, 0, "Square", cb_square });
                graph_menu.attach(new Graph_lib::Button{ Point{ 0, 0 }, 0, 0, "R triangle", cb_rtriangle });
                graph_menu.attach(new Graph_lib::Button{ Point{ 0, 0 }, 0, 0, "Hexagon", cb_hexagon });
                attach(graph_menu);
            }

            bool wait_for_button() {
                show();
                button_pushed = false;
#if 1
                // Simpler handler
                while (!button_pushed) Fl::wait();
                Fl::redraw();
#else
                // To handle the case where the user presses the X button in the window frame
                // to kill the application, change the condition to 0 to enable this branch.
                Fl::run();
#endif
                return button_pushed;
            }

private:
    Graph_lib::Button quit_button;
    Graph_lib::Menu graph_menu;
    Graph_lib::In_box x;
    Graph_lib::In_box y;
    bool button_pushed;

    void quit() {
        button_pushed = true;
        hide();
    }

    static void cb_circle(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<GraphMenu>(pw).circle_pressed();
    }
    static void cb_square(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<GraphMenu>(pw).square_pressed();
    }
    static void cb_rtriangle(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<GraphMenu>(pw).rtriangle_pressed();
    }
    static void cb_hexagon(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<GraphMenu>(pw).hexagon_pressed();
    }

    void circle_pressed() {
        attach(*(new Graph_lib::Circle{ Point{ x.get_int(), y.get_int() }, 50 }));
        redraw();
    }
    void square_pressed() {
        int side{ 100 };
        attach(*(new Graph_lib::Rectangle{ Point{ x.get_int() - side / 2, y.get_int() - side / 2 }, side, side }));
        redraw();
    }
    void rtriangle_pressed() {
        attach(*(new myGraph_lib::Regular_polygon{ Point{ x.get_int(), y.get_int() }, 3, 60 }));
        redraw();
    }
    void hexagon_pressed() {
        attach(*(new myGraph_lib::Regular_polygon{ Point{ x.get_int(), y.get_int() }, 6, 60 }));
        redraw();
    }
};