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

	MyUniquePtr(MyUniquePtr&& ptr) : pointer_(ptr.pointer_) {
		ptr.pointer_ = nullptr;
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

	T& operator *() const {
		return *pointer_;
	}
};

template<typename T>
class MyCountedPtr {
private:
	T* pointer_;
	int* counter_;

	void cleanup() {
		if (pointer_ != nullptr && *counter_ == 1) {
			delete pointer_;
			delete counter_;
			pointer_ = nullptr;
			counter_ = nullptr;
			cout << "Delete object\n";
		}
		else {
			--(*counter_);
			cout << "Delete copy\n";
		}
	}

public:
	MyCountedPtr(T* _pointer) {
		pointer_ = new T(*_pointer);
		counter_ = new int();
		*counter_ = 1;
	}

	MyCountedPtr(const MyCountedPtr& obj) {
		pointer_ = obj.ptr();
		counter_ = obj.counter_;
		++(*counter_);
	}

	MyCountedPtr operator=(const MyCountedPtr& obj) {
		if (*counter_ > 0) {
			cleanup();
		}

		if (this != &obj) {
			pointer_ = obj.ptr();
			counter_ = obj.counter_;
			++(*counter_);
		}

		return *this;
	}

	MyCountedPtr() {}

	~MyCountedPtr() {
		cleanup();
	}

	T* ptr() const {
		return pointer_;
	}

	T* operator ->() {
		return pointer_;
	}

	T& operator *() {
		return *pointer_;
	}

	T& operator *() const {
		return *pointer_;
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

void testing_unique() {
	Test* ptr = new Test(5);

	MyUniquePtr<Test> pointer(ptr);

	pointer->NoInfo();
	(*pointer).NoInfo();

	auto *p = pointer.release();

	p->NoInfo();

	delete p;
}

void testing_counted() {
	Test* ptr = new Test(5);

	MyCountedPtr<Test>* pointer = new MyCountedPtr<Test>(ptr);

	MyCountedPtr<Test>* pointer2 = new MyCountedPtr<Test>(*pointer);
	MyCountedPtr<Test> pointer3(*pointer2);

	delete pointer2;
	delete pointer;

	pointer3->NoInfo();
}

void ex_10_19() {
	//testing_unique();
	testing_counted();
}