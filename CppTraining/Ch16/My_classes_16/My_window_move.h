#pragma once

#include "../../Stroustruap_libs/GUI.h"
#include <random>

class My_window_move : public Graph_lib::Window {
public:
    My_window_move(Point xy, int w, int h, const string& title) :
        Window(xy, w, h, title),
        next_button(Point(x_max() / 2, y_max() / 2), 146, 64, "Next", cb_next),
        quit_button(Point(x_max() - 70, 0), 70, 20, "Quit", cb_quit),
        im(Point(x_max() / 2, y_max() / 2), "Resourses/run.jpg"),
        button_pushed(false)
    {
        attach(im);
        attach(next_button);
        attach(quit_button);
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
    Graph_lib::Button next_button;
    Graph_lib::Button quit_button;
    Graph_lib::Image im;
    bool button_pushed;

    int r(int min, int max) {
        static default_random_engine ran;
        return uniform_int_distribution<>{min, max}(ran);
    }

    static void cb_next(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<My_window_move>(pw).next();
    }
    static void cb_quit(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<My_window_move>(pw).quit();
    }
    void next() {
        int x = r(0, 1300);
        int y = r(0, 700);
        im.move(-im.point(0).x + x, -im.point(0).y + y);
        next_button.move(-next_button.loc.x + x, -next_button.loc.y + y);
        redraw();
    }
    void quit() {
        button_pushed = true;
        hide();
    }
};