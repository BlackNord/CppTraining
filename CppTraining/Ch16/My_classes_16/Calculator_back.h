#pragma once

#include "../../Stroustruap_libs/std_lib_facilities_4.h"
#include <map>
#define _USE_MATH_DEFINES
#include <cmath>

namespace roman {
    int scaning(const string& s) {
        map<char, int> roman;
        int res = 0;

        roman['M'] = 1000;
        roman['D'] = 500;
        roman['C'] = 100;
        roman['L'] = 50;
        roman['X'] = 10;
        roman['V'] = 5;
        roman['I'] = 1;

        for (int i = 0; i < s.size() - 1; ++i) {
            if (roman[s[i]] < roman[s[i + 1]])
                res -= roman[s[i]];
            else
                res += roman[s[i]];
        }
        res += roman[s[s.size() - 1]];

        return res;
    }

    bool valid_number(const string& str) {
        string bd = { "IVXLCDM" };

        for (const auto& u : str) {
            if (find(bd.begin(), bd.end(), u) == bd.end())
                return false;
        }

        return true;
    }

    class Roman_int {
    private:
        int value;
        string number;
    public:
        Roman_int() : number{ 'O' }, value{ 0 } {}

        Roman_int(const string& number_) {
            if (!valid_number(number_))
                error("Wrong value");

            number = number_;
            value = scaning(number_);
        }

        int as_int() const {
            return value;
        }

        friend istream& operator >>(istream& in, Roman_int& obj) {
            string temp;
            in >> temp;
            if (valid_number(temp)) {
                obj.number = temp;
                obj.value = scaning(obj.number);
            }
            else error("Wrong value");

            return in;
        }

        friend ostream& operator <<(ostream& out, const Roman_int& obj) {
            out << obj.number;
            return out;
        }
    };
}

namespace calculator {
    //Symbolic constants-parametrs
    //-
    const char FROM = 'F';
    const char TO = 'T';
    //-
    const char LET = 'L';
    const char CONS_T = 'C';
    const char SQRT = 'S';
    const char POW = 'P';
    const char QUIT = 'Q';
    const char SIN = '1';
    const char COS = '0';
    const char PRINT = ';';
    const char NUMBER = '8';
    const char NAME = 'a';
    const char ASSIGN = '=';
    const char STR = '\n';
    const char HELP = 'h';
    const string prompt = "> ";
    const string result = "= ";


    //Token represents a single unit that calculator operates on
    struct Token {
        char kind;
        double value;
        string name;
        Token() {}
        Token(char ch) :kind(ch), value(0) { }
        Token(char ch, double val) :kind(ch), value(val) { }
        Token(char ch, string val) :kind(ch), name(val), value(0) { }
    };


    //Table of units of variable
    class Table {
    public:
        void set(string s, double v) {                         //Sets a new value for variables
            for (int i = 0; i <= var_names.size(); ++i) {
                if (var_names[i].name == s) {
                    if (var_names[i].constanta) {
                        error(s, " is a constantic value.");
                    }
                    var_names[i].value = v;
                    return;
                }
            }
            error("set: undefined name ", s);
        }

        double get(string s) {                               //Returns value of a variable
            for (int i = 0; i < var_names.size(); ++i) {
                if (var_names[i].name == s) {
                    return var_names[i].value;
                }
            }
            error("get: undefined name ", s);
        }

        void define(string s, double v, bool c) {           //Defines a new variable or constant
            if (is_declared(s)) {
                error(s, " already declared");
            }
            var_names.push_back(Variable(s, v, c));
        }

        bool is_declared(string s) {                       //Checks is variable is declared
            for (int i = 0; i < var_names.size(); ++i) {
                if (var_names[i].name == s) {
                    return true;
                }
            }
            return false;
        }

    private:
        //Unit of variable
        struct Variable {
            string name;
            double value;
            bool constanta;
            Variable(string n, double v, bool c) :name(n), value(v), constanta(c) { }
        };
        //vector of units
        vector<Variable> var_names;
    };


    //Variables table
    class Symbol_Table {
    public:
        double get_value(string s) {
            return var_table.get(s);
        }

        void set_value(string s, double v) {
            var_table.set(s, v);
        }

        void define_name(string s, double v, bool c) {
            var_table.define(s, v, c);
        }

        bool is_declared(string s) {
            try {
                return var_table.get(s);
            }
            catch (exception& e) {
                return false;
            }
        }

    private:
        Table var_table;
    };

    Symbol_Table symbols;


    //Returns tokens from stdin
    class Token_stream {
    public:
        bool full;
        Token buffer;
        istream& strm;

