#pragma warning(disable:4996)
#include <cstdio>
#include <iostream>

using namespace std;

int max(int a, int b) {
	if (a >b) {
		return a;
	}
	else {
		return b;
	}
}

int main(int argc, char** argv) {
	
	setbuf(stdout, NULL);

	int T;
	int test_case;

	int w;
	int dp[10010];
	int p[10010],q[10010];

	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		int i;
		scanf("%d", &w);
		for (i = 1; i <= w; i++) {
			scanf("%d", &p[i]);
		}
		p[i] = 0;
		for (i = 1; i <= w; i++) {
			scanf("%d", &q[i]);
		}
		q[i] = 0;
		bool check = true;
		
		dp[1] = max(p[1],q[1]);
		dp[2] = max(dp[1] + p[2], q[2]);

		for (i = 3; i <= w; i++) {
			dp[i] = max(dp[i-2]+q[i], dp[i-1] + p[i]);
		}



		printf("Case #%d\n", test_case);
		printf("%d\n", dp[w]);

		
 
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}