#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main() {
	string s,s2;
	cin >> s;
	cin >> s2;

	int dp[1002][1002];
	

	int result = 0;

	for (int i = 1; i <= (int)s.length(); i++) {
		for (int j = 1; j <= (int)s2.length(); j++) {
			if (s[i] == s2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			if (dp[i][j]>0) {
				result = dp[i][j];
			}
		}
	}

	cout << result;

	

	return 0;
}