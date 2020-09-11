#include "ex_1z_19.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

template<typename T> 
class S { 
private:
	T val; 
public:
	S(T _val) : val{ _val } {}
	S() {}
	T get();
	T get() const;
	void set(T);
	S<T> operator=(const T&);
	void read_val();

	friend ostream& operator <<(ostream& outstream, const S& obj) {		
		outstream << obj.val;
		return outstream;
	}

	friend istream& operator >>(istream& instream, S& obj) {		
		instream >> obj.val;
		return instream;
	}
};

template<typename T>
void S<T>::set(T _val) {
	val = _val;
}

template<typename T>
T S<T>::get() {
	return val;
}

template<typename T>
T S<T>::get() const {
	return val;
}

template<typename T>
S<T> S<T>::operator=(const T& other) {
	this->val = other.get();
}

template<typename T> 
void S<T>::read_val() {
	T v;
	cin >> v;
	if (!cin) throw runtime_error("Other value is expected");
	set(v);
}

void ex_1z_19() {
	S<int> obj1(1);
	S<int> obj2(2);
	
	obj1 = obj2;

	cout << obj1.get() << endl;

	S<int> obj3;
	obj3.read_val();
	cout << obj3.get() << endl;

	S<int> obj4;
	cin >> obj4;
	cout << obj4 << endl;
}