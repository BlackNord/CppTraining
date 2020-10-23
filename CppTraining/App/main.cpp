#include "../Stroustruap_libs/std_lib_facilities_4.h"

#include "../Ch20/Task6z/ex_6z_20.h"
#include "../Ch20/Task2/ex_2_20.h"
#include "../Ch20/Task3/ex_3_20.h"
#include "../Ch20/Task5/ex_5_20.h"
#include "../Ch20/Task7/ex_7_20.h"
#include "../Ch20/Task10/ex_10_20.h"
#include "../Ch20/Task11/ex_11_20.h"
#include "../Ch20/Task14/ex_14_20.h"
#include "../Ch20/Task20/ex_20_20.h"

// 6-8-9, [12-13, 15, 16, 17, 18, 19] 

int main() {
	try {
		// ex_6z_20();
		// ex_2_20();
		// ex_3_20();
		// ex_7_20();
		// ex_10_20();
		// ex_11_20();
		// ex_20_20();
		// ex_5_20();
		// ex_14_20();
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
