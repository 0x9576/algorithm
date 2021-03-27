#include<iostream>
using namespace std;

int main() {
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		int s[10001] = { 0, };
		for (int i = 1; i < N; i++) {
			scanf("%d", s + i);
		}
		int mx = 0, mn = 0;
		if (s[1] < s[2]) {
			mx = s[2];
			mn = s[1];
		}
		else {
			mx = s[1];
			mn = s[2];
		}
		int i = 3;
		while (i <= N - 1) {
			if (s[i] < s[i + 1]) {
				if (s[i] < mn)
					mn = s[i];
				if (s[i + 1] > mx)
					mx = s[i + 1];
			}
			else {
				if (s[i + 1] < mn)
					mn = s[i + 1];
				if (s[i] > mx)
					mx = s[i];
			}
			i += 2;
		}
		cout << mx << " " << mn << endl;
	}
}