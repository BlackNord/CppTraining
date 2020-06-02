#pragma once

#include <iostream>
#include "../../Stroustruap_libs/Graph.h"
#include "../../Stroustruap_libs/Simple_window.h"

class Controller {
private:
    bool status;
    int level;
public:
    bool get_status() { return status; }
    int get_level() { return level; }
    Controller() : status{ false }, level{ 0 } {}
    virtual void on() { status = true; }
    virtual void off() { status = false; }
    virtual void set_level(int _arg) { level = _arg; }
    virtual void show() = 0;
};

class Controller_info : public Controller {
public:
    virtual void show() override {
        using namespace std;

        cout << "Status: ";
        if (get_status()) cout << "On\n";
        else cout << "Of\n";

        cout << "Level: ";
        cout << get_level() << endl;
    }
};

class Controller_color : public Controller_info {
    void change_color(Graph_lib::Shape& obj) {
        if (get_status()) {
            obj.set_color(Graph_lib::Color(get_level()));
        }
    }
};