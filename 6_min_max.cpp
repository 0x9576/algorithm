#include<iostream>
using namespace std;
int s[10004] = { 0, };

int main() {
	int T, N;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
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
		printf("%d %d\n", mx, mn);
	}
}