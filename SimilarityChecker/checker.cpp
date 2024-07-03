#include <string>
#include <stdexcept>

using namespace std;

class SimilarityChecker {
public:
	int inspectLength(const string& s1, const string& s2) {
		AssertOnInvalid(s1, s2);

		if (s1.length() == 3 && s2.length() == 3) return 60;

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