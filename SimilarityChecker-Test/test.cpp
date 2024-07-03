#include "pch.h"
#include <stdexcept>
#include "../SimilarityChecker/checker.cpp"

using namespace std;

class SimilarityCheckerFixture : public testing::Test {
public:
	SimilarityChecker checker{ };
};

TEST_F(SimilarityCheckerFixture, ZeroLengthException) {
	EXPECT_THROW(checker.inspectLength("ASD", ""), length_error);
}

TEST_F(SimilarityCheckerFixture, MaxPoints) {
	EXPECT_EQ(60, checker.inspectLength("ASD", "DSA"));
}

TEST_F(SimilarityCheckerFixture, ZeroPoints) {
	SimilarityChecker checker;
	EXPECT_EQ(0, checker.inspectLength("A", "BB"));
	EXPECT_EQ(0, checker.inspectLength("AA", "B"));
}


TEST_F(SimilarityCheckerFixture, PartialPoints) {
	EXPECT_EQ(20, checker.inspectLength("AAABB", "BAA"));
	EXPECT_EQ(30, checker.inspectLength("AA", "AAE"));
	EXPECT_EQ(20, checker.inspectLength("BAA", "AAABB"));
	EXPECT_EQ(30, checker.inspectLength("AAE", "AA"));
}