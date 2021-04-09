#pragma once
#include<iostream>
#include<algorithm>
#define M 99999
using namespace std;

int find(int start, int end, int* wood) {
	if (start == end)
		return wood[start];

	int mid = (start + end) / 2;
	int ret = max(find(start, mid, wood), find(mid + 1, end, wood));

	int low = mid, high = mid + 1;
	int h = min(wood[low], wood[high]);
	ret = max(ret, h * 2);

	while (start < low || high < end) {
		if (high < end && (low == start || wood[low - 1] < wood[high + 1])) {
			high++;
			h = min(h, wood[high]);
		}
		else {
			--low;
			h = min(h, wood[low]);
		}
		ret = max(ret, h * (high - low + 1));
	}
	return ret;
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