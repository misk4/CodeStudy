#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	int coin[100] = {};
	int dp[10001] = {};
	int n, k ,i, j;
	cin >> n>>k;
	dp[0] = 1;
	for (i = 0; i < n; i++) {
		cin >> coin[i];
		for (j = coin[i]; j <= k; j++) {
			if (j - coin[i] >= 0)
				dp[j] += dp[j - coin[i]];
		}
	}

	cout << dp[k];
}