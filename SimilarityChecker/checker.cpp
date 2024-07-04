#include <string>
#include <stdexcept>

using namespace std;

class SimilarityChecker {
public:
	int inspectAlphabet(const string& s1, const string& s2) {
		if (s1[0] < 'A' || s1[0] > 'Z'
			|| s2[0] < 'A' || s2[0] > 'Z') {
			throw invalid_argument("");
		}
	}
};