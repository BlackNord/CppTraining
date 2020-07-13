#include "ex_11_14_17.h"
#include "../Task11-14/list.h"

class God {						
private:
	string name;
	string myth;
	string riding;
	string weapon;

public:
	God() {
		this->name = { "" };
		this->myth = { "" };
		this->riding = { "" };
		this->weapon = { "" };
	}

	God(const string& _name, const string& _myth, const string& _riding, const string& _weapon ) {
		this->name = _name;
		this->myth = _myth;
		this->riding = _riding;
		this->weapon = _weapon;
	}

	void set_name(const string& _name) {
		this->name = _name;
	}

	void set_myth(const string& _myth) {
		this->myth = _myth;
	}

	void set_riding(const string& _riding) {
		this->riding = _riding;
	}

	void set_weapon(const string& _weapon) {
		this->weapon = _weapon;
	}

	string get_name() const {
		return this->name;
	}

	string get_myth() const {
		return this->myth;
	}

	string get_riding() const {
		return this->riding;
	}

	string get_weapon() const {
		return this->weapon;
	}

	friend ostream& operator <<(ostream& outstream, const God& obj) {		
		outstream << obj.get_name() << endl;
		outstream << obj.get_myth() << endl;
		outstream << obj.get_riding() << endl;
		outstream << obj.get_weapon() << endl;
		return outstream;
	}

	friend istream& operator >>(istream& instream, God& obj) {
		instream >> obj.name;
		instream >> obj.myth;
		instream >> obj.riding;
		instream >> obj.weapon;
		return instream;
	}
};

void ex_11_14_17() {
	list<God> gods;
	gods.input();
	gods.add_ordered();
	gods.print();
}