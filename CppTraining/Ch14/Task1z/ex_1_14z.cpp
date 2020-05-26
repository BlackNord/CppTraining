#include "ex_1_14z.h"
#include "../../Stroustruap_libs/Simple_window.h"
#include "../../Stroustruap_libs/Graph.h"

using namespace std;

class B1 {
	public:
	virtual void vf() {
		cout << "B1::vf()\n";
	}
	virtual void pvf() {
		cout << "B1::pvf()\n";
	}
	void f() {
		cout << "B1::f()\n";
	}
};

class D1 : public B1 {
public:
	virtual void vf() override{
		cout << "D1::vf()\n";
	}
	void f() {
		cout << "D1::f()\n";
	}
};

class D2 : public D1 {
public:
	virtual void pvf() override {
		cout << "D2::pvf()\n";
	}
};

class B2 {
public:
	virtual void pvf() = 0;
};

class D21 : public B2 {
private:
	string s;
public:
	D21(const string& _s) : s{ _s } {}

	virtual void pvf() override {
		cout << s << endl;
	}
};

class D22 : public B2 {
private:
	int i;
public:
	D22(int _i) : i{ _i } {}

	virtual void pvf() override {
		cout << i << endl;
	}
};

void f(B2& obj) {
	obj.pvf();
}

void ex_1_14z() {
	B1 obj_b1;
	obj_b1.f();
	obj_b1.vf();
	cout << '\n';

	D1 obj_d1;			// demonstration overriding
	obj_d1.f();
	obj_d1.vf();
	cout << '\n';

	B1& s_b1 = obj_d1;
	s_b1.f();
	s_b1.vf();
	cout << '\n';

	D1 obj_d2;			
	obj_d2.f();
	obj_d2.vf();
	cout << '\n';

	B1& s_b2 = obj_d2;
	s_b2.f();
	s_b2.vf();
	cout << '\n';

	D1 obj_d3;
	obj_d3.f();
	obj_d3.vf();
	obj_d3.pvf();
	cout << '\n';

	B1& s_b3 = obj_d3;
	s_b3.f();
	s_b3.vf();
	s_b3.pvf();
	cout << '\n';

	D2 obj_dd2;
	obj_dd2.f();
	obj_dd2.vf();
	obj_dd2.pvf();
	cout << '\n';

	D21 ex1("Example 1");
	D22 ex2(12);
	f(ex1);
	f(ex2);
}