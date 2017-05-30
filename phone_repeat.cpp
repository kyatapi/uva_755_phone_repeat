#include <string>
#include <map>
#include <list>
#include <vector>

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

list< pair<int, int> > compile_directory(const vector<string>& phone_list) {
	list< pair<int, int> > phone_repeat_times;

	for (const string& p : phone_list) {
		unsigned int digits = phone_to_digit(p);
		phone_repeat_times.push_back(pair<int, int>(digits, 1));
	}

	return phone_repeat_times;
}

int main(int argc, char **argv) {
	run_test(argc, argv);

	return 0;
}