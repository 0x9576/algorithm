#include<iostream>
using namespace std;
int T;
int main() {
	cin >> T;
	while (T--) {
		int count[52] = { 0, }, N, e, ans, mv = -1;
		cin >> N;
		for (int i = 0; i < N; i++) {
			scanf("%d", &e);
			count[e]++;
		}
		for (int i = 0; i < 51; i++)
			if (mv < count[i]) {
				mv = count[i];
				ans = i;
			}
		cout << ans << endl;
	}
	return 0;
}