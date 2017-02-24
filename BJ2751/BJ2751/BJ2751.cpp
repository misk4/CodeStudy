#pragma warning(disable : 4996)
#include <cstdio>

using namespace std;

int *array;
int n = 0;

void merge(int arr[], int left, int mid, int right) {
	int *temp;
	int i = left, j = mid + 1;

	int index = 0;

	temp = new int[right-left +1];

	while (i <= mid && j <= right) {
		if (arr[i] < arr[j]) {
			temp[index] = arr[i];
			i++;
		}
		else {
			temp[index] = arr[j];
			j++;
		}
		index++;
	}

	if (i <= mid) {
		for (i; i <= mid; i++) {
			temp[index] = arr[i];
			index++;
		}
	}
	else {
		for (j; j <= right; j++) {
			temp[index] = arr[j];
			index++;
		}
	}
	index = 0;
	for (i = left; i <= right; i++) {
		arr[i] = temp[index];
		index++;
	}

	delete temp;

}

void mergesort(int arr[], int left, int right) {
	int mid = (left + right) / 2;

	
	if (left < right) {

		mergesort(arr, left, mid);
		mergesort(arr, mid + 1, right);

		merge(arr, left, mid, right);

	}

}



int main() {

	scanf("%d", &n);

	array = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}

	mergesort(array, 0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%d\n", array[i]);
	}

	delete array;
}