#include "../Stroustruap_libs/std_lib_facilities_4.h"
#include "../Ch16/Task1z/ex_1_16z.h"

int main() {
	try {
		ex_1_16z();
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
