#pragma warning(disable:4996)

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	setbuf(stdout, NULL);

	int T;
	int test_case;
	int **map;
	bool *check;

	int result=0;

	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		int k, l, n, m;
		int i, j;
		int a, b;
		scanf("%d %d %d %d", &k, &l, &n, &m);
		map = new int*[n+1];
		check = new bool[n+1];
		for (i = 0; i <= n; i++) {
			map[i] = new int[n+1];
			check[i] = false;
		}
		
		for (i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			map[a][b] = map[b][a] = 1;
		}

		int V = n;
		int count = 0;

		while (1) {
			for (i = 1; i < n; i++) {
				if (check[i])continue;
				for (j = 1; j <= n; j++) count += map[i][j];
				if (count<k || count > V - l - 1) {
					V--;
					check[i] = true;
					for (j = 1; j <= n; j++)map[i][j] = map[j][i] = 0;
					break;
				}
			}

			if (i == n + 1) {
				break;
			}


		}

		for (i = 1; i <= n; i++) {
			if (check[i]) {
				result += i;
			}
		}
		


		printf("Case #%d\n", test_case);
		printf("%d\n", result);


		for (int i = 0; i < n; i++) {
			delete[] map[i];
		}
		delete[] map;
		delete[] check;
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}