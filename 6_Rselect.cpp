#include<iostream>
#include<random>
#include<algorithm>
using namespace std;
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

int Rselect(int* A, int left, int right,int i) {
	if (left == right)
		A[left];
	int p = choose_pivot(left, right);
	int pLoc = partition(A, left, right, p);
	if (pLoc == i)
		return A[i];
	else if(pLoc>i)
		return Rselect(A, left, pLoc - 1,i);
	else
		return Rselect(A, pLoc + 1, right,i);
}

int main() {
	int T, N,k;
	cin >> T;
	while (T--) {
		cin >> N>>k;
		int A[10003] = { 0, };
		for (int i = 1; i <= N; i++) {
			scanf("%d", A + i);
		}
		cout<< Rselect(A, 1, N,k)<<endl;
	}
}