#pragma once
#include <iostream>
#include <string>

using namespace std;

#ifndef lst
#define lst

template<class T>
T readValue(const string& message) {		// checking on the input type
	T v;
	cout << message << endl;
	cin >> v;

	if (!cin)
		throw runtime_error("Other value is expected");

	return v;
}

template <class T>
class MyList {
protected:							 						
	class Node {
	public:
		Node() {
			next = nullptr;
		}

		Node(const T& data) {
			this->data = data;
			this->next = nullptr;
		}

		T data;
		Node* next;
	};

	Node* head;
	int maxSize;
	int size;

public:
	MyList() {
		head = nullptr;
		size = 0;
		maxSize = 100;
	}

	MyList(int _maxSize) {
		head = nullptr;
		size = 0;
		maxSize = _maxSize;
	}

	MyList(MyList&& temp) {
		head = temp.head;
		size = temp.size;
		maxSize = temp.maxSize;

		temp.head = nullptr;
	}

	MyList& operator=(MyList&& temp) {
		if (&temp == this)
			return *this;

		head = temp.head;
		size = temp.size;
		maxSize = temp.maxSize;

		temp.head = nullptr;
		temp.size = 0;
		temp.maxSize = 0;

		return *this;
	}

	MyList(const MyList& other) {									
		head = nullptr;
		Node* un = other.head;
		maxSize = other.maxSize;

		while (un) {											
			pushEnd(un->data);
			un = un->next;
		}

		size = other.size;
	}

	~MyList() {													
		Node* un = head;
		Node* temp = nullptr;

		while (un) {
			temp = un->next;
			delete un;
			un = temp;
		}

		delete un;
	}

	int getSize() const {
		return size;
	}

	void print() const {
		if (getSize() == 0)
			cout << "MyList is empty" << endl;
		else {
			cout << "Now in MyList is " << getSize() << " elements" << endl;
			Node* un = head;
			while (un) {
				cout << un->data << endl;
				un = un->next;
			}
		}
	}

	void input() {
		T data;

		data = readValue<T>("Enter data");

		cout << "Add to tail or to head? (t/h)\n";				
		char ch;
		cin >> ch;

		if (ch == 't') {
			pushEnd(data);
		}
		else if (ch == 'h') {
			pushFront(data);
		}
		else cout << "Check your entering\n";
	}

	void pushFront(const T& data) {
		if (size >= maxSize)
			throw runtime_error("MyList is full");

		Node* un = new Node(data);
		un->next = head;
		head = un;

		size++;
	}

	void pushEnd(const T& data) {
		if (size >= maxSize)
			throw runtime_error("MyList is full");

		Node* un = head;

		if (un == nullptr) {
			un = new Node(data);
			head = un;
		}
		else {
			while (un->next != nullptr) {
				un = un->next;
			}
			un->next = new Node(data);
		}

		size++;
	}

	void popFront() {
		if (size <= 0)
			throw runtime_error("No elements");

		if (size == 1) {
			Node* un = head;
			delete un;
			head = nullptr;
		}
		else {
			Node* un = head;
			head = un->next;
			delete un;
		}

		size--;
	}

	void popEnd() {
		if (size <= 0)
			throw runtime_error("No elements");

		if (size == 1) {
			Node* un = head;
			delete un;
			head = nullptr;
		}
		else {
			Node* un = head, * temp = nullptr;
			while (un->next != nullptr) {
				temp = un;
				un = un->next;
			}
			temp->next = nullptr;
			delete un;
		}

		size--;
	}

	T operator [](const int& index) const {												
		if (index >= size or index < 0)
			throw runtime_error("Check your entering");

		Node* un = head;

		for (int i = 0; i != index; i++) {
			un = un->next;
		}

		return un->data;
	}

	MyList<T>& operator =(const MyList<T>& other) {									
		Node* un = other.head;

		this->~MyList();

		while (un) {
			this->pushEnd(un->data);
			un = un->next;
		}

		this->size = other.size;
		this->maxSize = other.maxSize;

		return *this;
	}

	/*MyList<T>& operator --() {														
		this->popFront();

		return *this;
	}

	MyList<T>& operator +(const T& data) {													
		this->pushFront(data);

		return *this;
	}*/
};

#endif