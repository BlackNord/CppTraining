#include "../Stroustruap_libs/std_lib_facilities_4.h"
#include "../Ch14/Task1z/ex_1_14z.h"
#include "../Ch14/Task1/ex_1_14.h"
#include "../Ch14/Task4/ex_4_14.h"
#include "../Ch14/Task8/ex_8_14.h"
#include "../Ch14/Task15/ex_15_14.h"
#include "../Ch14/Task16/ex_16_14.h"
#include "../Ch14/Task5/ex_5_14.h"

int main() {
	try {
		//ex_1_14z();
		//ex_1_14();
		//ex_4_14();
		//ex_8_14();
		//ex_15_14();
		//ex_16_14();
		ex_5_14();
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
