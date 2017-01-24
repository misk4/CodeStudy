#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main() {
	string s, s2;
	cin >> s >> s2;

	int result = 0, temp, x = s.length(), y = s2.length();

	int **dp = new int*[y + 2];
	for (int i = 0; i < y + 2; i++) {
		dp[i] = new int[x + 2];
	}
	for (int i = 0; i < y + 2;i++) {
		dp[i][0] = 0;
	}
	for (int i = 0; i < x + 2; i++) {
		dp[0][i] = 0;
	}

	for (int i = 1; i <=y ; i++) {
		temp = 0;
		for (int j = 1; j <= x; j++) {
			if (s[j-1] == s2[i-1]) {
				temp = dp[i - 1][j - 1] + 1;
				dp[i][j] = temp;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			if (result < dp[i][j]) {
				result = dp[i][j];
			}
		}
		if (temp > result) {
			result = temp;
		}
	}

	printf("%d", result);

	for (int i = 0; i < y + 2; i++) {
		delete[] dp[i];
	}
	delete[]dp;

}