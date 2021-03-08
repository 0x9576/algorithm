#include<iostream>
#include<cstring>
using namespace std;
bool arr[12][12];
int n, m, T, a, b, ans;

bool full(bool f[]) {
	//cout << endl;
	for (int i = 0; i < n; i++) {
		//cout << i << " ";
		if (!f[i])
			return false;
	}
	//cout << endl;
	return true;
}

void picnic(int a, int b, bool f[]) {
	cout << a << " " << b << endl;
	if (full(f)) {
		ans++;
		return;
	}
	for (int j = a + 1; j < n; j++) {
		if (arr[a + 1][j] && !f[a + 1] && !f[j] && a < j) {
			f[a + 1] = 1;
			f[j] = 1;
			picnic(a + 1, j, f);
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
				//cout << i << " " << j << endl;
				bool d[12] = { 0, };
				d[0] = 1;
				d[j] = 1;
				picnic(0, j, d);
			}
		}
		cout << ans;
	}

}