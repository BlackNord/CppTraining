#pragma once

#include "../../Stroustruap_libs/GUI.h"

class My_window : public Graph_lib::Window {
public:
    My_window(Point xy, int w, int h, const string& title) :
        Window(xy, w, h, title),
        next_button(Point(x_max() - 70, 0), 70, 20, "Next", cb_next),
        quit_button(Point(x_max() - 70, 20), 70, 20, "Quit", cb_quit),
        button_pushed(false)
    {
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
    bool button_pushed;

    static void cb_next(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<My_window>(pw).next();
    }
    static void cb_quit(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<My_window>(pw).quit();
    }
    void next() {
        redraw();
    }
    void quit() {
        button_pushed = true;
        hide();
    }
};