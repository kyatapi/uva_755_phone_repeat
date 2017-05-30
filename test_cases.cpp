#include <string>
#include <list>
#include <vector>
#include "test_cases.h"

using namespace std;

extern unsigned int phone_to_digit(const string&);
list< pair<int, int> > compile_directory(const vector<string>&);

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

TEST(PhoneToDigit, HandleAlphanumericPhone) {
	ASSERT_EQ(8352266, phone_to_digit("TEL-2266"));
	ASSERT_EQ(3376836, phone_to_digit("337-OUEN"));
}

TEST(PhoneToDigit, HandleInvalidPhone) {
	ASSERT_EQ(0, phone_to_digit("QQ-QQ-ZZZ"));
}

using ::testing::IsEmpty;
using ::testing::ElementsAre;
using ::testing::Pair;

TEST(CompileDirectory, HandleEmptyList) {
	EXPECT_THAT(compile_directory({}), IsEmpty());
}

TEST(CompileDirectory, HandleNoRepeatAndOrdered) {
	EXPECT_THAT(compile_directory({"123", "456", "789"}), ElementsAre(Pair(123, 1), Pair(456, 1), Pair(789, 1)));
}