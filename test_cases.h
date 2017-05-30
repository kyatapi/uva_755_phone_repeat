#pragma once
#include <gtest\gtest.h>

inline void run_test(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();;
}

