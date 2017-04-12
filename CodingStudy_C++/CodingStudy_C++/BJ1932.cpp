#include <cstdio>
#include <iostream>

using namespace std;

int cost[500][500];
int dp[500][500];
int sizeOfTriangle;

void getInput() {
	cin >> sizeOfTriangle;
	int k=1;
	for (int i = 0; i < sizeOfTriangle; i++) {
		for (int j = 0; j < k; j++) {
			cin >> cost[i][j];
		}
		k++;
	}

	dp[0][0] = cost[0][0];

}

int max(int a,int b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}

int findMaximumCost() {
	int i, j,result=0;
	int k = 3;


	dp[1][0] = cost[1][0] + dp[0][0];
	dp[1][1] = cost[1][1] + dp[0][0];
	for (i = 2; i < sizeOfTriangle; i++) {
		for (j = 0; j < k; j++) {
			if (j == 0) {
				dp[i][j] = cost[i][j] + dp[i - 1][j];
				continue;
			}
			else if (j == k - 1) {
				dp[i][j] = cost[i][j] + dp[i - 1][j-1];
			}
			else {
				dp[i][j] = cost[i][j] + max(dp[i - 1][j-1], dp[i - 1][j]);
			}

			if (i==(sizeOfTriangle-1) && dp[i][j] > result) {
				result = dp[i][j];
			}
		}
		k++;
	}


	return result;
}




int main() {

	getInput();

	cout<<findMaximumCost();

}