#include <cstdio>
#include <iostream>

using namespace std;


int max(int a, int b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}


int main() {
	int dp[10001] = {};
	int wine[10001] = {};
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}

	dp[1] = wine[1];
	if(2<=n)
		dp[2] = wine[1] + wine[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i-1], wine[i] + wine[i - 1] + dp[i - 3]);
		dp[i] = max(dp[i], wine[i] + dp[i - 2]);
	}

	cout << dp[n];
}