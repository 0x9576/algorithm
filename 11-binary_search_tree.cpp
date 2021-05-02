#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, F[102],C[105][105];
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> F[i];
		for (int i = 1; i < N + 2; i++)
			C[i][i - 1] = 0;
		for(int s = 0; s<N; s++)
			for (int i = 1; i <= N - s; i++) {
				int p_sum = 0, m = 999999999;
				for (int r = i; r <= i + s; r++) {
					p_sum += F[r];
					m = min(m, C[i][r - 1] + C[r + 1][i + s]);
				}
				C[i][i + s] = p_sum + m;
			}
		cout << C[1][N] << endl;
	}
}