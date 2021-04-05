#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int T,N,E,a,b;
	cin >> T;
	while (T--) {
		vector<vector<int>> connected;
		vector<int> edge[105];
		bool visited[105] = { 0, };
		cin >> N >> E;
		for (int i = 0; i < E; i++) {
			cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				vector<int> con;
				visited[i] = 1;
				queue <int> q;
				q.push(i);
				while (!q.empty()) {
					int node = q.front();
					con.push_back(node);
					q.pop();
					for (int j = 0; j < edge[node].size(); j++){
						int next = edge[node][j];
						if (!visited[next]) {
							visited[next] = 1;
							q.push(next);
						}
					}
				}
				connected.push_back(con);
			}
		}
		int max_size = -1;
		cout << connected.size()<<" ";
		for (int i = 0; i < connected.size(); i++)
			max_size = max(max_size, (int)connected[i].size());
		cout << max_size << endl;
	}
}