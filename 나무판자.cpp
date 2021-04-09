#include<iostream>
#include<algorithm>
using namespace std;

int find(int start, int end, int* wood) {
	if (start == end)
		return wood[start];
	int mid = (start + end) / 2;
	int ret = max(find(start, mid, wood), find(mid + 1, end, wood));
	int high = mid + 1, low = mid;
	int h = min(wood[high], wood[low]);
	ret = max(ret, h * 2);

	while (high < end || low >start) {
		if (high < end && (low == start || wood[low - 1] < wood[high + 1]))
			h = min(h, wood[++high]);
		else
			h = min(h, wood[--low]);
		ret = max(ret, h * (high - low + 1));
	}
	return ret;
}

int main() {
	int T;
	int wood[20001] = { 0, }, N;
	cin >> T;
	while (T--) {

		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> wood[i];
		cout << find(0, N - 1, wood) << endl;
	}
}