#include<iostream>
#include<vector>
using namespace std;

bool flag;

void dfs(int node, int* visited, vector<int>* edge) {
	for (int i = 0; i < edge[node].size(); i++) {
		int next = edge[node][i];
		if (!visited[next]) {
			visited[next] = 1;
			dfs(next, visited, edge);
			visited[next] = 2;
		}
		if (visited[next] == 1)
			flag = true;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int T, N, E, a, b;
	cin >> T;
	while (T--) {
		flag = false;
		int visited[105] = { 0, };
		vector<int> edge[105];
		cin >> N >> E;
		for (int i = 0; i < E; i++) {
			cin >> a >> b;
			edge[a].push_back(b);
		}
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				visited[i] = 1;
				dfs(i, visited, edge);
				visited[i] = 2;
			}
		}
		flag ? cout << "true" : cout << "false";
		cout << endl;
	}
}