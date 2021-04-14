#include<iostream>
#include<algorithm>
using namespace std;

int find(int start, int end, int* wood) {
	if (start == end)
		return wood[end];
	int mid = (start + end) / 2;
	int mx = max(find(start, mid, wood), find(mid + 1, end, wood));
	int high = mid + 1, low = mid;
	int h = min(wood[high], wood[low]);
	mx = max(mx,2* h);
	while (start < low || high < end) {
		if (start == low || wood[high + 1] > wood[low - 1])
			h = min(h, wood[++high]);
		else
			h = min(h, wood[--low]);
		mx = max(mx,h * (high - low + 1));
	}
	return mx;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int wood[20001] = { 0, }, N;
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> wood[i];
		cout << find(0, N - 1, wood) << endl;
	}
}