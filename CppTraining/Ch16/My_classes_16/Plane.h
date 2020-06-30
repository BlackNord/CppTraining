#pragma once

#include "../../Stroustruap_libs/GUI.h"

class Plane : public Graph_lib::Window {
public:
    Plane(Point xy, int w = 600, int h = 600, const string& title = "Plane") :
        Window(xy, w, h, title),
        im{ xy, "Resourses/plane.jpg" },
        origin{ xy },
        quit_button(Point(x_max() - 70, 0), 70, 20, "Quit", cb_quit),
        start_button(Point(x_max() - 70, 20), 70, 20, "Start", cb_start),
        stop_button(Point(x_max() - 70, 40), 70, 20, "Stop", cb_stop),
        restart_button(Point(x_max() - 70, 60), 70, 20, "Restart", cb_restart),
        button_pushed(false),
        flying(false)
    {
        color(Graph_lib::Color::white);
        attach(quit_button);
        attach(start_button);
        attach(stop_button);
        attach(restart_button);
        attach(im);
    }

    bool wait_for_button() {
        show();
        button_pushed = false;
#if 1
        // Simpler handler
        while (!button_pushed) {
            Fl::wait();
            if (flying) {
                Sleep(70);
                fly();
            }
        }
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
    Graph_lib::Button start_button;
    Graph_lib::Button stop_button;
    Graph_lib::Button restart_button;
    Graph_lib::Image im;
    bool button_pushed;
    bool flying;
    Point origin;

    void fly() {
        im.move(40, 20);
        redraw();
    }

    static void cb_quit(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Plane>(pw).quit();
    }

    static void cb_start(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Plane>(pw).start();
    }

    static void cb_stop(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Plane>(pw).stop();
    }

    static void cb_restart(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Plane>(pw).restart();
    }

    void quit() {
        button_pushed = true;
        hide();
    }

    void start() {
        flying = true;
    }

    void stop() {
        flying = false;
    }
    
    void restart() {
        im.move(origin.x - im.point(0).x, origin.y - im.point(0).y);
        redraw();
    }
};