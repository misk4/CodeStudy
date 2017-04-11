#include <iostream>
#include <cstdio>
#include <vector>


using namespace std;
const int MAX = 1000001;

//Baek Joon 1463
/*

���� X�� ����� �� �ִ� ������ ������ ���� �� ���� �̴�.

X�� 3���� ������ ��������, 3���� ������.
X�� 2�� ������ ��������, 2�� ������.
1�� ����.
���� N�� �־����� ��, ���� ���� ���� �� ���� ������ ����ؼ� 1�� ������� �Ѵ�. ������ ����ϴ� Ƚ���� �ּҰ��� ����Ͻÿ�.

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