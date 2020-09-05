#include "raii_test.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

class Reader {
public:
    Reader() {
        in1.open("F:\\Programms\\Visual Studio 2019\\Projects\\CppTraining\\CppTraining\\Ch18\\RAII_test\\1.txt");
        in0.open("F:\\Programms\\Visual Studio 2019\\Projects\\CppTraining\\CppTraining\\Ch18\\RAII_test\\0.txt");
    }

    void testing() {
        string buf1{}, buf0{};

        if (in1.is_open()) {
            in1 >> buf1;
        }
        if (buf1[0] == '0') throw runtime_error("1");

        if (in0.is_open()) {
            in0 >> buf0;
        }
        if (buf0[0] == '0') throw runtime_error("0");
    }

    ~Reader() {
        in0.close();
        cout << "in0.close" << endl;
        in1.close();
        cout << "in1.close" << endl;
    }
private:
    ifstream in1, in0;
};

class Reader1 {
public:
    Reader1() {
        in0.open("F:\\Programms\\Visual Studio 2019\\Projects\\CppTraining\\CppTraining\\Ch18\\RAII_test\\0.txt");
    }

    void testing() {
        string buf0{};

        if (in0.is_open()) {
            in0 >> buf0;
        }
        if (buf0[0] == '0') throw runtime_error("0");
    }

    ~Reader1() {
        in0.close();
        cout << "in0.close" << endl;
    }
private:
    ifstream in0;
};

void raii_test() {
    try {
        Reader obj;
        // Reader1 obj;
        obj.testing();
    }
    catch (const exception& ex) {
        cout << "Error: " << ex.what() << endl;
        keep_window_open();
    }

    cout << "Ending" << endl;
}