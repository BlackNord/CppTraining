#include "ex_7_20.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

void ex_7_20() {
	vector<string> strings;

	strings.push_back("is a simply example");
	strings.push_back("fis a simply example");
	strings.push_back("bis a simply example");
	strings.push_back("zis a simply example");
	strings.push_back("cis a simply example");

	sort(strings.begin(), strings.end());

	vector<string>::iterator it = strings.end();

	--it;

	cout << *it << endl;
}