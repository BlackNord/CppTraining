#include "ex_13_19.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

class Tracer {
private:
	string str_c, str_d;
public:
	Tracer(const string& _str_c, const string& _str_d) : str_c{ _str_c }, str_d{ _str_d } {
		cout << str_c << endl;
	}
	~Tracer() {
		cout << str_d << endl;
	}
	Tracer(const Tracer& obj) {
		str_c = obj.get_c();
		cout << str_c << endl;
		str_d = obj.get_d();
	}
	string get_c() const {
		return str_c;
	}
	string get_d() const {
		return str_d;
	}
	string get_c() {
		return str_c;
	}
	string get_d() {
		return str_d;
	}
};

void ex_13_19() {
	Tracer obj1("Constructor", "Destructor");
	Tracer obj2(obj1);
	Tracer obj3 = obj2;
}