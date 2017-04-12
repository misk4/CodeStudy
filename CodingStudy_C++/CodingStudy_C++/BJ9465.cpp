#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 100000;

int sticker[2][MAX], dp[MAX][3];

int max(int a, int b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}

int check(int n, int c, int status) {
	if (c == n) return 0;
	if (dp[c][status] != -1) return dp[c][status];

	int result = check(n, c + 1, 0);
	if (status != 1) result = max(result, check(n,c + 1, 1) + sticker[0][c]);
	if (status != 2) result = max(result, check(n,c + 1, 2) + sticker[1][c]);
	dp[c][status] = result;
	return result;
}

int main() {
	int numOfTest,n;
	cin >> numOfTest;
	while (numOfTest > 0) {
		cin >> n;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++) {
				cin >> sticker[i][j];
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 3; j++) {
				dp[i][j] = -1;
			}
		cout << check(n, 0, 0)<<endl;
		numOfTest--;
	}

	return 0;
}