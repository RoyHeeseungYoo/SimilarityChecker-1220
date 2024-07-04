#include "pch.h"
#include <stdexcept>
#include "../SimilarityChecker/checker.cpp"

using namespace std;

TEST(SimilarityCheckerTest, ExceptionOnInvalid) {
	SimilarityChecker checker;
	EXPECT_THROW(checker.inspectAlphabet("aBC", "ABC"), invalid_argument);
	EXPECT_THROW(checker.inspectAlphabet("1aBC", "ABC"), invalid_argument);
	EXPECT_THROW(checker.inspectAlphabet("^aBC", "ABC"), invalid_argument);
	EXPECT_THROW(checker.inspectAlphabet("ABC", "2ABC"), invalid_argument);
}