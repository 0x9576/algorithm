#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<vector>
#include<queue>

using namespace std;

#define INT_MAX 2147483647

int N;
int min_length;
int G[23][23];

struct Node {
    int level;
    int bound;
    vector<int> tour;
    unordered_set <int> unvisited;
};

struct compare {
    bool operator()(Node a, Node b) {
        return a.bound < b.bound;
    }
};

int length(Node& node) {
    int ret = 0;
    for (int i = 0; i < node.tour.size() - 1; i++) {
        ret += G[node.tour[i]][node.tour[i + 1]];
    }
    return ret;
}

int compute_bound(Node& node) {
    int bound = length(node);
    int min_w = INT_MAX;
    for (int a : node.unvisited) {
        for (int b : node.unvisited)
            if (G[a][b] != INT_MAX)
                min_w = min(min_w, G[a][b]);
        bound += min_w;
    }
    return bound;
}

void tsp(int N)
{
    priority_queue <Node, vector<Node>, compare > q;
    Node root;
    root.level = 0;
    root.tour.push_back(1);
    for (int i = 2; i <= N; i++)
        root.unvisited.insert(i);
    root.bound = compute_bound(root);
    q.push(root);
    Node node, next;

    while (!q.empty())
    {
        node = q.top();
        q.pop();
        if (node.bound < min_length) {
            for (int i = 2; i <= N; i++) {
                if (node.unvisited.find(i) == node.unvisited.end())
                    continue;
                if (G[node.tour[node.level]][i] == INT_MAX || G[node.tour[node.level]][i] == 0)
                    continue;
                next = node;
                next.level = node.level + 1;
                next.tour.push_back(i);
                next.unvisited.erase(i);
                if (next.level == N - 1) {
                    next.tour.push_back(1);
                    int next_length = length(next);
                    if (next_length < min_length) {
                        min_length = next_length;
                    }
                }
                else {
                    next.bound = compute_bound(next);
                    if (next.bound < min_length) q.push(next);
                }
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        min_length = INT_MAX;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++) {
                cin >> G[i][j];
                if (G[i][j] == -1)
                    G[i][j] = INT_MAX;
            }
        tsp(N);
        cout << min_length << endl;
    }
}