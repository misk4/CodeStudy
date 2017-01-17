#include <cstdio>
#include <iostream>

using namespace std;

int dfs() {


	return 0;
}

int main() {
	int trial,numOfBuildings,numOfRules;
	int *result;
	int time[1000];
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

		result[i] = dfs();
	}

	for (int i = 0; i < trial; i++) {
		cout << result[i] << endl;
	}


}