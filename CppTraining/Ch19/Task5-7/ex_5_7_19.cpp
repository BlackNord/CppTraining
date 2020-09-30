#include "ex_5_7_19.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"
#include "../Task2/ex_2_19.h"

template<typename T>
class Number {
private:
	T value;

	constexpr bool chec_type(T _value) {
		if (typeid(_value) == typeid(int) or typeid(_value) == typeid(float)
			or typeid(_value) == typeid(double) or typeid(_value) == typeid(short)) {
			return true;
		}
		else return false;
	}
public:
	Number(T _value) {
		if (chec_type(_value)) {
			value = _value;
		}
		else throw runtime_error("Wrong type");
	}

	Number() : value{ 0 } {}

	T get() const{
		return value;
	}

	void set(T _value) {
		if (chec_type(_value)) {
			value = _value;
		}
		else throw runtime_error("Wrong type");
	}

	Number<T> operator=(const T& other) {
		this->value = other.get();
	}

	friend ostream& operator <<(ostream& outstream, const Number& obj) {
		outstream << obj.value;
		return outstream;
	}

	friend istream& operator >>(istream& instream, Number& obj) {
		instream >> obj.value;
		return instream;
	}

	friend Number operator +(const Number& obj1, const Number& obj2) {
		return Number(obj1.get() + obj2.get());
	}

	friend Number operator -(const Number& obj1, const Number& obj2) {
		return Number(obj1.get() - obj2.get());
	}

	friend Number operator *(const Number& obj1, const Number& obj2) {
		return Number(obj1.get() * obj2.get());
	}

	friend Number operator /(const Number& obj1, const Number& obj2) {
		return Number(obj1.get() / obj2.get());
	}

	friend Number operator %(const Number& obj1, const Number& obj2) {
		return Number(obj1.get() % obj2.get());
	}
};

template<typename T, typename U>
T sm_5(const vector<T>& vec1, const vector<U>& vec2) {
	T sum{ 0 };
	if (vec1.size() > vec2.size()) {
		int i{ 0 };
		for (; i < vec2.size(); ++i) {
			sum = sum + vec1[i] * vec2[i];
		}

		for (; i < vec1.size(); ++i) {
			sum = sum + vec1[i];
		}
	}
	else {
		int i{ 0 };
		for (; i < vec1.size(); ++i) {
			sum = sum + vec1[i] * vec2[i];
		}

		for (; i < vec2.size(); ++i) {
			sum = sum + vec2[i];
		}
	}
	return sum;
}

void ex_5_7_19() {
	Number<int> obj1(6);
	Number<int> obj2;
	cin >> obj2;
	obj1 = obj2;
	cout << obj1 + obj1 << endl;

	vector<Number<int>> num1 = { 1,2,3 };
	vector<Number<int>> num2 = { 4,5,6 };

	cout << sm_5(num1, num2) << endl;
}