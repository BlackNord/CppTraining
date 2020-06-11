#include "../Stroustruap_libs/std_lib_facilities_4.h"
#include "../Ch15/Task1z/ex_1_15z.h"
#include "../Ch15/Task1/ex_1_15.h"

//2-3, 4, 5, 6-11

int main() {
	try {
		//ex_1_15z();
		//ex_1_15z_2();
		ex_1_15();
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
