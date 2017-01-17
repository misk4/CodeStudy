#include <cstdio>
#include <iostream>

using namespace std;

int dfs(int s,int numOfRules,int *to,int *from,int *time,int *dp ) {
	int result = 0,temp;

	if (dp[s - 1] != -1) {
		return dp[s - 1];
	}

	for (int i = 0; i < numOfRules; i++) {
		if (to[i] == s) {
			temp = dfs(from[i], numOfRules, to, from, time, dp);
			if (result < temp) {
				result = temp;
			}
		}
	}

	result += time[s-1];
	if (dp[s - 1] < result) {
		dp[s - 1] = result;
	}

	return result;
}

int main() {
	int trial,numOfBuildings,numOfRules;
	int *result;
	int time[1000];
	int dp[1000];
	int from[10000];
	int to[10000];
	int start;

	cin >> trial;
	result = new int[trial];
	
	for (int i = 0; i < trial; i++) {
		cin >> numOfBuildings >> numOfRules;
		for (int j = 0; j < numOfBuildings; j++) {
			cin >> time[i];
		}
		for (int j = 0; j < numOfRules; j++) {
			cin >> from[j] >> to[j];
		}
		cin >> start;

		fill_n(dp, 1000, -1);

		result[i] = dfs(start,numOfRules,to,from,time,dp);
	}

	for (int i = 0; i < trial; i++) {
		cout << result[i] << endl;
	}


}