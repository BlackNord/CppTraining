#include "../Stroustruap_libs/std_lib_facilities_4.h"
#include "../Ch13/Task1/ex_1.h"
#include "../Ch13/Task2/ex_2.h"
#include "../Ch13/Task3/ex_3.h"

int main() {
	try {
		//ex_1();
		//ex_2();
		ex_3();
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