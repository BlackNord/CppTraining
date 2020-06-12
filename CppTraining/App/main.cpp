#include "../Stroustruap_libs/std_lib_facilities_4.h"
#include "../Ch15/Task1z/ex_1_15z.h"
#include "../Ch15/Task1/ex_1_15.h"
#include "../Ch15/Task4/ex_4_15.h"
#include "../Ch15/Task2-3/ex_2_3_15.h"
#include "../Ch15/Task5/ex_5_15.h"

//5, 6-11

int main() {
	try {
		//ex_1_15z();
		//ex_1_15z_2();
		//ex_1_15();
		//ex_4_15();
		//ex_2_3_15();
		ex_5_15();
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
