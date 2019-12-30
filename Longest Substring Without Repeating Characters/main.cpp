#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s);

int main() {
	cout << lengthOfLongestSubstring("pwwkew") << endl;
	return 0;
}

int lengthOfLongestSubstring(string s) {
	if (s.length() <= 1) return s.length();
	int longest = 0;
	for (int i = 0; i < s.length(); i++) {
		unordered_set<char> repeatCount;
		int j = i;
		do {
			repeatCount.insert(s[j]);
			j++;
		} while (repeatCount.find(s[j]) == repeatCount.end() && j < s.length());
		if (repeatCount.size() > longest) {
			longest = repeatCount.size();
		}
	}
	return longest;
}