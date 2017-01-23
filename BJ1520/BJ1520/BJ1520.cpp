#include <cstdio>
#include <iostream>

using namespace std;

int getPath(int **map, int **dp, int r, int c, int row[],int column[]) {

	if (dp[r][c] != 0) {
		return dp[r][c];
	}

	if (r == dp[0][0] && c == dp[0][1])
		return 1;

	for (int i = 0; i < 4; i++) {
		if (c+column[i] > 0 && c+ column[i] <= dp[0][1] && r+row[i]>0 && r+row[i] <= dp[0][0]&& map[r][c] > map[r+row[i]][c+column[i]]) {
			dp[r][c] += getPath(map, dp, r + row[i], c + column[i],row,column);
		}
	}

	return dp[r][c];
}

int main() {
	int **map, **dp, m, n;
	int row[4] = { 0,0,-1,1 };
	int column[4] = { -1,1,0,0 };

	cin >> m >> n;
	map = new int*[m + 1];
	dp = new int*[m + 1];
	for (int i = 0; i < m + 1; i++) {
		map[i] = new int[n + 1];
		dp[i] = new int[n + 1];
	}

	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			dp[i][j] = 0;
		}
	}

	dp[0][0] = m;
	dp[0][1] = n;
	//cin >> dp[0][1] >> dp[0][0];

	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cin >> map[i][j];
		}
	}

	cout << getPath(map, dp, 1, 1,row,column);

	for (int i = 0; i < m + 1; i++) {
		delete[] map[i];
		delete[] dp[i];
	}
	delete[] map;
	delete[] dp;
}