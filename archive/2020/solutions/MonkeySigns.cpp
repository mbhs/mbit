#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main () {
	string str;
	getline(cin, str);

	map<char, int> cnt;
	int maxCnt = 0;
	for (char c : str) {
		if (c >= 'a' && c <= 'z') c = c - 'a' + 'A'; // Convert to uppercase
		if (c >= 'A' && c <= 'Z') {
			cnt[c]++;
			if (c != 'M') maxCnt = max(cnt[c], maxCnt);
		}
	}

	cout << cnt['M'] + maxCnt << endl;
}