#pragma once

#include "../../Stroustruap_libs/GUI.h"
#include "Calculator_back.h"

class Calculator : public Graph_lib::Window {
public:
    Calculator(Point xy, int w = 600, int h = 200, const string& title = "Calculator") :
        Window(xy, w, h, title),
        origin{ xy },
        quit_button(Point(x_max() - 70, 0), 70, 20, "Quit", cb_quit),
        next_button(Point(x_max() - 70, 20), 70, 20, "Next", cb_next),
        button_pushed(false),
        sh{ false },
        in_put{ Point{ 70, 50 }, 400, 20, "Enter:" },
        out_put{ Point{ 70, 100 }, 100, 20, "Result:" },
        t{ Point{ 70, 150 }, "Warning! This version works only with int-type values, ; in the end!!!" }
    {
        attach(quit_button);
        attach(next_button);
        attach(in_put);
        attach(out_put);
        t.set_color(Graph_lib::Color::black);
        attach(t);
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
    Graph_lib::Button next_button;
    Graph_lib::In_box in_put;
    Graph_lib::Out_box out_put;
    bool button_pushed;
    bool sh;
    Point origin;
    Graph_lib::Text t;

    static void cb_quit(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Calculator>(pw).quit();
    }

    static void cb_next(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Calculator>(pw).next();
    }

    void quit() {
        button_pushed = true;
        hide();
    }

    void next() {
        if (!sh) {
            calculator::calculate();
            sh = true;
        }
        string value = in_put.get_string();
        if (!value.size() == 0) {
            ostringstream so;
            so << calculator::calcul(value);
            out_put.put(so.str());
        }
    }
};