        Token_stream(istream& s_) :full(0), buffer(0), strm{ s_ } { }

        Token get();

        void unget(Token t) {
            buffer = t;
            full = true;
        }

        void ignore(char c, istream& cik) {
            if (full && c == buffer.kind) {
                full = false;
                return;
            }
            full = false;

            char ch;
            while (cik >> ch) {
                if (ch == c) {
                    return;
                }
            }
        }
    };

    //Helping
    void help() {
        cout << "Help\n";
        cout << "Warning! This version works only with int-type values\n";
        cout << "cos(val) - cosine\n"
            << "sin(val) - sinus\n"
            << "sqrt(val) - square root\n"
            << "pow(val, power) - sinus\n"
            << "+ - addition\n"
            << "- - subtraction\n"
            << "/ - division\n"
            << "* - multiplication\n"
            << "% - division without remainder\n"
            << "! - factorial\n"
            << "# - define/redefine variable\n"
            << "const - define constant\n"
            << "() - hooks\n"
            << "{} - hooks\n"
            << "exit - exit\n";
    }


    Token Token_stream::get() {
        if (full) {
            full = false;
            return buffer;
        }

        if (strm.eof()) {
            return Token(PRINT);
        }

        char ch;

        if (strm.get(ch) && ch == STR) {
            return Token(PRINT);
        }
        strm.unget();                        //push a symbol to stream

        strm >> ch;
        switch (ch) {
        case '(':
        case ')':
        case '{':
        case '}':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case ';':
        case '=':
        case ',':
        case '!':
            return Token(ch);
        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        {
            strm.unget();
            double val;
            strm >> val;
            return Token(NUMBER, narrow_cast<int>(val));
        }
        //-
        case 'I':
        case 'V':
        case 'X':
        case 'L':
        case 'C':
        case 'D':
        case 'M':
        {
            if (isalpha(ch)) {
                string s;
                s += ch;
                // read in all alphanumeric chars
                while (strm.get(ch) && isalpha(ch)) {
                    s += ch;
                }
                // put next non-alphanumeral back into stream
                strm.unget();

                roman::Roman_int num1(s);

                double val = num1.as_int();

                return Token(NUMBER, narrow_cast<int>(val));
            }
            error("Bad token");
        }
        //-
        default:
            if (isalpha(ch) || ch == '#' || ch == '_') {
                string s;
                s += ch;
                // read in all alphanumeric chars
                while (strm.get(ch) && (ch == '_' || isalpha(ch) || isdigit(ch))) {
                    s += ch;
                }
                // put next non-alphanumeral back into stream
                strm.unget();
                //-
                if (s == "from") return Token(FROM);
                if (s == "to") return Token(TO);
                //-
                if (s == "#") return Token(LET);
                if (s == "const") return Token(CONS_T);
                if (s == "sqrt") return Token(SQRT);
                if (s == "pow") return Token(POW);
                if (s == "sin") return Token(SIN);
                if (s == "cos") return Token(COS);
                if (s == "exit") return Token(QUIT);
                if (s == "H" or s == "h" or s == "help") return Token(HELP);
                return Token(NAME, s);
            }
            error("Bad token");
        }
    }

    //void clean_up_mess() {
    //    ts.ignore(PRINT);
    //}

    //-
    void to_file(double rez) {
        cout << "Enter the name of file to write\n";
        string fname;
        cin >> fname;

        ofstream fout(fname);
        if (fout.is_open()) {
            fout << rez;
            fout.close();
            cout << "Writing in file completed\n";
        }
        else cout << "Error of opening\n";

    }
    //-

    class calcul_logic {
    private:
        Token_stream ts;
    public:
        calcul_logic(istream& s) : ts{ Token_stream(s) } {}

        Token ts_get() {
            return ts.get();
        }

        void ts_unget(Token t) {
            ts.unget(t);
        }

        double primary() {
            Token t = ts.get();
            switch (t.kind) {
            case '(': {
                double d = expression();
                t = ts.get();
                if (t.kind != ')') error("')' expected");
                return d;
            }
            case '{': {
                double d = expression();
                t = ts.get();
                if (t.kind != '}') error("'}' expected");
                return d;
            }
            case '-':
                return -primary();
            case NUMBER:
                return t.value;
            case NAME:
                return symbols.get_value(t.name);
            default:
                exit(0);
                error("primary expected");
            }
        }

        //checking on the diapazon of result
        void check_on_diapazon_i(long int num) {
            if (num <= numeric_limits<int>::min()) throw underflow_error("Underflow: Out of diapazon");
            else if (num >= numeric_limits<int>::max()) throw overflow_error("Overflow: Out of diapazon");
        }

