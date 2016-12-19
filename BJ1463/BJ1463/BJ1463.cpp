#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

//Baek Joon 1463
/*

���� X�� ����� �� �ִ� ������ ������ ���� �� ���� �̴�.

X�� 3���� ������ ��������, 3���� ������.
X�� 2�� ������ ��������, 2�� ������.
1�� ����.
���� N�� �־����� ��, ���� ���� ���� �� ���� ������ ����ؼ� 1�� ������� �Ѵ�. ������ ����ϴ� Ƚ���� �ּҰ��� ����Ͻÿ�.

*/

int simplify(int n) {

	if (n % 3 == 0) return simplify(n / 3);
	else if (n % 3 == 1) return simplify((n - 1) / 3);
	else if (n % 2 == 0) return simplify(n / 2);
	else return simplify((n - 1) / 2);
}

void main() {
	int n;

	cout << "Enter number to make it become 1 :";
	cin >> n;

	cout << simplify(n)<<endl;

}