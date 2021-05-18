#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int ans;

bool promising(vector<int> &nums, int curr_total, int left_total, int W, int index) {
	return curr_total + left_total >= W && (curr_total == W || curr_total + nums[index] <= W);
}

void subset_sum(vector<int> &nums, bool included[], int curr_total, int left_total, int W, int index) {
	if (promising(nums, curr_total, left_total, W, index)) {
		if (curr_total == W)
			ans++;
		else {
			included[index] = true;
			left_total -= nums[index];
			subset_sum(nums, included, curr_total + nums[index], left_total, W, index + 1);
			included[index] = false;
			subset_sum(nums, included, curr_total, left_total, W, index + 1);
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		ans = 0;
		int N, M,e;
		vector<int> nums;
		bool included[27] = { 0, };
		cin >> M >> N;
		nums.push_back(-9999999);
		nums.push_back(99999999);
		for (int i = 0; i < N; i++) {
			cin >> e;
			nums.push_back(e);
		}
		sort(nums.begin(), nums.end());
		subset_sum(nums, included, 0, M, M, 0);
		cout << ans<<endl;
	}
}