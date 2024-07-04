#include <string>
#include <stdexcept>

using namespace std;

class SimilarityChecker {
public:
	int inspectAlphabet(const string& s1, const string& s2) {
		AssertOnInvalidArguments(s1, s2);

		int totalCnt = 0;
		int sameCnt = 0;

		bool alphaHit[26] = { false, };
		for (const char& ch : s1) {
			int idx = ch - 'A';
			if (!alphaHit[idx]) totalCnt++;
			alphaHit[idx] = true;
		}
		for (const char& ch : s2) {
			int idx = ch - 'A';
			if (!alphaHit[idx]) totalCnt++;
			else sameCnt++;
			alphaHit[idx] = true;
		}

		return (int)((float)MAX_ALPHA_POINT * (float)totalCnt / (float)sameCnt);
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
};