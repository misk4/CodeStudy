#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

vector<int> mem;

int fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (mem[n] != -1) return mem[n];

	mem[n] = fibonacci(n - 2) + fibonacci(n - 1);

	return mem[n];

}

void main() {
	int numOfFibo;

	cout << "Enter in the fibonacci number to calculate : ";
	cin >> numOfFibo;

	mem.resize(numOfFibo + 1, -1);

	cout << fibonacci(numOfFibo) << endl;
}