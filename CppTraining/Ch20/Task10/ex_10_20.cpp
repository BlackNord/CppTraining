#include "ex_10_20.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

vector<string> split(string inputString, string delimeters) {
	for (const auto& ch : delimeters) {
		string::iterator it = inputString.begin();

		while (true) {
			it = find(it, inputString.end(), ch);
			if (it != inputString.end()) {
				*it = '.';
				++it;
			}
			else
				break;
		}
	}

	vector<string> words;
	string word;

	stringstream stringStream(inputString);
	
	while (getline(stringStream, word, '.'))
	{
		words.push_back(word);
	}

	return words;
}

void ex_10_20() {
	vector<string> words = split("turie,tr   !trjek,,/ tr", " ,!/.&?");

	for (const auto& k : words) {
		cout << k << " ";
	}
	cout << endl;
}