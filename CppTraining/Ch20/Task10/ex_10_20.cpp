#include "ex_10_20.h"
#include "../../Stroustruap_libs/std_lib_facilities_4.h"

//vector<string> split(string inputString, string delimeters) {
//	for (const auto& ch : delimeters) {
//		string::iterator it = inputString.begin();
//
//		while (true) {
//			it = find(it, inputString.end(), ch);
//			if (it != inputString.end()) {
//				*it = '.';
//				++it;
//			}
//			else
//				break;
//		}
//	}
//
//	vector<string> words;
//	string word;
//
//	stringstream stringStream(inputString);
//	
//	while (getline(stringStream, word, '.'))
//	{
//		if (!word.empty()) {
//			words.push_back(word);
//		}
//	}
//
//	return words;
//}

/*vector<string> split(const string& str) {
	vector<string> result;
	stringstream x;
	string buf;

	x << str;
	while (x >> buf) {
		result.push_back(buf);
	}

	return result;
}*/

vector<string> split(std::stringstream& str, char separator) {
	std::vector<string> result;
	std::string line;

	while (getline(str, line, separator)) {
		result.push_back(line);
	}

	return result;
}

void ex_10_20() {
	std::stringstream stream("turie,tr,trjek,tr");
	std::vector<std::string> words = split(stream, ',');

	for (const auto& k : words) {
		cout << k << " ";
	}
	cout << endl;

	cout << words.size() << endl;
}