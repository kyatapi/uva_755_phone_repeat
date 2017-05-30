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
	const map<char, int> char_digit_mapping = {
		{ '0', 0 }, 
		{ '1', 1 }, { '2', 2 }, { '3', 3 },
		{ '4', 4 }, { '5', 5 }, { '6', 6 },
		{ '7', 7 }, { '8', 8 }, { '9', 9 },
		{ 'A', 2 }, { 'B', 2 }, { 'C', 2 },
		{ 'D', 3 }, { 'E', 3 }, { 'F', 3 },
		{ 'G', 4 }, { 'H', 4 }, { 'I', 4 },
		{ 'J', 5 }, { 'K', 5 }, { 'L', 5 },
		{ 'M', 6 }, { 'N', 6 }, { 'O', 6 },
		{ 'P', 7 }, { 'R', 7 }, { 'S', 7 },
		{ 'T', 8 }, { 'U', 8 }, { 'V', 8 },
		{ 'W', 9 }, { 'X', 9 }, { 'Y', 9 },
	};

	unsigned int digits = 0;
	for (const char p : phone)
	{
		try {
			unsigned int digit = char_digit_mapping.at(p);
			digits = digits * 10 + digit;
		} catch (out_of_range e) {}
	}

	return digits;
}

typedef pair<unsigned int, unsigned int> digit_repeat_time;

list<digit_repeat_time> compile_directory(const vector<string>& phone_list) {
	list<digit_repeat_time> repeat_times;

	for (const string& p : phone_list) {
		digit_repeat_time entry(phone_to_digit(p), 1);
		list<digit_repeat_time>::iterator ite = lower_bound(repeat_times.begin(), 
			                                                repeat_times.end(),
															entry, 
			                                                [](const digit_repeat_time& element, const digit_repeat_time& value) { return element.first < value.first; });

		if (ite != repeat_times.end() && ite->first == entry.first) {
			ite->second += 1;
		}
		else {
			repeat_times.insert(ite, entry);
		}
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
		list<digit_repeat_time> repeat_times = compile_directory(phone_list);
		for (digit_repeat_time rt : repeat_times) {
			if (rt.second > 1) {
				cout << setw(3) << rt.first / 10000 << "-" << setw(4) << rt.first % 10000 << " " << rt.second << endl;
			}
		}
		cin.ignore(1, '\n');
	}

	return 0;
}