#include "../Ch12/Task1/ex_1.h"
#include "../Ch12/Task2/ex_2.h"
#include "../Ch12/Task3/ex_3.h"
#include "../Ch12/Task4/ex_4.h"
#include "../Ch12/Task5/ex_5.h"
#include "../Ch12/Task6/ex_6.h"
#include "../Ch12/Task7/ex_7.h"
#include "../Ch12/Task8/ex_8.h"
#include "../Ch12/Task9/ex_9.h"
#include "../Ch12/Task10/ex_10.h"
#include "../Ch12/Task11/ex_11.h"
#include "../Ch12/Task12-13/ex_12_13.h"
#include "../Stroustruap_libs/std_lib_facilities_4.h"

int main() {
	try {
		//ex_1();
		//ex_2();
		//ex_3();
		//ex_4();
		//ex_5();
		//ex_6_1();
		//ex_6_2();
		//ex_7();
		//ex_8();
		//ex_9();
		//ex_10();
		//ex_11();
		ex_12_13();
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