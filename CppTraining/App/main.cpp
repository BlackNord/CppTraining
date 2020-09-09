#include "../Stroustruap_libs/std_lib_facilities_4.h"

#include "../Ch19/Task6z/ex_6z_19.h"

// task6, (2,4), 5, (6,8,9-10), 7, 11, 12-13, 14, 15, 16, 17, 18, 19, 20

int main() {
	try {
		ex_6z_19();
	}
	catch (const exception & ex) {
		cout << "Error: " << ex.what() << endl;
		keep_window_open();
	}
	catch (...) {
		cout << "Unnown error\n";
		keep_window_open();
	}
	system("pause");
	return 0;
}
