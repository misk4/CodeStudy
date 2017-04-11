#pragma warning(disable:4996)
#include <cstdio>

using namespace std;

int main() {
	int trial,n;
	long long dp[101] = { 1,1,1,1,2,2,};

	for (int i = 6; i <= 100; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	
	scanf("%d", &trial);

	while (trial--) {
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
}