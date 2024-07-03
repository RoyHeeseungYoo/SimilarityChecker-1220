#include <string>
#include <stdexcept>

using namespace std;

class SimilarityChecker {
public:
	int inspectLength(const string& s1, const string& s2) {
		AssertOnInvalid(s1, s2);

		if (s1.length() == s2.length()) return 60;
		if (s1.length() == 5 && s2.length() == 3
			|| s1.length() == 3 && s2.length() == 5) return 20;
		if (s1.length() == 2 && s2.length() == 3
			|| s1.length() == 3 && s2.length() == 2) return 30;

		return 0;
	}

private:
	void AssertOnInvalid(const std::string& s1, const std::string& s2)
	{
		if (s1.empty() || s2.empty()) {
			throw length_error("The length of string should be more than 0.");
		}
	}
};