#include<iostream>
using namespace std;
int paper[2500][2500] = { 0, };
int arr[3];
void check(int N, int x, int y) {
	bool minus = 1, zero = 1, plus = 1;
	if (N == 1) {
		arr[paper[x][y] + 1]++;
		return;
	}
	for (int i = x; i < x + N; i++)
		for (int j = y; j < y + N; j++) {
			if (paper[i][j] == -1) {
				zero = 0;
				plus = 0;
			}
			else if (!paper[i][j]) {
				minus = 0;
				plus = 0;
			}
			else {
				zero = 0;
				minus = 0;
			}
		}
	if (minus)
		arr[0]++;
	else if (zero)
		arr[1]++;
	else if (plus)
		arr[2]++;
	else {
		int newN = N / 3;
		check(newN, x, y);

		check(newN, x + newN, y);
		check(newN, x, y + newN);
		check(newN, x + newN, y + newN);

		check(newN, x + 2 * newN, y);
		check(newN, x, y + 2 * newN);
		check(newN, x + 2 * newN, y + 2 * newN);

		check(newN, x + 2 * newN, y + newN);
		check(newN, x + newN, y + 2 * newN);
	}
}

int main() {
	int N, n;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", paper[i] + j);
	check(N, 0, 0);
	for (int i = 0; i < 3; i++)
		cout << arr[i] << endl;
}