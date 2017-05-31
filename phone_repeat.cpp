#include <string>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

#ifndef ONLINE_JUDGE
#include "test_cases.h"
extern void run_test(int argc, char **argv);
#else
inline void run_test(int argc, char **argv) {}
#endif // !ONLINE_JUDGE

using namespace std;

unsigned int phone_to_digit(const string& phone) {
	static const unsigned int char_digit_mapping[] = {
		2, 2, 2,
		3, 3, 3,
		4, 4, 4,
		5, 5, 5,
		6, 6, 6,
		7, 0, 7, 7,
		8, 8, 8,
		9, 9, 9, 0
	};

	unsigned int digits = 0;
	for (const char p : phone)
	{
		unsigned int digit = 0;
		if (p >= '0' &&  p <= '9') {
			digit = p - '0';
		}
		else if (p >= 'A' && p <= 'Y' && p != 'Q') {
			digit = char_digit_mapping[p - 'A'];	
		}
		else {
			continue;
		}

		digits = digits * 10 + digit;
	}

	return digits;
}

map<unsigned int, unsigned int> compile_directory(const vector<string>& phone_list) {
	map<unsigned int, unsigned int> repeat_times;

	for (const string& p : phone_list) {
		repeat_times[phone_to_digit(p)]++;
	}

	return repeat_times;
}

int main(int argc, char **argv) {
	run_test(argc, argv);

	unsigned int directory_count = 0;
	cin >> directory_count;
	cin.ignore(2, '\n');

	cout.fill('0');
	for (unsigned int d = 0; d < directory_count; ++d) {
		unsigned int phone_count = 0;
		vector<string> phone_list;
		cin >> phone_count;
		cin.ignore(1, '\n');
		for (unsigned int p = 0; p < phone_count; ++p) {
			string phone = "";
			getline(cin, phone);
			phone_list.push_back(phone);
		}
		map<unsigned int, unsigned int> repeat_times = compile_directory(phone_list);
		unsigned int repeat_entry_count = 0;
		for (auto rt : repeat_times) {
			if (rt.second > 1) {
				cout << setw(3) << rt.first / 10000 << "-" << setw(4) << rt.first % 10000 << " " << rt.second << endl;
				++repeat_entry_count;
			}
		}
		if (repeat_entry_count == 0) {
			cout << "No duplicates." << endl;
		}
		cout << endl;
		cin.ignore(1, '\n');
	}

	return 0;
}