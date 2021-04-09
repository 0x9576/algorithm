#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define P pair<int,int>
#define INF 9999999

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		priority_queue <P>pq;
		int path_distance[101];
		vector<P> edge[101];
		int N, E, S, K, d[100], a, b, c;

		cin >> N >> E >> S >> K;
		for (int i = 0; i < K; i++)
			cin >> d[i];
		for (int i = 0; i < E; i++) {
			cin >> a >> b >> c;
			edge[a].push_back({ b,c });
		}
		for (int i = 0; i < 101; i++)
			path_distance[i] = INF;

		pq.push({ 0,S });
		path_distance[S] = 0;
		while (!pq.empty()) {
			int w = pq.top().second;
			int co = -pq.top().first;
			pq.pop();
			if (path_distance[w] < co)
				continue;
			for (int i = 0; i < edge[w].size(); i++) {
				int next_node = edge[w][i].first;
				int next_dis = co + edge[w][i].second;
				if (path_distance[next_node] > next_dis) {
					path_distance[next_node] = next_dis;
					pq.push({ -next_dis,next_node });
				}
			}
		}
		for (int i = 0; i < K; i++) {
			if (path_distance[d[i]] < INF)
				cout << path_distance[d[i]]<< " ";
			else
				cout << -1 << " ";
		}
		cout << endl;
	}
}