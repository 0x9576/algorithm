#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    int arr[20002] = { 0, };
    while (T--) {
        int N;
        cin >> N;
        for (int i = N - 1; i < 2 * N - 1; i++) {
            scanf("%d", arr + i);
        }
		int i = 2 * N - 3;
        int idx = N - 2;
		while (1) {
			if (idx < 0 || i < 0)
				break;
			if (arr[i] <= arr[i + 1])
				arr[idx--] = arr[i + 1];
			else
				arr[idx--] = arr[i];
			i -= 2;
		}
        idx = 1;
        int ans = -2147483648;
        while (1) {
            if (idx >= 2 * N - 1)
                break;
            if (arr[idx] < arr[0]) {
                ans = max(ans, arr[idx]);
                idx = 2 * (idx + 1) + 1;
            }
            else {
                ans = max(ans, arr[idx + 1]);
                idx = 2 * idx + 1;
            }
        }
        cout << ans << endl;
    }
}