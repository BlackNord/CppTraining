#include "../Ch12/Task1/ex_1.h"
#include "../Ch12/Task2/ex_2.h"
#include "../Ch12/Task3/ex_3.h"
#include "../Stroustruap_libs/std_lib_facilities_4.h"

int main() {
	try {
		//ex_1();
		//ex_2();
		ex_3();
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