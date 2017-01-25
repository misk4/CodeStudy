#pragma warning(disable: 4996) 
#include <cstdio>


using namespace std;

int file[501],fileSum[501];
int dp[501][501];

int min(int a, int b) {
	if (a <= b) {
		return a;
	}
	else {
		return b;
	}
}

int getMin(int start, int end) {
	if (start >= end) return 0;
	if (start+1 == end) return file[start] + file[end];
	if (dp[start][end] != 1200000000) return dp[start][end];

	for (int i = start; i < end; i++) {
		dp[start][end] = min(dp[start][end], getMin(start,i) + getMin(i+1,end) + fileSum[end] - fileSum[start - 1]);
	}

	return dp[start][end];
}

int main() {

	int trial,n;
	scanf("%d", &trial);
	while (trial--) {
		scanf("%d", &n);
		
		fileSum[0] = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &file[i + 1]);
			fileSum[i + 1] = fileSum[i] + file[i + 1];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = 1200000000;
			}
		}

		printf("%d\n", getMin(1, n));
	}

}