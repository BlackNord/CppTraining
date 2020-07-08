#pragma once

#include "../../Stroustruap_libs/GUI.h"

// fix setting_curses (to double)

class dollar {
    double euro, rub;
public:
    dollar(double _euro, double _rub) : euro{ _euro }, rub{ _rub } {}
    dollar() : euro{ 0 }, rub{ 0 } {}
    double get_euro() {
        return euro;
    }
    double get_rub() {
        return rub;
    }
    void set_euro(double _euro) { euro = _euro; }
    void set_rub(double _rub) { rub = _rub; }
};

class euro {
    double dollar, rub;
public:
    euro(double _dollar, double _rub) : dollar{ _dollar }, rub{ _rub } {}
    euro() : dollar{ 0 }, rub{ 0 } {}
    double get_dollar() {
        return dollar;
    }
    double get_rub() {
        return rub;
    }
    void set_dollar(double _dollar) { dollar = _dollar; }
    void set_rub(double _rub) { rub = _rub; }
};

class rub {
    double dollar, euro;
public:
    rub(double _dollar, double _euro) : dollar{ _dollar }, euro{ _euro } {}
    rub() : dollar{ 0 }, euro{ 0 } {}
    double get_dollar(){ 
        return dollar; 
    }
    double get_euro() {
        return euro;
    }
    void set_dollar(double _dollar) { dollar = _dollar; }
    void set_euro(double _euro) { euro = _euro; }
};

class Convert : public Graph_lib::Window {
public:
    Convert(Point xy, int w = 600, int h = 150, const string& title = "Converter") :
        Window(xy, w, h, title),
        origin{ xy },
        next_button_d{ Point{ x_max() - 70, 90 }, 70, 20, "Result",
            [](Graph_lib::Address, Graph_lib::Address pw) {
                Graph_lib::reference_to<Convert>(pw).next_d();
            }
        },
        next_button_e{ Point{ x_max() - 70, 90 }, 70, 20, "Result",
            [](Graph_lib::Address, Graph_lib::Address pw) {
                Graph_lib::reference_to<Convert>(pw).next_e();
            }
        },
        next_button_r{ Point{ x_max() - 70, 90 }, 70, 20, "Result",
            [](Graph_lib::Address, Graph_lib::Address pw) {
                Graph_lib::reference_to<Convert>(pw).next_r();
            }
        },
        quit_button(Point(x_max() - 70, 0), 70, 20, "Quit", cb_quit),
        menu{ Point{ x_max() - 70, 30 }, 70, 20, Graph_lib::Menu::vertical, "Value" },
        menu_button{ Point{ x_max() - 70, 30}, 70, 20, "Menu", cb_menu },

        value_d{ Point{ 60, 0 }, 100, 20, "VDollar:" },
        result_de{ Point{ 220, 0 }, 100, 20, "Euro:" },
        result_dr{ Point{ 390, 0 }, 100, 20, "Rub:" },

        value_e{ Point{ 60, 0 }, 100, 20, "VEuro:" },
        result_ed{ Point{ 220, 0 }, 100, 20, "Dollar:" },
        result_er{ Point{ 390, 0 }, 100, 20, "Rub:" },

        value_r{ Point{ 60, 0 }, 100, 20, "VRub:" },
        result_rd{ Point{ 220, 0 }, 100, 20, "Dollar:" },
        result_re{ Point{ 390, 0 }, 100, 20, "Euro:" },

        c_dollar(),
        c_euro(),
        c_rub(),

