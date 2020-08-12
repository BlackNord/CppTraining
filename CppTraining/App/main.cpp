#include "../Stroustruap_libs/std_lib_facilities_4.h"

#include "../Ch18/Task1z/ex_1z_18.h"
#include "../Ch18/Task1-4/ex_1_4_18.h"
#include "../Ch18/Task5-7/ex_5_7_18.h"
#include "../Ch18/Task10/ex_10_18.h"
#include "../Ch18/Task9/ex_9_18.h"
#include "../Ch18/Task11/ex_11_18.h"

// 12 

int main() {
	try {
		// ex_1z_18();
		// ex_1_4_18();
		// ex_5_7_18();
		// ex_8_18();
		// ex_10_18();
		// ex_9_18();
		ex_11_18();
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
