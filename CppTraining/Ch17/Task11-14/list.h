#pragma once
#include <iostream>
#include <string>

using namespace std;

#ifndef lst
#define lst

template<class Type>
Type read_value(const string& message) {							
	Type v;
	cout << message << endl;
	cin >> v;
	if (!cin) throw runtime_error("Other value is expected");
	return v;
}

template <class T>
class list {
protected:							 						
	class node {
	public:
		node() {
			next = nullptr;
		}
		node(const T& data) {
			node* next = nullptr;
			this->data = data;
			this->next = next;
		}
		T data;
		node* next;
	};

	node* head;
	int max_size;
	int size;

public:
	list() {
		head = nullptr;
		size = 0;
		max_size = 100;
	}

	list(const int& max_s) {
		head = nullptr;
		size = 0;
		max_size = max_s;
	}

	list(const list& other) {									
		head = nullptr;
		node* un = other.head;
		max_size = other.max_size;
		while (un) {											
			push_end(un->data);
			un = un->next;
		}

		size = other.size;
	}

	~list() {													
		node* ptr = head;
		node* temp = nullptr;

		while (ptr) {											
			temp = ptr->next;
			delete ptr;
			ptr = temp;
		}

		delete ptr;
		delete temp;
	}

	int get_size() const {
		return size;
	}

	void print() const {
		if (get_size() == 0) cout << "List is empty" << endl;
		cout << "Now in list is " << get_size() << " elements" << endl;
		node* un = head;
		while (un) {
			cout << un->data << endl;
			un = un->next;
		}
	}

	void input() {
		T data;

		data = read_value<T>("Enter data");

		cout << "Add to tail or to head? (t/h)\n";				
		char ch;
		cin >> ch;
		if (ch == 't') {
			push_end(data);
		}
		else if (ch == 'h') {
			push_front(data);
		}
		else cout << "Check your entering\n";
	}

	void push_front(const T& data) {
		if (size > max_size) throw runtime_error("List is full");

		node* un = new node(data);
		un->next = head;
		head = un;

		size++;
	}

	void push_end(const T& data) {
		if (size > max_size) throw runtime_error("List is full");

		node* un = head;
		if (un == nullptr) {
			un = new node(data);
			head = un;
		}
		else {
			while (un->next != nullptr) {
				un = un->next;
			}
			un->next = new node(data);
		}

		size++;
	}

	void pop_front() {
		if (size <= 0) throw runtime_error("No elements");

		if (size == 1) {
			node* un = head;
			delete un;
			head = nullptr;
		}
		else {
			node* un = head;
			head = un->next;
			delete un;
		}

		size--;
	}

	void pop_end() {
		if (size <= 0) throw runtime_error("No elements");

		if (size == 1) {
			node* un = head;
			delete un;
			head = nullptr;
		}
		else {
			node* un = head, * temp = nullptr;
			while (un->next != nullptr) {
				temp = un;
				un = un->next;
			}
			temp->next = nullptr;
			delete un;
		}

		size--;
	}

	void add_ordered() {
		input();
		sort();
	}

	void sort() {
		if (size <= 0) throw runtime_error("No elements");

		node* un = head;
		T temp;
		bool p = false;

		while (true) {
			for (; un->next != nullptr; un = un->next) {
				if (un->data.get_name() > un->next->data.get_name()) {
					temp = un->data;
					un->data = un->next->data;
					un->next->data = temp;
					p = true;
				}
			}
			if (p == false) break;
			p = false;
		}
		cout << "Sorting is done\n";
	}

	T operator [](const int& index) const {												
		if (index >= size or index < 0) throw runtime_error("Check your entering");

		node* un = head;
		for (int i = 0; i != index; i++) {
			un = un->next;
		}
		return un->data;
	}

	list<T>& operator =(const list<T>& other) {									
		node* un = other.head;
		node* ptr = head;
		node* temp = nullptr;

		while (ptr) {																
			temp = ptr->next;
			delete ptr;
			ptr = temp;
		}

		this->head = nullptr;

		while (un) {
			this->push_end(un->data);
			un = un->next;
		}

		this->size = other.size;
		this->max_size = other.max_size;

		return *this;
	}

	list<T>& operator --() {														
		this->pop_front();

		return *this;
	}

	list<T>& operator +(const T& data) {													
		this->push_front(data);

		return *this;
	}
};

#endif