        button_pushed(false)
    {
        setting_curses();
        attach(quit_button);
        attach(next_button_d);
        attach(next_button_e);
        next_button_e.hide();
        attach(next_button_r);
        next_button_r.hide();

        menu.attach(new Graph_lib::Button{ Point{ 0, 0 }, 0, 0, "dollar", cb_dollar });
        menu.attach(new Graph_lib::Button{ Point{ 0, 0 }, 0, 0, "euro", cb_euro });
        menu.attach(new Graph_lib::Button{ Point{ 0, 0 }, 0, 0, "rub", cb_rub });
        attach(menu);
        menu.hide();
        attach(menu_button);

        attach(value_d);
        attach(result_de);
        attach(result_dr);

        attach(value_e);
        value_e.hide();
        attach(result_ed);
        result_ed.hide();
        attach(result_er);
        result_er.hide();

        attach(value_r);
        value_r.hide();
        attach(result_rd);
        result_rd.hide();
        attach(result_re);
        result_re.hide();
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
    Graph_lib::Button next_button_d;
    Graph_lib::Button next_button_e;
    Graph_lib::Button next_button_r;
    Graph_lib::Menu menu;
    Graph_lib::Button menu_button;

    Graph_lib::In_box value_d;
    Graph_lib::Out_box result_de;
    Graph_lib::Out_box result_dr;

    Graph_lib::In_box value_e;
    Graph_lib::Out_box result_ed;
    Graph_lib::Out_box result_er;

    Graph_lib::In_box value_r;
    Graph_lib::Out_box result_rd;
    Graph_lib::Out_box result_re;

    dollar c_dollar;
    euro c_euro;
    rub c_rub;

    bool button_pushed;
    Point origin;

    void setting_curses() {
        string line;
        vector<string> lines;
        int i{ 0 };

        ifstream in("Resourses/curs.txt");
        if (in.is_open()) {
            while (getline(in, line)) {
                lines = split(line);
                if (i == 0) {
                    c_dollar.set_euro(atof(lines[0].c_str()));
                    c_dollar.set_rub(atof(lines[1].c_str()));
                }
                if (i == 1) {
                    c_euro.set_dollar(atof(lines[0].c_str()));
                    c_euro.set_rub(atof(lines[1].c_str()));
                }
                if (i == 2) {
                    c_rub.set_dollar(atof(lines[0].c_str()));
                    c_rub.set_euro(atof(lines[1].c_str()));
                }
                i++;
            }
        }
    }

    vector<string> split(const string& str) {
        vector<string> result;
        stringstream x;
        string buf;

        x << str;
        while (x >> buf) {
            //if (!isalpha(atoi(buf.c_str()))) error("Bad value");
            result.push_back(buf);
        }
        return result;
    }

    void hide_menu() {
        menu.hide();
        menu_button.show();
    }
    void dollar_pressed() { 
        value_d.show();
        result_de.show();
        result_dr.show();

        next_button_d.show();
        next_button_e.hide();
        next_button_r.hide();

        value_e.hide();       
        result_ed.hide();        
        result_re.hide();

        value_r.hide();        
        result_rd.hide();
        result_re.hide();

        hide_menu();
    }
    void euro_pressed() {
        value_e.show();
        result_ed.show();
        result_er.show();

        next_button_e.show();
        next_button_d.hide();
        next_button_r.hide();

        value_d.hide();
        result_de.hide();
        result_dr.hide();

        value_r.hide();
        result_rd.hide();
        result_re.hide();
        
        hide_menu();
    }
    void rub_pressed() {
        value_r.show();
        result_rd.show();
        result_re.show();

        next_button_r.show();
        next_button_d.hide();
        next_button_e.hide();

        value_d.hide();
        result_de.hide();
        result_dr.hide();

        value_e.hide();
        result_ed.hide();
        result_er.hide();
        
        hide_menu();
    }
    void menu_pressed() {
        menu_button.hide();
        menu.show();
    }

    static void cb_menu(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Convert>(pw).menu_pressed();
    }

    static void cb_dollar(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Convert>(pw).dollar_pressed();
    }

    static void cb_euro(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Convert>(pw).euro_pressed();
    }

    static void cb_rub(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Convert>(pw).rub_pressed();
    }

    static void cb_quit(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Convert>(pw).quit();
    }

    void quit() {
        button_pushed = true;
        hide();
    }

    void next_d() {
        double val = atof(value_d.get_string().c_str());
        ostringstream s1, s2;
        s1 << val * c_dollar.get_euro();
        result_de.put(s1.str());
       
        s2 << val * c_dollar.get_rub();    
        result_dr.put(s2.str());
        redraw();
    }

    void next_e() {
        double val = atof(value_e.get_string().c_str());
        ostringstream s1, s2;
        s1 << val * c_euro.get_dollar();
        result_ed.put(s1.str());
        
        s2 << val * c_euro.get_rub();
        result_er.put(s2.str());
        redraw();
    }

    void next_r() {
        double val = atof(value_r.get_string().c_str());
        ostringstream s1, s2;
        s1 << val * c_rub.get_dollar();
        result_rd.put(s1.str());

        s2 << val * c_rub.get_euro();
        result_re.put(s2.str());
        redraw();
    }
};