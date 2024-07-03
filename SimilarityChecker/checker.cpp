#include <string>
#include <stdexcept>

using namespace std;

class SimilarityChecker {
public:
	int inspectLength(const string& s1, const string& s2) {
		if (s1.empty() || s2.empty()) {
			throw length_error("The length of string should be more than 0.");
		}
		return 0;
	}
};