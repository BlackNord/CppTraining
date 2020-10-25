#include "ex_10_19.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

//+11 ex

template<typename T>
class MyUniquePtr {
private:
	T* pointer_;
public:
	MyUniquePtr(T* pointer) {
		pointer_ = new T(*pointer);
		cout << "Constructor working\n";
	}

	~MyUniquePtr() {
		delete pointer_;
		cout << "Destructor working\n";
	}

	MyUniquePtr(const MyUniquePtr&) = delete;
	void operator=(const MyUniquePtr&) = delete;

	T* release() {
		T* pointer = pointer_;
		pointer_ = nullptr;
		return pointer;
	}

	T* operator ->() {
		return pointer_;
	}

	T& operator *() {
		return *pointer_;
	}
};

//template<typename T>
//class counted_ptr {
//private:
//	T* pointer;
//	static int counter;
//public:
//	counted_ptr(T* _pointer) {
//		pointer = new T(*_pointer);
//	}
//
//	counted_ptr(const counted_ptr& obj) {
//		pointer = obj.ptr();
//		counter++;
//	}
//
//	counted_ptr operator=(const counted_ptr& obj) {
//		pointer = obj.ptr();
//		counter++;
//		return *this;
//	}
//
//	~counted_ptr() {
//		if (pointer != nullptr && counter == 0) {
//			delete pointer;
//			cout << "Delete object\n";
//		}
//		else {
//			cout << "Delete copy\n";
//			counter--;
//		}
//	}
//
//	T* release() {
//		T* _pointer = pointer;
//		pointer = nullptr;
//		return _pointer;
//	}
//
//	T* ptr() const {
//		return pointer;
//	}
//
//	T* operator ->() {
//		return pointer;
//	}
//
//	T& operator *() {
//		return *pointer;
//	}
//};

//template<typename T>
//int counted_ptr<T>::counter = 0;

class Test {
	int i;
public:
	Test(int _i) : i{ _i } {}

	void NoInfo() {
		cout << "Working\n";
	}
};

void testing_unique() {
	Test* ptr = new Test(5);

	MyUniquePtr<Test> pointer(ptr);

	pointer->NoInfo();
	(*pointer).NoInfo();

	auto *p = pointer.release();

	p->NoInfo();

	delete p;
}

void ex_10_19() {
	testing_unique();
}