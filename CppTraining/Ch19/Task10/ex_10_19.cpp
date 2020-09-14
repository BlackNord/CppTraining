#include "ex_10_19.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

//+11 ex

template<typename T>
class my_unique_ptr {
private:
	T* pointer;
	int counter;
public:
	my_unique_ptr(T* _pointer) {
		pointer = _pointer;
		counter = 0;
	}

	my_unique_ptr(const my_unique_ptr& obj) {
		pointer = obj.ptr();
		counter++;
	}

	my_unique_ptr operator=(const my_unique_ptr& obj) {
		pointer = obj.ptr();
		counter++;
		return *this;
	}

	~my_unique_ptr() {
		if (pointer != nullptr && counter == 0) {
			delete[] pointer;
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

class Test {
	int i;
public:
	Test(int _i) : i{ _i } {}

	void NoInfo() {
		cout << "Working\n";
	}
};

void ex_10_19() {
	Test* ptr = new Test(5);
	my_unique_ptr<Test> pointer(ptr);
	pointer->NoInfo();
	my_unique_ptr pointer2 = pointer;
	// pointer.release();					// testing
}