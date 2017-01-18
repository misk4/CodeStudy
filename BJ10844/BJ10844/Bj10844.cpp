#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int dp[101][10] = { 0 };

	for (int i = 1; i < 10; i++) {
			dp[1][i] = 1;
	}

	for (int i = 2; i < 101; i++) {
		for (int j = 0; j < 10; j++) {
			if (j - 1 >= 0) dp[i][j] += dp[i - 1][j - 1];
			if (j + 1 <= 9) dp[i][j] += dp[i - 1][j + 1];
			dp[i][j] %= 1000000000;
		}
	}
	int answer = 0;
	for (int i = 0; i < 10; i++) {
		answer += dp[n][i];
		answer %= 1000000000;
	}

	cout << answer;
}