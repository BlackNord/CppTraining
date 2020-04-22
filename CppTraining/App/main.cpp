#include "../Ch12/Task1/ex_1.h"
#include "../Stroustruap_libs/std_lib_facilities_4.h"

int main() {
	try {
		ex_1();
	}
	catch (const exception & ex) {
		cout << "Error: " << ex.what() << endl;
		keep_window_open();
	}
	catch (...) {
		cout << "Unnown error\n";
		keep_window_open();
	}
	return 0;
}