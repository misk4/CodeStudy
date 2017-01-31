#pragma warning(disable:4996)
#include <cstdio>

using namespace std;

int main() {

	int *num, *dp;
	int i,n, max = 0;

	scanf("%d", &n);
	num = new int[n + 2];
	dp = new int[n + 2];

	for (i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}

	dp[1] = num[1];
	max = dp[1];

	for (i = 2; i <= n; i++) {
		if (dp[i - 1] + num[i] > num[i]) {
			dp[i] = dp[i - 1] + num[i];
		}
		else {
			dp[i] = num[i];
		}

		if (max < dp[i]) {
			max = dp[i];
		}
	}

	printf("%d\n", max);

	delete[]num;
	delete[]dp;
}