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

TEST(SimilarityCheckerTest, MaxAlphaPoints) {
	SimilarityChecker checker;
	EXPECT_EQ(40, checker.inspectAlphabet("ASD", "DSA"));
}