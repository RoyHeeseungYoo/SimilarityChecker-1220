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
		for (const char& ch : s1) {
			int idx = ch - 'A';
			if (alphaHit[idx] == HIT_BY_NOTHING) totalCnt++;
			alphaHit[idx] = HIT_BY_STRING_1;
		}
		for (const char& ch : s2) {
			int idx = ch - 'A';
			if (alphaHit[idx] == HIT_BY_NOTHING) totalCnt++;
			else if (alphaHit[idx] == HIT_BY_STRING_1)sameCnt++;
			alphaHit[idx] = HIT_BY_STRING_2;
		}

		return (int)((float)MAX_ALPHA_POINT * (float)sameCnt / (float)totalCnt );
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

	const int MAX_ALPHA_POINT = 40;
	const int HIT_BY_NOTHING = 0;
	const int HIT_BY_STRING_1 = 1;
	const int HIT_BY_STRING_2 = 2;
};