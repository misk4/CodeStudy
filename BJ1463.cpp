#include <iostream>
#include <cstdio>
#include <vector>


using namespace std;
const int MAX = 1000001;

//Baek Joon 1463
/*

정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만드려고 한다. 연산을 사용하는 횟수의 최소값을 출력하시오.

*/

int dp[MAX];

int min(int a, int b) {
	if (a >= b) {
		return b;
	}
	else {
		return a;
	}
}

int simplify(int n) {

	if (n == 1) return 0;
	if (dp[n] != -1) return dp[n];

	int result = simplify(n - 1) + 1;
	if (n % 3 == 0) result = min(result, simplify(n / 3) + 1);
	if (n % 2 == 0) result = min(result, simplify(n / 2) + 1);
	dp[n] = result;

	return result;
}

void main() {
	int n;

	cout << "Enter number to make it become 1 : ";
	cin >> n;
	fill(dp, dp + MAX, -1);

	cout << simplify(n)<<endl;

}