#include<iostream>
#include<algorithm>
using namespace std;

#define INF 999999999

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, E, S, D, W, f[103][103], ans{ -INF }, ans_start{0}, ans_end{0},d[103][103];
		fill(&f[0][0], &f[102][103], INF);
		cin >> N >> E;
		for (int i = 0; i < E; i++) {
			cin >> S >> D >> W;
			f[S][D] = W;
		}
		for (int i = 0; i < 103; i++)
			for (int j = 0; j < 103; j++) {
				if (i == j)
					f[i][j] = 0;
				d[i][j] = f[i][j];
			}


		for (int k = 0; k < N; k++)
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					if (d[i][k] + d[k][j] < d[i][j] && d[k][j] != INF && d[i][k] != INF)
						d[i][j] = d[i][k] + d[k][j];

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if (d[i][j] > ans && d[i][j] != INF) {
					ans_start = i;
					ans_end = j;
					ans = d[i][j];
				}
				if (d[i][j] == ans && d[i][j] != INF) {
					if (ans_start > i) {
						ans_start = i;
						ans_end = j;
					}
					if(ans_start == i)
						if (ans_end > j) {
							ans_start = i;
							ans_end = j;
						}
				}
			}

		for (int i = 0; i < N; i++)
			if (d[i][i] < 0)
				ans = -1;
		if (ans == -1)
			cout << ans << endl;
		else
			cout << ans_start << " " << ans_end << " " << ans << endl;
	}
}