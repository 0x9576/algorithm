#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		int arr[20004] = { 0, };
		cin >> N;
		for (int i = N-1; i < 2*N-1; i++)
			scanf("%d", arr + i);
		int cs = 2*N-2, ps = N-1;
		int idx = N-2;
		while (1) {
			for (int i = 0; i < 2*N-1; i++) {
				cout << arr[i] << " ";
			}
			cout << endl;
			if (idx <=0)
				break;
			for (int i = cs; i => ps; i-=2) {
				if (ps-i == 1) {
					arr[idx--] = arr[i];
				}
				if (arr[i] <= arr[i + 1])
					arr[idx--] = arr[i+1];
				else
					arr[idx--] = arr[i];
			}
			cs = ps-1;
			ps = idx-1;
		}
		/*int mx = v.back();
		int ans = looser[mx][0];
		for (int i = 0; i < looser[mx].size(); i++)
			ans = max(ans, looser[mx][i]);
		cout << ans << endl;*/
	}
}