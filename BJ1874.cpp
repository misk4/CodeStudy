#pragma warning(disable:4996)
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int stack[100010];
	char op[200010];

	int i, n,k, top = 0, index = 0,max =0;

	cout << "|\\_/|\n" << "|q p|   /}\n" << "( 0 )\"\"\"\\\n" << "|\"^\"\`    |\n"
		<< "||_/=\\\\__|\n}" << endl;
	scanf("%d", &n);

	while (n--) {
		scanf("%d", &k);
		if (k > max) {
			for (i = max; i < k; i++) {
				stack[top++] = i + 1;
				op[index++] = '+';
			}
		}
		else {
			if (stack[top - 1] != k) {
				printf("NO\n"); return 0;
			}
		}
			top--;
			op[index++] = '-';
			if (max < k)
				max = k;
		
	}

	for (i = 0; i < index; i++)
		printf("%c\n", op[i]);
}