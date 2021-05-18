#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
double max_profit;

struct bag
{
    double profit;
    double weight;
};

bool cmp(bag b1, bag b2) {
    return b1.profit / b1.weight > b2.profit / b2.weight;
}

bool promising(vector<bag> &items, double W, double curr_profit, double curr_weight, int index) {
    if (curr_weight >= W)
        return false;
    else {
        int next_index = index + 1;
        double bound = curr_profit;
        double total_weight = curr_weight;
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

void knapsack(vector<bag> &items, bool* include, double W, double curr_profit, double curr_weight, int index) {
    if (curr_weight <= W && curr_profit > max_profit) {
        max_profit = curr_profit;
    }
    if (promising(items, W, curr_profit, curr_weight, index)) {
        include[index + 1] = true;
        knapsack(items, include, W, curr_profit + items[index + 1].profit
            , curr_weight + items[index + 1].weight, index + 1);
        include[index + 1] = false;
        knapsack(items, include, W, curr_profit, curr_weight, index + 1);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        double W, v, w;
        bool include[505] = { 0, };
        max_profit = -1;
        cin >> W >> N;
        vector<bag> items;
        items.push_back({ 999999999,1 });
        for (int i = 1; i <= N; i++) {
            cin >> v >> w;
            items.push_back({ v,w });
        }
        sort(items.begin(),items.end(),cmp);
        knapsack(items, include, W, 0, 0, 0);
        cout << max_profit << endl;
    }
}