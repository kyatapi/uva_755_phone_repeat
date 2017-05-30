#include <string>
#include <map>

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
		{ '7', 7 }, { '8', 8 }, { '9', 9 }
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

int main(int argc, char **argv) {
	run_test(argc, argv);

	return 0;
}