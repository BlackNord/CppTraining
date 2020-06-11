#include "ex_1_15z.h"
#include "../../Stroustruap_libs/Graph.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"
#include <vector>

double one(double x) {
    return 1;
}

double slope(double x) {
    return x/2;
}

double square(double x) {
    return x*x;
}

double sloping_cos(double x) {
    return slope(x) + cos(x);
}

struct Person {
private:
    int age;
    string first_name;
    string second_name;

    bool validation_s(const string & str) {
        string valid = ";:\"'[]*&\"%$#@!";

        for (int i{ 0 }; i < str.size(); ++i) {
            for (int j{ 0 }; j < valid.size(); ++j) {
                if (str[i] == valid[j]) return false;
            }
        }

        return true;
    }

    bool validation_i(int _age) {
        if (_age < 0 or _age >= 150) return false;
        return true;
    }

public:
    Person(const string& _first_name, const string& _second_name, int _age) {
        if (!validation_i(_age)) error("wrong age");
        age = _age;
        if (!validation_s(_first_name)) error("wrong name");
        first_name = _first_name;
        if (!validation_s(_second_name)) error("wrong name");
        second_name = _second_name;
    }

    Person() : age{ 0 }, first_name{ "" }, second_name{ "" } {}

    int get_age() const { return age; }

    string get_fname() const { return first_name; }

    string get_sname() const { return second_name; }

    void set_fname(const string & _name) {
        if (!validation_s(_name)) error("wrong name");
        first_name = _name;
    }

    void set_sname(const string& _name) {
        if (!validation_s(_name)) error("wrong name");
        second_name = _name;
    }

    void set_age(int _age) {
        if (!validation_i(_age)) error("wrong age");
        age = _age;
    }

    string get_str() const {
        return first_name + " " + second_name + " " + to_string(age);
    }

    friend ostream& operator <<(ostream& outstream, const Person& obj) {
        outstream << obj.get_str();
        return outstream;
    }

    friend istream& operator >>(istream& instream, Person& obj) {
        int _age;
        string _fname, _sname;

        instream >> _fname;
        if (!obj.validation_s(_fname)) error("wrong first name");
        obj.set_fname(_fname);

        instream >> _sname;
        if (!obj.validation_s(_sname)) error("wrong second name");
        obj.set_sname(_sname);

        instream >> _age;
        if (!obj.validation_i(_age)) error("wrong age");
        obj.set_age(_age);

        return instream;
    }
};

void ex_1_15z_2() {
    vector<Person> vec_p;

    for (int i{ 0 }; i < 3; ++i) {
        Person temp;
        cin >> temp;
        vec_p.push_back(temp);
    }

    for (const auto & it : vec_p) {
        cout << it << endl;
    }
}

void ex_1_15z() {
    int height{ 600 };
    int width{ 600 };
    int length{ 400 };

    Simple_window win{ Point {20, 50 }, height, width, "Graphics of the functions" };

    Graph_lib::Axis ox{ Graph_lib::Axis::x, Point{(height - length)/2, width/2}, length, 20, "X" };
    ox.set_color(Graph_lib::Color::red);
    ox.label.set_color(Graph_lib::Color::black);
    ox.label.move(-120, -40);
    win.attach(ox);

    Graph_lib::Axis oy{ Graph_lib::Axis::y, Point{height/2, width - (width - length) / 2}, length, 20, "Y" };
    oy.set_color(Graph_lib::Color::red);
    oy.label.set_color(Graph_lib::Color::black);
    oy.label.move(-10, 40);
    win.attach(oy);

    Point orig{ height / 2 , width / 2 };
    double r_min{ -10 }, r_max{ 11 };
    int number_of_points{ 400 };

    Graph_lib::Function f1{ one, r_min, r_max, orig, number_of_points, 20, 20 };
    f1.set_color(Graph_lib::Color::black);
    win.attach(f1);

    Graph_lib::Function f2{ slope, r_min, r_max, orig, number_of_points, 20, 20 };
    f2.set_color(Graph_lib::Color::black);
    win.attach(f2);

    Graph_lib::Text txt1(Point{ 75, width - 165 }, "x/2");
    txt1.set_color(Graph_lib::Color::black);
    win.attach(txt1);

    Graph_lib::Function f3{ square, r_min, r_max, orig, number_of_points, 20, 20 };
    f3.set_color(Graph_lib::Color::black);
    win.attach(f3);

    Graph_lib::Function f4{ sin, r_min, r_max, orig, number_of_points, 20, 20 };
    f4.set_color(Graph_lib::Color::black);
    win.attach(f4);

    Graph_lib::Function f5{ cos, r_min, r_max, orig, number_of_points, 20, 20 };
    f5.set_color(Graph_lib::Color::dark_blue);
    win.attach(f5);

    Graph_lib::Function f6{ sloping_cos, r_min, r_max, orig, number_of_points, 20, 20 };
    f6.set_color(Graph_lib::Color::black);
    win.attach(f6);

    win.wait_for_button();
}