#include "../Stroustruap_libs/std_lib_facilities_4.h"
#include "../Ch16/Task1z/ex_1_16z.h"
#include "../Ch16/Task1/ex_1_16.h"
#include "../Ch16/Task3/ex_3_16.h"
#include "../Ch16/Task4/ex_4_16.h"
#include "../Ch16/Task5/ex_5_16.h"
#include "../Ch16/Task2/ex_2_16.h"

//6, 7, 8, 9, 10

int main() {
	try {
		//ex_1_16z();
		//ex_1_16();
		//ex_3_16();
		//ex_4_16();
		//ex_5_16();
		ex_2_16();
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
