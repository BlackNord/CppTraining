#include "ex_7_8_17.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

void clear_cin() {
    cin.clear();
    while (cin.get() != '\n');
}

char* add(char* _old, char ch) {
    if (_old == nullptr) {
        char* _new = new char[2];
        _new[0] = ch;
        _new[1] = '\0';
        return _new;
    }
    else {
        int size{ 0 };
        for (; _old[size] != '\0'; ++size);
        
        char* _new = new char[size + 2];

        for (int i{ 0 }; i < size; ++i) {
            _new[i] = _old[i];
        }
        _new[size] = ch;
        _new[size + 1] = '\0';

        delete[] _old;
        return _new;
    }
}

void ex_7_8_17() {
    char temp;

    cout << "Enter your text1\n";

    char* str = nullptr;
    do {
        temp = getchar();
        if (temp == '!') break;
        str = add(str, temp);
    } while (true);

    cout << str << endl;

    delete[] str;

    cout << "Enter your text2\n";
    string str_2{};

    clear_cin();

    do {
        temp = getchar();
        if (temp == '!') break;
        str_2.push_back(temp);
    } while (true);
    
    cout << str_2 << endl;
}