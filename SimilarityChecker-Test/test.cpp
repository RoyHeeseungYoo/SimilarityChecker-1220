#include "pch.h"
#include <stdexcept>
#include "../SimilarityChecker/checker.cpp"

using namespace std;

TEST(SimilarityCheckerTest, ZeroLengthException) {
	SimilarityChecker checker;
	EXPECT_THROW(checker.inspectLength("ASD", ""), length_error);
}

TEST(SimilarityCheckerTest, MaxPoints) {
	SimilarityChecker checker;
	EXPECT_EQ(60, checker.inspectLength("ASD", "DSA"));
}