#pragma once

#include "../../Stroustruap_libs/GUI.h"
#include "../../Stroustruap_libs/Graph.h"

class MoveFigure : public Graph_lib::Window {
private:
    Graph_lib::Circle c;
    Graph_lib::Button next_button;
    Graph_lib::Button quit_button;
    Graph_lib::In_box x;
    Graph_lib::In_box y;
    bool button_pushed;
public:
    MoveFigure(Point xy, int w, int h, const string& title) : Window(xy, w, h, title),
        c{ Point{x_max() / 2, y_max() / 2}, 50 },
        quit_button{ Point{ x_max() - 70, 0 }, 70, 20, "Quit",
            [](Graph_lib::Address, Graph_lib::Address pw) {
                Graph_lib::reference_to<MoveFigure>(pw).quit();
            }
        },
        next_button{ Point{ x_max() - 70, 20 }, 70, 20, "Next",
            [](Graph_lib::Address, Graph_lib::Address pw) {
                Graph_lib::reference_to<MoveFigure>(pw).next();
            }
            },
                x{ Point{ x_max() - 310, 0 }, 50, 20, "next x:" },
                y{ Point{ x_max() - 210, 0 }, 50, 20, "next y:" }
            {
                c.set_color(Graph_lib::Color::black);
                attach(c);
                attach(x);
                attach(y);
                attach(next_button);
                attach(quit_button);
            }

            void quit() {
                button_pushed = true;
                hide();
            }

            void next() {
                c.move(-c.center().x + x.get_int(), -c.center().y + y.get_int());
                redraw();
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
};