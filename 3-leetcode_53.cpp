#include <iostream>
#include<algorithm>
using namespace std;
int merge(int arr[], int p, int q, int r) {
	int i = p, j = q + 1, k = p;
	int con = q - p + 1, co = 0;
	int tmp[10001] = { 0, };
	while (i <= q && j <= r) {
		if (arr[i] <= arr[j]) {
			tmp[k++] = arr[i++];
			con--;
		}
		else {
			tmp[k++] = arr[j++];
			co += con;
		}
	}
	while (i <= q) {
		tmp[k++] = arr[i++];
	}
	while (j <= r) {
		tmp[k++] = arr[j++];
	}
	for (int a = p; a <= r; a++) arr[a] = tmp[a];
	return co;
}

int mergeSort(int arr[], int p, int r) {
	if (r - p < 1)
		return 0;
	int q = (p + r) / 2;
	mergeSort(arr, p, q), mergeSort(arr, q + 1, r) + merge(arr, p, q, r);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int arr[10001], N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			scanf("%d", arr + i);
		}
		int ans = mergeSort(arr, 0, N - 1);
		cout << ans;
		puts("");
	}
}