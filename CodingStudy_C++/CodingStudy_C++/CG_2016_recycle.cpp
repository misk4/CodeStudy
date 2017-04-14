
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int h[501],dp[501][501],dis[501][501];
int H, B;	//house, bin


int min(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}
void sort() {
	int i, j, temp = 0;
	for (i = 1; i <= H; i++) {
		for (j = 1; j < H; j++) {
			if (h[j] > h[j + 1]) {
				temp = h[j];
				h[j] = h[j + 1];
				h[j + 1] = temp;
			}
		}
	}
}

void init() {
	for (int i = 1; i <= H; i++) {
		for (int j = i; j <= H; j++)
		{
			int mid = (i + j) / 2;
			for (int k = i; k <= j; k++)
				dis[i][j] += abs(h[mid] - h[k]);
		}
	}
}

int solve(int index, int remainder) {
	if (index == H+1)return 0;
	if (remainder == 0)return 999999999;
	
	int &ret = dp[index][remainder];
	if (ret != -1) return ret;
	ret = 999999999;
	for (int i = index; i <= H; i++) {
		ret = min(ret, dis[index][i] + solve(i + 1, remainder - 1));
	}

	return ret;
}

int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� sample_input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� sample_input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� sample_input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� sample_input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("sample_input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		
		int i, j = 1;
		int min = 100001, max = -1;
		scanf("%d %d", &H, &B);
		for (i = 1; i <= H; i++) {
			scanf("%d", &h[i]);
			for (j = 1; j <= H; j++) {
				dis[i][j] = 0;
				dp[i][j] = -1;
			}
		}
		
		sort();
		init();

		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", solve(1,B));

	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}