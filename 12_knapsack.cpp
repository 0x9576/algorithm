#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N,ans;

struct bag
{
	int profit;
	int weight;
};

bool cmp(bag b1, bag b2) {
	return b1.weight < b2.weight;
}

bool promising(vector<bag> &items, int W, int curr_profit, int curr_weight,int max_profit, int index) {
	if (curr_weight >= W)
		return false;
	else {
		int next_index = index + 1;
		double bound = curr_profit;
		int total_weight = curr_weight;
		while (next_index <= N && total_weight + items[next_index].weight <= W) {
			total_weight += items[next_index].weight;
			bound += items[next_index].profit;
			next_index++;
		}
		if (next_index <= N) {
			double score = items[next_index].profit / items[next_index].weight;
			bound += (W - total_weight) * score;
		}
		return bound > max_profit;
	}
}

void knapsack(vector<bag> &items,bool include[], int W, int curr_profit, int curr_weight,int max_profit, int index) {
	if (curr_weight <= W && curr_profit > max_profit) {
		max_profit = curr_profit;
	}
	cout <<index<<" "<< curr_profit << endl;
	if (promising(items, W, curr_profit, curr_weight, max_profit, index)) {
		cout << "true" << endl;
		include[index + 1] = true;
		knapsack(items, include, W, curr_profit + items[index + 1].profit
			, curr_weight + items[index + 1].weight, max_profit, index + 1);
		include[index + 1] = false;
		knapsack(items, include, W, curr_profit, curr_weight, max_profit, index + 1);
	}
	else
		cout << "false" << endl;
	ans = max(ans, max_profit);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int W,v,w;
		bool include[502] = { 0, };
		ans = -1;
		cin >>W>> N;
		vector<bag> items;
		items.push_back({ -99999,999999 });
		for (int i = 1; i <= N; i++) {
			cin >> v >> w;
			items.push_back({ v,w });
		}
		sort(items.begin(), items.end(), cmp);
		knapsack(items, include, W, 0, 0, 0,0);
		cout << ans << endl;
	}
}

/*
1
2 4
1 1
1 5
1 5
1 1

´ä : 2
*/