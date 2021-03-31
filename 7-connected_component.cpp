#include<iostream>
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
		vector<int> edge[101];
		bool visited[101] = { 0, };
		queue <int> q;
		cin >> N >> E;
		for (int i = 0; i < E; i++) {
			cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
	}
}