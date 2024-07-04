#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

class SimilarityChecker {
public:
	int inspectAlphabet(const string& s1, const string& s2) {
		AssertOnInvalidArguments(s1, s2);

		int totalCnt = 0;
		int sameCnt = 0;
		int alphaHit[26] = { HIT_BY_NOTHING, };

		processString1(s1, alphaHit, totalCnt);
		processString2(s2, alphaHit, totalCnt, sameCnt);

		return calculateFinalAlphaPoint(sameCnt, totalCnt);
	}

private:
	void AssertOnInvalidArguments(const std::string& s1, const std::string& s2)
	{
		if (isNonCapital(s1) || isNonCapital(s2)) {
			throw invalid_argument("");
		}
	}

	bool isNonCapital(const std::string& str)
	{
		for (auto ch : str) {
			if (ch < 'A' || ch > 'Z') return true;
		}
		return false;
	}

	int calculateFinalAlphaPoint(int sameCnt, int totalCnt)
	{
		return (int)((float)MAX_ALPHA_POINT * (float)sameCnt / (float)totalCnt);
	}

	void processString2(const std::string& s2, int  alphaHit[26], int& totalCnt, int& sameCnt)
	{
		for (const char& ch : s2) {
			int idx = getAlphaHitIndex(ch);
			if (isHitByNothing(alphaHit, idx)) totalCnt++;
			if (isHitByString1(alphaHit, idx)) sameCnt++;
			alphaHit[idx] = HIT_BY_STRING_2;
		}
	}

	void processString1(const std::string& s1, int  alphaHit[26], int& totalCnt)
	{
		for (const char& ch : s1) {
			int idx = getAlphaHitIndex(ch);
			if (isHitByNothing(alphaHit, idx)) totalCnt++;
			alphaHit[idx] = HIT_BY_STRING_1;
		}
	}

	bool isHitByString1(int  alphaHit[26], int idx)
	{
		return alphaHit[idx] == HIT_BY_STRING_1;
	}

	bool isHitByNothing(int  alphaHit[26], int idx)
	{
		return alphaHit[idx] == HIT_BY_NOTHING;
	}

	int getAlphaHitIndex(const char& ch)
	{
		return ch - 'A';
	}

	const int MAX_ALPHA_POINT = 40;
	const int HIT_BY_NOTHING = 0;
	const int HIT_BY_STRING_1 = 1;
	const int HIT_BY_STRING_2 = 2;
};