#pragma once

#include "../../Stroustruap_libs/GUI.h"
#include "../../Ch13/My_Classes/Arrow.h"
#include "Windows.h"

namespace myGraph_lib {
    class mLine : public Graph_lib::Line {
    public:
        mLine(Point _p1, Point _p2) : Line(_p1, _p2) { }

        void rotate(Point _new) {
            set_point(1, _new);
        }

        virtual void draw_lines() const override {
            Line::draw_lines();
        }
    };
}

class Clock : public Graph_lib::Window {
public:
    Clock(Point xy, int w = 600, int h = 600, const string& title = "Clock") :
        Window(xy, w, h, title),
        quit_button(Point(x_max() - 70, 0), 70, 20, "Quit", cb_quit),
        button_pushed(false),
        c_l{ Point{ x_max() / 2, y_max() / 2 }, (x_max() - x_max() / 3)/2 },
        c_b{ Point{ x_max() / 2, y_max() / 2 }, (x_max() - x_max() / 8)/2 },
        h_s{ Point{ x_max() / 2, y_max() / 2 }, Point{  0, 0 } },
        m_s{ Point{ x_max() / 2, y_max() / 2 }, Point{  0, 0 } },
        s_s{ Point{ x_max() / 2, y_max() / 2 }, Point{  0, 0 } },
        t12{ Point{ x_max() / 2 - 30, y_max() / 2 - (x_max() - x_max() / 8) / 2 + 60}, "XII" },
        t3{ Point{ x_max() / 2 + (x_max() - x_max() / 8) / 2 - 60, y_max() / 2 + 20}, "III" },
        t6{ Point{ x_max() / 2 - 30, y_max() / 2 + (x_max() - x_max() / 8) / 2 - 5}, "VI" },
        t9{ Point{ x_max() / 2 - (x_max() - x_max() / 8) / 2, y_max() / 2 + 20}, "IX" }
    {
        attach(quit_button);

        t12.set_font_size(60);
        t12.set_color(Graph_lib::Color::black);
        attach(t12);
        t3.set_font_size(60);
        t3.set_color(Graph_lib::Color::black);
        attach(t3);
        t6.set_font_size(60);
        t6.set_color(Graph_lib::Color::black);
        attach(t6);
        t9.set_font_size(60);
        t9.set_color(Graph_lib::Color::black);
        attach(t9);

        h_s.rotate(new_point(&h_s, to_angle_from_h() - M_PI / 2));
        h_s.set_color(Graph_lib::Color::black);
        h_s.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 7));
        attach(h_s);

        m_s.rotate(new_point(&m_s, to_angle_from_m() - M_PI / 2));
        m_s.set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 4));
        m_s.set_color(Graph_lib::Color::black);
        attach(m_s);

        s_s.rotate(new_point(&s_s, to_angle_from_s() - M_PI / 2));
        s_s.set_color(Graph_lib::Color::black);
        attach(s_s);

        c_l.set_color(Graph_lib::Color::black);
        attach(c_l);

        c_b.set_color(Graph_lib::Color::black);
        attach(c_b);
    }

    bool wait_for_button() {
        show();
        button_pushed = false;
#if 1
        // Simpler handler
        while (!button_pushed) {
            Fl::wait();
            Sleep(1000);
            time();
            Fl::redraw();
            
        }
#else
        // To handle the case where the user presses the X button in the window frame
        // to kill the application, change the condition to 0 to enable this branch.
        Fl::run();
#endif
        return button_pushed;
    }

private:
    myGraph_lib::mLine h_s, m_s, s_s;
    Graph_lib::Circle c_l, c_b;

    Graph_lib::Button quit_button;
    bool button_pushed;

    Graph_lib::Text t12;
    Graph_lib::Text t3;
    Graph_lib::Text t6;
    Graph_lib::Text t9;

    void time() {
        h_s.rotate(new_point(&h_s, to_angle_from_h() - M_PI / 2));
        m_s.rotate(new_point(&m_s, to_angle_from_m() - M_PI / 2));
        s_s.rotate(new_point(&s_s, to_angle_from_s() - M_PI / 2));
        attach(h_s);
        attach(m_s);
        attach(s_s);
    }
  
    double to_angle_from_h() {
        SYSTEMTIME st;
        GetSystemTime(&st);
        st.wHour += 3;
        return (360 * st.wHour / 12) * M_PI / 180;
    }

    double to_angle_from_m() {
        SYSTEMTIME st;
        GetSystemTime(&st);
        return (360 * st.wMinute / 60) * M_PI / 180;
    }

    double to_angle_from_s() {
        SYSTEMTIME st;
        GetSystemTime(&st);
        return (360 * st.wSecond / 60) * M_PI / 180;
    }

    Point new_point(myGraph_lib::mLine *l, double angle) {
        Point new_p;

        new_p.x = 200 * cos(-angle) + l->point(0).x;
        new_p.y = -200 * sin(-angle) + l->point(0).y;

        return new_p;
    }

    static void cb_quit(Graph_lib::Address, Graph_lib::Address pw) {
        Graph_lib::reference_to<Clock>(pw).quit();
    }

    void quit() {
        button_pushed = true;
        hide();
    }
};