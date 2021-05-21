#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<vector>
#include<queue>

using namespace std;

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

int length(Node node) {
	int ret = 0;
	for (int i = 0; i < node.tour.size() - 1; i++) {
		ret += G[node.tour[i]][node.tour[i + 1]];
	}
	return ret;
}

int compute_bound(Node node) {
	int bound = 0;
	bound += length(node);
	vector<int> tem;
	for (int a : node.unvisited) {
		tem.push_back(a);
	}
	for (int i = 0; i < tem.size(); i++) {
		int min_w = -1;
		for (int j = 0; j < tem.size(); j++) {
			if (tem[i] != tem[j])
				min_w = min(min_w, G[tem[i]][tem[j]]);
		}
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
	min_length = INT_MAX;

	while (!q.empty())
	{
		Node node = q.top();
		q.pop();
		if (node.bound < min_length) {
			for (int i = 2; i <= N; i++) {
				if (!node.unvisited.count(i))
					continue;
				if (G[node.level][i] == INT_MAX)
					continue;
				Node next = node;
				next.level = node.level + 1;
				next.tour.push_back(i);
				next.unvisited.erase(i);
				if (next.level == N - 2) {
					if (length(next) < min_length)
						min_length = length(next);
				}
				else {
					next.bound = compute_bound(next);
					cout << next.bound << endl;
					if (next.bound < min_length) q.push(next);
				}
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		min_length = INT_MAX;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				cin >> G[i][j];
				if (G[i][j] == -1 || !G[i][j])
					G[i][j] = INT_MAX;
			}
		tsp(N);
		cout << min_length << endl;
	}
}