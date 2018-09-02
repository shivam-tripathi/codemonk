#include <bits/stdc++.h>
using namespace std;

bool isVowel(char);

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
	string s;
	cin >> s;
	size_t len = s.size();
	int maxCount = 0;
	int count = 0;
	for(size_t i=0; i<len; i++) {
		if (!isVowel(s[i])) {
			maxCount = max(maxCount, count);
			count = 0;
		} else {
			count++;
		}
	}
	cout << max(maxCount, count) << endl;
	return 0;
}