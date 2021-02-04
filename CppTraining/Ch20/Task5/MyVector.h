#pragma once
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

template <typename T>
class MyAllocator {
public:
	T* allocate(int n) {
		return (T*)malloc(n * sizeof(T));
	}

	void deallocate(T* p, int n) {
		free(p);
	}

	void construct(T* p, const T& v) {		// create type T with value v on adress p
		new(p) T(v);
	}

	void destroy(T* p) {
		delete(p);
	}
};

template<typename T, typename A = MyAllocator<T>>
class MyVector {
private:
	int sz;
	T* elem;
	int space;
	A alloc;

public:
	MyVector() : sz{ 0 }, elem{ nullptr }, space{ 0 } { }

	explicit MyVector(int s) : sz{ s }, elem{ alloc.allocate(T[s]) }, space{ s } {
		for (int i{ 0 }; i < sz; ++i) {
			elem[i] = 0;
		}
	}

	MyVector(MyVector&& temp) {
		sz = temp.sz;
		elem = temp.elem;
		space = temp.space;
		alloc = temp.alloc;
		
		temp.elem = nullptr;
	}

	MyVector& operator=(MyVector&& temp) {
		if (&temp == this)
			return *this;

		*this = std::move(temp);

		return *this;
	}

	MyVector& operator=(const MyVector& a) {
		if (this == &a)
			return *this;

		if (a.sz <= space) {
			for (int i{ 0 }; i < a.sz; ++i) {
				elem[i] = a.elem[i];
			}
			sz = a.sz;
			return *this;
		}

		T* p = alloc.allocate(a.sz);

		for (int i{ 0 }; i < a.sz; ++i) {
			p[i] = a.elem[i];
		}

		alloc.destroy(elem);
		space = sz = a.sz;
		elem = p;

		return *this;
	}

	~MyVector() { 
		alloc.destroy(elem);
	}

	T& operator[](int n) {
		return elem[n];
	}

	const T& operator[](int n) const {
		return elem[n];
	}

	int size() const {
		return sz;
	}

	int capacity() const {
		return space;
	}

	void push_back(const T& val) {
		if (space == 0)
			reserve(8);
		else if (sz == space)
			reserve(2 * space);

		alloc.construct(&elem[sz], val);

		++sz;
	}

	void resize(int newsize, T val = T()) {
		reserve(newsize);

		for (int i{ sz }; i < newsize; ++i)
			alloc.construct(&elem[i], val);

		for (int i{ newsize }; i < sz; ++i)
			alloc.destroy(&elem[i]);

		sz = newsize;
	}

	void reserve(int newalloc) {
		if (newalloc <= space)
			return;

		T* p = alloc.allocate(newalloc);

		for (int i{ 0 }; i < sz; ++i)
			alloc.construct(&p[i], elem[i]);
		for (int i{ 0 }; i < sz; ++i)
			alloc.destroy(&elem[i]);

		alloc.deallocate(elem, space);
		elem = p;
		space = newalloc;
	}

	friend ostream& operator <<(ostream& outstream, const MyVector<T>& vec) {
		for (size_t i{ 0 }; i < vec.size(); ++i) {
			outstream << vec[i] << " ";
		}
		return outstream;
	}

	friend istream& operator >>(istream& instream, MyVector<T>& vec) {
		T temp;
		instream >> temp;
		vec.push_back(temp);
		return instream;
	}
};