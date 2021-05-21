#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N;
double max_profit;

struct Node {
    int level;
    double curr_profit;
    double curr_weight;
    double bound;
};

struct item {
    double profit;
    double weight;
};

bool cmp(item b1, item b2) {
    return b1.profit / b1.weight > b2.profit / b2.weight;
}

struct compare {
    bool operator()(Node a, Node b) {
        return a.bound < b.bound;
    }
};

double compute_bound(vector<item> &items, double W, Node node) {
    double curr_profit = node.curr_profit;
    double curr_weight = node.curr_weight;
    int index = node.level;
    if (curr_weight >= W)
        return 0;
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
        return bound;
    }
}

void knapsack(double W, vector<item> &items)
{
    priority_queue <Node, vector<Node>, compare > q;
    Node root;
    root.bound = 0;
    root.curr_profit = 0;
    root.curr_weight = 0;
    root.level = 0;

    q.push(root);

    while (!q.empty())
    {
        Node node = q.top();
        q.pop();
        node.level++;
        node.curr_weight += items[node.level].weight;
        node.curr_profit += items[node.level].profit;
        if (node.curr_weight <= W and node.curr_profit > max_profit)
            max_profit = node.curr_profit;
        double bound = compute_bound(items, W, node);

        if (bound > max_profit) {
            node.bound = bound;
            q.push(node);
        }
        node.curr_weight -= items[node.level].weight;
        node.curr_profit -= items[node.level].profit;
        bound = compute_bound(items, W, node);
        if (bound > max_profit) {
            node.bound = bound;
            q.push(node);
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        double W, v, w;
        max_profit = -1;
        cin >> W >> N;
        vector<item> items;
        items.push_back({ 9999999999,1 });
        for (int i = 1; i <= N; i++) {
            cin >> v >> w;
            items.push_back({ v,w });
        }
        sort(items.begin(), items.end(), cmp);
        knapsack(W, items);
        cout << max_profit << endl;
    }
}