        double term0() {
            double left = primary();
            Token t = ts.get();
            while (true) {
                switch (t.kind) {
                case '!': {
                    int result = 1;
                    for (int i = 1; i <= left; i++) {
                        check_on_diapazon_i(result);
                        result *= i;
                    }
                    left = result;
                    t = ts.get();
                    break;
                }
                default:
                    ts.unget(t);
                    return left;
                }
            }
        }

        double term() {
            double left = term0();
            while (true) {
                Token t = ts.get();
                switch (t.kind) {
                case '%': {
                    int mod = (int)left;
                    int right = term0();
                    left = mod % right;
                    break;
                }
                case '*':
                    left *= term0();
                    break;
                case '/': {
                    double d = term0();
                    if (d == 0) error("divide by zero");
                    left /= d;
                    break;
                }
                default:
                    ts.unget(t);
                    return left;
                }
            }
        }

        double expression() {
            double left = term();
            while (true) {
                Token t = ts.get();
                switch (t.kind) {
                case '+':
                    left += term();
                    break;
                case '-':
                    left -= term();
                    break;
                default:
                    ts.unget(t);
                    return left;
                }
            }
        }

        double declaration(bool constant) {
            Token t = ts.get();
            if (t.kind != NAME) error("name expected in declaration");
            string name = t.name;

            Token t2 = ts.get();
            if (t2.kind != '=') error("= missing");

            double d = expression();

            if (symbols.is_declared(name)) symbols.set_value(name, d);
            else symbols.define_name(name, d, constant);

            return d;
        }

        double statement() {
            Token t = ts.get();
            switch (t.kind) {
            case LET:
                return declaration(false);
            case CONS_T:
                return declaration(true);
            case ASSIGN:
                return declaration(false);
            case SQRT: {
                double e = expression();
                if (e < 0) error("Cannot calculate square root of negative numbers.");
                return sqrt(e);
            }
            case SIN: {
                t = ts.get();
                if (t.kind != '(') error("( expected.");

                double base = primary();

                t = ts.get();
                if (t.kind != ')') error(") expected.");

                return sin(base);
            }
            case COS: {
                t = ts.get();
                if (t.kind != '(') error("( expected.");

                double base = primary();

                t = ts.get();
                if (t.kind != ')') error(") expected.");

                return cos(base);
            }
            case POW: {
                t = ts.get();
                if (t.kind != '(') error("( expected.");

                double base = primary();
                t = ts.get();
                if (t.kind != ',') error("Comma expected.");

                double power = primary();

                t = ts.get();
                if (t.kind != ')') error(") expected.");

                double result = 1;

                while (power > 0) {
                    result *= base;
                    --power;
                }

                return result;
            }
            default:
                ts.unget(t);
                return expression();
            }
        }
    };

    //calculating
    double calcul(const string& str) {
        //-
        double rez_f = 0;
        //-

        while (true) {
            try {
                cout << prompt;
                //-
                istringstream si(str.c_str());
                calcul_logic c(si);            // cin
                //-   
                Token t = c.ts_get();
                while (t.kind == PRINT) t = c.ts_get();            // eat all ';' chars
                if (t.kind == QUIT) return 0;
                if (t.kind == HELP) {
                    help();
                    continue;
                }
                //-
                if (t.kind == TO) {
                    to_file(rez_f);
                    continue;
                }
                if (t.kind == FROM) {
                    cout << "Enter the name of file to read\n";
                    string fname;
                    cin >> fname;

                    ifstream fof(fname);
                    if (fof.is_open()) {
                        cout << "Reading from file completed\n";

                        calcul_logic f(fof);
                        t = f.ts_get();
                        f.ts_unget(t);
                        rez_f = f.statement();
                        cout << result << rez_f << endl;

                        fof.close();
                    }
                    else cout << "Error of opening\n";
                }
                else {
                    c.ts_unget(t);
                    rez_f = c.statement();
                    cout << result << rez_f << endl;
                    return rez_f;
                }
                //-               
            }
            catch (runtime_error& e) {
                cerr << e.what() << endl;
                //clean_up_mess();
            }
        }
    }

    void calculate() {
        symbols.define_name("e", 2.7, true);                    //defined constants     // M_E    
        symbols.define_name("pi", 3.14, true);                                          // M_PI
        symbols.define_name("k", 1000, true);                   //constant from the example

        cout << "Enter 'help/h/H' to run the info\n";
        cout << "Warning! This version works only with int-type values\n";
    }
}