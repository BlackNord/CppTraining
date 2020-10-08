#include "ex_10_19.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

//+11 ex

template<typename T>
class counted_ptr {
private:
	T* pointer;
	static int counter;
public:
	counted_ptr(T* _pointer) {
		pointer = new T(*_pointer);
	}

	counted_ptr(const counted_ptr& obj) {
		pointer = obj.ptr();
		counter++;
	}

	counted_ptr operator=(const counted_ptr& obj) {
		pointer = obj.ptr();
		counter++;
		return *this;
	}

	~counted_ptr() {
		if (pointer != nullptr && counter == 0) {
			delete pointer;
			cout << "Delete object\n";
		}
		else {
			cout << "Delete copy\n";
			counter--;
		}
	}

	T* release() {
		T* _pointer = pointer;
		pointer = nullptr;
		return _pointer;
	}

	T* ptr() const {
		return pointer;
	}

	T* operator ->() {
		return pointer;
	}

	T& operator *() {
		return *pointer;
	}
};

template<typename T>
int counted_ptr<T>::counter = 0;

class Test {
	int i;
public:
	Test(int _i) : i{ _i } {}

	void NoInfo() {
		cout << "Working\n";
	}
};

template<typename T>
counted_ptr<T> testing() {
	Test* ptr = new Test(5);				// create obj
	counted_ptr<Test> pointer(ptr);			// create ptr with obj
	pointer->NoInfo();
	counted_ptr test = pointer;				// create copy of obj
	return test;							// deleting ptr
}

void ex_10_19() {
	testing<Test>()->NoInfo();
}