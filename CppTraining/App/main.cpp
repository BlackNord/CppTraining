#include "../Stroustruap_libs/std_lib_facilities_4.h"

#include "../Ch19/Task1z/ex_1z_19.h"
#include "../Ch19/Task1/ex_1_19.h"
#include "../Ch19/Task2/ex_2_19.h"
#include "../Ch19/Task3/ex_3_19.h"
#include "../Ch19/Task5-7/ex_5_7_19.h"

// 8, 9, 10, 11, 13, 16, (14-15)

int main() {
	try {
		// ex_1z_19();
		// ex_1_19();
		// ex_2_19();
		// ex_3_19();
		ex_5_7_19();
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
