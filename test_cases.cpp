#include <string>
#include "test_cases.h"

using namespace std;

extern unsigned int phone_to_digit(const string&);

TEST(PhoneToDigit, HandleEmptyPhone) {
	ASSERT_EQ(0, phone_to_digit(""));
}
