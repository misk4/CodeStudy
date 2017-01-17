#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int main() {

	int dp[1000];
	int time[1000];
	string phase[1000];
	queue<int> q;

	int trial;
	cin >> trial;

	while (trial > 0) {
		int numOfBuilding=0,numOfRule;
		cin >> numOfBuilding;
		cin >> numOfRule;
		int check = 1;
		int from, to;
		
		for (int i = 0; i < numOfBuilding; i++) {
			cin >> time[i];
		}

		int phase = 1;

		while (numOfRule > 0) {
			cin >> from;
			if (check == from) {
				cin >> to;
				q.push(to);
				numOfRule--;
			}
			else {
				check == from;
				if (q.front == from) {

				}
			}






		}

















	}





}