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

TEST(SimilarityCheckerTest, ZeroPoints) {
	SimilarityChecker checker;
	EXPECT_EQ(0, checker.inspectLength("A", "BB"));
	EXPECT_EQ(0, checker.inspectLength("AA", "B"));
}

TEST(SimilarityCheckerTest, PartialPoints) {
	SimilarityChecker checker;
	EXPECT_EQ(20, checker.inspectLength("AAABB", "BAA"));
	EXPECT_EQ(30, checker.inspectLength("AA", "AAE"));
	EXPECT_EQ(20, checker.inspectLength("BAA", "AAABB"));
	EXPECT_EQ(30, checker.inspectLength("AAE", "AA"));
}