#include "ex_3_19.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

template<typename T, typename U>
class Pair {
private:
	T key;
	U value;
public:
	Pair(T _key, U _value) : key{ _key }, value{ _value } {}
	void set(T _key, U _value) {
		key = _key;
		value = _value;
	}
	T get_key() {
		return key;
	}
	U get_value() {
		return value;
	}
};

void ex_3_19() {
	Pair obj(3, "a");
	cout << obj.get_key() << "-" << obj.get_value() << endl;
}