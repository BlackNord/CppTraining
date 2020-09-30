#include "ex_8_19.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

//+9 ex

template <typename T>
class my_allocator {
public:
	T* allocate(int n)  {
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

		/*T* temp = (T*)malloc(sizeof(T));	// mistakes
		*temp = v;
		memmove(p, temp, sizeof(T));*/
	}
	void destroy(T* p) {
		free(p);
	}
};

template<typename T, typename A = my_allocator<T>>
class my_vector {
private:
	int sz;
	T* elem;
	int space;
	A alloc;
public:
	my_vector() : sz{ 0 }, elem{ nullptr }, space{ 0 }{}

	explicit my_vector(int s) : sz{ s }, elem{ new T[s] }, space{ s } {
		for (int i{ 0 }; i < sz; ++i) {
			elem[i] = 0;
		}
	}

	my_vector& operator=(const my_vector& a) {
		if (this == &a) return *this;

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

	~my_vector() { delete[] elem; }

	T& operator[](int n) { return elem[n]; }
	const T& operator[](int n) const { return elem[n]; }

	int size() const { return sz; }

	int capacity() const { return space; }

	void push_back(const T& val) {
		if (space == 0) reserve(8);
		else if (sz == space) reserve(2 * space);
		alloc.construct(&elem[sz], val);

		++sz;
	}

	void resize(int newsize, T val = T()) {
		reserve(newsize);
		for (int i{ sz }; i < newsize; ++i) alloc.construct(&elem[i], val);
		for (int i{ newsize }; i < sz; ++i) alloc.destroy(&elem[i]);
		sz = newsize;
	}

	void reserve(int newalloc) {
		if (newalloc <= space) return;
		T* p = alloc.allocate(newalloc);
		for (int i{ 0 }; i < sz; ++i) alloc.construct(&p[i], elem[i]);
		for (int i{ 0 }; i < sz; ++i) alloc.destroy(&elem[i]);
		alloc.deallocate(elem, space);
		elem = p;
		space = newalloc;
	}
};

void ex_8_19() {
	my_vector<char> obj;
	obj.push_back('f');
	my_vector<char> obj1;
	obj1 = obj;
	cout << obj1[0] << endl;

	//+16 ex
	my_vector<my_vector<int>> test1;
	my_vector<int*> test2;
	cout << sizeof(test1) << endl;
	cout << sizeof(test2) << endl;
}