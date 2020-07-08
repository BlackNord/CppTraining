#pragma once

#include "../../Stroustruap_libs/GUI.h"

class Plot_builder : public Graph_lib::Window {
private:
    double r_min{ -10 }, r_max{ 11 };
    int number_of_points{ 400 };
    Point orig{ x_max() / 2 , y_max() / 2 };
public:
    Plot_builder(Point xy, int w = 600, int h = 600, const string& title = "Plot") :
        Window(xy, w, h, title),
        origin{ xy },
        quit_button(Point(x_max() - 70, 0), 70, 20, "Quit", cb_quit),
        button_pushed(false),
        ox{ Graph_lib::Axis::x, Point{(x_max() - 400) / 2, y_max() / 2}, 400, 20, "X" },
        oy{ Graph_lib::Axis::y, Point{x_max() / 2, y_max() - (y_max() - 400) / 2}, 400, 20, "Y" }, 
        menu{ Point{ 0, y_max() - 60 }, 70, 20, Graph_lib::Menu::vertical, "Functions" },
        menu_button{ Point{ 0, y_max() - 60}, 80, 20, "Functions", cb_menu },
        _sin{ sin, r_min, r_max, orig, number_of_points, 20, 20 },
        _cos{ cos, r_min, r_max, orig, number_of_points, 20, 20 }, 
        _log{ log, r_min, r_max, orig, number_of_points, 20, 20 }
    {
        attach(quit_button);

        ox.set_color(Graph_lib::Color::red);
        ox.label.set_color(Graph_lib::Color::black);
        ox.label.move(-120, -40);
        attach(ox);

        oy.set_color(Graph_lib::Color::red);
        oy.label.set_color(Graph_lib::Color::black);
        oy.label.move(-10, 40);
        attach(oy);

        menu.attach(new Graph_lib::Button{ Point{ 0, 0 }, 0, 0, "Sin()", cb_sin });
        menu.attach(new Graph_lib::Button{ Point{ 0, 0 }, 0, 0, "Cos()", cb_cos });
        menu.attach(new Graph_lib::Button{ Point{ 0, 0 }, 0, 0, "Log()", cb_log });
        attach(menu);
        menu.hide();
        attach(menu_button);

        _sin.set_color(Graph_lib::Color::black);
        _cos.set_color(Graph_lib::Color::dark_blue);
        _log.set_color(Graph_lib::Color::dark_green);
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
    bool button_pushed;
    Point origin;

    Graph_lib::Axis ox;
    Graph_lib::Axis oy;

    Graph_lib::Menu menu;
    Graph_lib::Button menu_button;

    Graph_lib::Function _sin;
    Graph_lib::Function _cos;
    Graph_lib::Function _log;

    void hide_menu() {
        menu.hide();
        menu_button.show();
    }
    void sin_pressed() {
        attach(_sin);
        detach(_cos);
        detach(_log);
        hide_menu();
    }
    void cos_pressed() {
        detach(_sin);
        attach(_cos);
        detach(_log);
        hide_menu();
    }
    void log_pressed() {
        detach(_sin);
        detach(_cos);
        attach(_log);
        hide_menu();
    }
    void menu_pressed() {
        menu_button.hide();
        menu.show();
    }

    static void cb_sin(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Plot_builder>(pw).sin_pressed();
    }
    static void cb_cos(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Plot_builder>(pw).cos_pressed();
    }
    static void cb_log(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Plot_builder>(pw).log_pressed();
    }
    static void cb_menu(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Plot_builder>(pw).menu_pressed();
    }

    static void cb_quit(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Plot_builder>(pw).quit();
    }

    void quit() {
        button_pushed = true;
        hide();
    }
};