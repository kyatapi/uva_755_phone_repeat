#include <string>
#include "test_cases.h"

using namespace std;

extern unsigned int phone_to_digit(const string&);

TEST(PhoneToDigit, HandleEmptyPhone) {
	ASSERT_EQ(0, phone_to_digit(""));
}

TEST(PhoneToDigit, HandleNumericPhone) {
	ASSERT_EQ(2345678, phone_to_digit("2345678"));
	ASSERT_EQ(5678, phone_to_digit("000-5678"));
	ASSERT_EQ(301010, phone_to_digit("030-10-10"));
}

TEST(PhoneToDigit, HandleAlphabeticPhone) {
	ASSERT_EQ(4873279, phone_to_digit("ITS-EASY"));
	ASSERT_EQ(4875566, phone_to_digit("HUP-KLON"));
	ASSERT_EQ(6666345, phone_to_digit("NO-NO-DHL"));
}
