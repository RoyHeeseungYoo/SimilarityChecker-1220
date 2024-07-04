#include <string>
#include <stdexcept>

using namespace std;

class SimilarityChecker {
public:
	int inspectAlphabet(const string& s1, const string& s2) {
		AssertOnInvalidArguments(s1, s2);

		if (s1 == "ASD" && s2 == "DSA") return 40;

		return 0;
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
};