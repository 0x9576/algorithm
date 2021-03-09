#include<iostream>
#include<cstring>
using namespace std;
bool arr[12][12];
int n, m, T, a, b, ans;

int find_nextnum(int a, bool f[]) {
	for (int i = a; i < 12; i++)
		if (!f[i])
			return i;
}

bool full(bool f[]) {
	for (int i = 0; i < n; i++) {
		if (!f[i])
			return false;
	}
	return true;
}

void picnic(int a, int b, bool f[]) {
	if (full(f)) {
		ans++;
		return;
	}
	int nex = find_nextnum(a, f);
	for (int j = nex; j < n; j++) {
		bool tem[12] = { 0, };
		for (int i = 0; i < 12; i++)
			tem[i] = f[i];
		if (arr[nex][j] && !f[j] && nex < j) {
			tem[nex] = 1;
			tem[j] = 1;
			picnic(nex, j, tem);
		}
	}
}

int main() {
	cin >> T;
	while (T--) {
		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 12; j++)
				arr[i][j] = 0;
		ans = 0;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			arr[a][b] = 1;
			arr[b][a] = 1;
		}
		for (int j = 0; j < n; j++) {
			if (arr[0][j]) {
				bool d[12] = { 0, };
				d[0] = 1;
				d[j] = 1;
				picnic(0, j, d);
			}
		}
		cout << ans<<endl;
	}
}