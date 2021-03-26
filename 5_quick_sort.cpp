#include<iostream>
#include<random>
#include<algorithm>
using namespace std;
//quicksort (random pivot pick)
random_device rd;
mt19937 mt(rd());

int choose_pivot(int left, int right) {
	uniform_int_distribution<int> dis(left, right);
	int ran = dis(mt);
	return ran;
}

int partition(int* A, int left, int right, int pos) {
	int p = A[pos];
	swap(A[pos], A[left]);
	int i = left + 1;
	for (int j = left + 1; j <= right; j++) {
		if (A[j] < p) {
			swap(A[j], A[i]);
			++i;
		}
	}
	swap(A[left], A[i - 1]);
	return i - 1;
}

void quicksort(int* A, int left, int right) {
	if (left >= right)
		return;
	int pos = choose_pivot(left, right);
	int mid = partition(A, left, right, pos);
	quicksort(A, left, mid - 1);
	quicksort(A, mid + 1, right);
}

int main() {
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		int A[10001] = { 0, };
		for (int i = 0; i < N; i++) {
			scanf("%d", A + i);
		}
		quicksort(A, 0, N - 1);
		for (int i = 0; i < N; i++)
			printf("%d ", A[i]);
		puts("");
	}
}