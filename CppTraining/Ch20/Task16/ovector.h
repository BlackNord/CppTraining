#pragma once

#include <type_traits>

template <typename T>
class my_allocator {
public:
	T* allocate(int n) {
		return (T*)malloc(n * sizeof(T));
	}

	void deallocate(T* p, int n) {
		T* i = p;

		for (int k = 0; k < n; ++i, ++k) {
			free(i);
		}
	}

	void construct(T* p, const T& v) {		// создание типа T со значением v по адресу p
		new(p) T(v);
	}

	void destroy(T* p) {
		free(p);
	}
};

template<typename T>		// for example use 3 from variety of types
constexpr bool is_pointer =
	std::is_same<T, int*>::value || std::is_same<T, double*>::value || std::is_same<T, char*>::value;

template<typename T, typename A = my_allocator<T>>
class ovector {
	static_assert(is_pointer<T>, "Check your type");
private:
	int sz;
	T* elem;
	int space;
	A alloc;

public:
	ovector() : sz{ 0 }, elem{ nullptr }, space{ 0 } {}

	explicit ovector(int s) : sz{ s }, elem{ new T[s] }, space{ s } {
		for (int i{ 0 }; i < sz; ++i) {
			elem[i] = 0;
		}
	}

	ovector& operator=(const ovector& a) {
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

	~ovector() { 
		for (int i{ 0 }; i < sz; ++i) {
			delete elem[i];
		}

		delete[] elem; 
	}

	auto operator[](int n) {
		return *elem[n]; 
	}

	const auto operator[](int n) const {
		return *elem[n];
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
};