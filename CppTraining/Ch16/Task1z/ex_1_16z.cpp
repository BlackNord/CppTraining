#include "ex_1_16z.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

struct Lines_window : Graph_lib::Window {
    Lines_window(Point υσ, int w, int h, const string& title); 
    Graph_lib::Open_polyline lines; 
private: 
    Graph_lib::Button next_button;
    Graph_lib::Button quit_button; 

    Graph_lib::In_box next_x;
    Graph_lib::In_box next_y;
    Graph_lib::Out_box xy_out;

    Graph_lib::Menu color_menu;
    Graph_lib::Button menu_button;

    Graph_lib::Menu style_menu;
    Graph_lib::Button menu_s_button;

    void change(Graph_lib::Color c) { lines.set_color(c); }
    void hide_menu() { 
        color_menu.hide();
        menu_button.show();
    }
    void red_pressed() {
        change(Graph_lib::Color::red);
        hide_menu();
    }
    void blue_pressed() {
        change(Graph_lib::Color::blue);
        hide_menu();
    }
    void black_pressed() {
        change(Graph_lib::Color::black);
        hide_menu();
    }
    void menu_pressed() {
        menu_button.hide();
        color_menu.show();
    }

    void change_s(Graph_lib::Line_style c) { lines.set_style(c); }
    void hide_menu_s() {
        style_menu.hide();
        menu_s_button.show();
    }
    void dot_pressed() {
        change_s(Graph_lib::Line_style::dot);
        hide_menu_s();
    }
    void solid_pressed() {
        change_s(Graph_lib::Line_style::solid);
        hide_menu_s();
    }
    void dash_pressed() {
        change_s(Graph_lib::Line_style::dash);
        hide_menu_s();
    }
    void menu_s_pressed() {
        menu_s_button.hide();
        style_menu.show();
    }

    void next(); 
    void quit();

    static void cb_red(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Lines_window>(pw).red_pressed();
    }
    static void cb_blue(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Lines_window>(pw).blue_pressed();
    }
    static void cb_black(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Lines_window>(pw).black_pressed();
    }
    static void cb_menu(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Lines_window>(pw).menu_pressed();
    }

    static void cb_dot(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Lines_window>(pw).dot_pressed();
    }
    static void cb_solid(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Lines_window>(pw).solid_pressed();
    }
    static void cb_dash(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Lines_window>(pw).dash_pressed();
    }
    static void cb_menu_s(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Lines_window>(pw).menu_s_pressed();
    }
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title) : Window{ xy, w, h, title }, 
    next_button{ Point{ x_max() - 150, 0 }, 70, 20, "Next point",
        [](Graph_lib::Address, Graph_lib::Address pw) {
            Graph_lib::reference_to<Lines_window>(pw).next();
        }
    },
    quit_button{ Point{ x_max() - 70, 0 }, 70, 20, "Quit", 
        [](Graph_lib::Address, Graph_lib::Address pw) {
            Graph_lib::reference_to<Lines_window>(pw).quit();
        }
    },
    next_x{ Point{ x_max() - 310, 0 }, 50, 20, "next x:" },
    next_y{ Point{ x_max() - 210, 0 }, 50, 20, "next y:" },
    xy_out{ Point{ 100, 0 }, 100, 20, "current (x,y):" },
    color_menu{ Point{ x_max() - 70, 30 }, 70, 20, Graph_lib::Menu::vertical, "color" },
    menu_button{ Point{ x_max() - 80, 30}, 80, 20, "color menu", cb_menu },
    style_menu{ Point{ x_max() - 70, 120 }, 70, 20, Graph_lib::Menu::vertical, "style" },
    menu_s_button{ Point{ x_max() - 80, 120}, 80, 20, "style menu", cb_menu_s }
{
    lines.set_color(Graph_lib::Color::black);
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point"); 

    color_menu.attach(new Graph_lib::Button{ Point{ 0, 0 }, 0, 0, "red", cb_red });
    color_menu.attach(new Graph_lib::Button{ Point{ 0, 0 }, 0, 0, "blue", cb_blue });
    color_menu.attach(new Graph_lib::Button{ Point{ 0, 0 }, 0, 0, "black", cb_black });
    attach(color_menu); 
    color_menu.hide(); 
    attach(menu_button);

    style_menu.attach(new Graph_lib::Button{ Point{ 0, 0 }, 0, 0, "dot", cb_dot });
    style_menu.attach(new Graph_lib::Button{ Point{ 0, 0 }, 0, 0, "solid", cb_solid });
    style_menu.attach(new Graph_lib::Button{ Point{ 0, 0 }, 0, 0, "dash", cb_dash });
    attach(style_menu);
    style_menu.hide();
    attach(menu_s_button);

    attach(lines);
}

void Lines_window::quit() {
    hide();
}

void Lines_window::next() {
    int x = atoi(next_x.get_string().c_str());
    int y = atoi(next_y.get_string().c_str());
    lines.add(Point{ x,y });
    ostringstream ss; 
    ss << '(' << x << ',' << y << ')'; 
    xy_out.put(ss.str());
    redraw();
}

void ex_1_16z() {
    Lines_window win{ Point{100, 100}, 600, 400, "lines" };
    Graph_lib::gui_main();
}