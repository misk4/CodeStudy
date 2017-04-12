#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main() {
	string s, s2;
	cin >> s >> s2;

	int result = 0, temp, y = s.length(), x = s2.length();

	int **dp = new int*[x + 2];
	for (int i = 0; i < x + 2; i++) {
		dp[i] = new int[y + 2];
	}
	for (int i = 0; i < x + 2; i++) {
		dp[i][0] = 0;
	}
	for (int i = 0; i < y + 2; i++) {
		dp[0][i] = 0;
	}

	for (int i = 1; i <= x; i++) {
		temp = 0;
		for (int j = 1; j <= y; j++) {
			if (s[j - 1] == s2[i - 1]) {
				temp = dp[i - 1][j - 1] + 1;
				dp[i][j] = temp;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			if (result < dp[i][j]) {
				result = dp[i][j];
			}
		}
		if (temp > result) {
			result = temp;
		}
	}

	cout << result << endl;


	int len1 = result;
	int len2 = len1 - 1;
	int k = y ;

	string word = "";

	for (int i = x; i >0; i--) {
		for (int j = k; j >0; j--) {
			if (dp[i][j] == len1 && dp[i][j - 1] == len2 && dp[i - 1][j] == len2 && dp[i-1][j-1] == len2) {
				len1--;
				len2--;
				word = s2[i-1] + word;
				k = j;
				break;
			}
		}
	}

	cout << word << endl;

	for (int i = 0; i < x + 2; i++) {
		delete[] dp[i];
	}
	delete[]dp;

}