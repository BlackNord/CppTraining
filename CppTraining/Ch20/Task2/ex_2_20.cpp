#include "ex_2_20.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

double* findHigh(double* first, double* last) {
	double h{ -1 };
	double* high{ nullptr };

	for (double* p = first; p != last; ++p) {
		if (h < *p) {
			high = p;
			h = *p;
		}
	}

	return high;
}

void ex_2_20() {
	vector<double> data{};
	data.push_back(1.2);
	data.push_back(2.3);
	data.push_back(3.4);

	vector<double>* jillData = &data;

	int jackCount{ 3 };
	double* jackData = new double[jackCount];

	for (int i{ 0 }; i < jackCount; ++i) {
		jackData[i] = i;
	}

	double* jackHigh = findHigh(jackData, jackData + jackCount);
	vector<double>& vec = *jillData;
	double* jillHigh = findHigh(vec.data(), vec.data() + vec.size());

	cout << *jackHigh << " " << *jillHigh << endl;

	delete[] jackData;
}