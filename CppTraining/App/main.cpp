#include "../Stroustruap_libs/std_lib_facilities_4.h"

#include "../Ch18/Task1z/ex_1z_18.h"
#include "../Ch18/Task1-4/ex_1_4_18.h"

//(3, 4), (5, 6, 7), 8, 9, 10, 11, 12 

int main() {
	try {
		// ex_1z_18();
		ex_1_4_18();
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
