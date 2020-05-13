#include "../Stroustruap_libs/std_lib_facilities_4.h"
#include "../Ch13/Task1/ex_1.h"
#include "../Ch13/Task2/ex_2.h"
#include "../Ch13/Task3/ex_3.h"
#include "../Ch13/Task4/ex_4.h"
#include "../Ch13/Task5/ex_5.h"
#include "../Ch13/Task7/ex_7.h"
#include "../Ch13/Task8-9/ex_8_9.h"
#include "../Ch13/Task10/ex_10.h"
#include "../Ch13/Task11/ex_11.h"

int main() {
	try {
		//ex_1();
		//ex_2();
		//ex_3();
		//ex_4();
		//ex_5();
		//ex_7();
		//ex_8_9();
		//ex_10();
		ex_11();
	}
	catch (const exception & ex) {
		cout << "Error: " << ex.what() << endl;
		keep_window_open();
	}
	catch (...) {
		cout << "Unnown error\n";
		keep_window_open();
	}
	//system("pause");
	return 0;
}