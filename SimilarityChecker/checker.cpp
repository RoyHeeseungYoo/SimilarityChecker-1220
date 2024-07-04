#include <string>
#include <stdexcept>

using namespace std;

class SimilarityChecker {
public:
	int inspectLength(const string& s1, const string& s2) {
		AssertOnInvalid(s1, s2);

		int A = getBigStringLength(s1, s2);
		int B = getSmallStringLength(s1, s2);

		if (isSameLength(A, B)) return MAX_POINT;
		if (isMoreDoubleLength(A, B)) return MIN_POINT;

		return calculatePartialPoint(A, B);
	}

private:
	int calculatePartialPoint(int A, int B)
	{
		int Gap = A - B;
		return (int)((float)MAX_POINT * (float)(B - Gap) / (float)B);
	}

	bool isMoreDoubleLength(int A, int B)
	{
		return A >= B * 2;
	}

	bool isSameLength(int A, int B)
	{
		return A == B;
	}

	void AssertOnInvalid(const std::string& s1, const std::string& s2)
	{
		if (s1.empty() || s2.empty()) {
			throw length_error("The length of string should be more than 0.");
		}
	}

	int getBigStringLength(const string& s1, const string& s2) {
		return s1.length() >= s2.length() ? s1.length() : s2.length();
	}
	
	int getSmallStringLength(const string& s1, const string& s2) {
		return s1.length() >= s2.length() ? s2.length() : s1.length();
	}

	const int MAX_POINT = 60;
	const int MIN_POINT = 0;
};