#define INF 9999999
#include<iostream>
#include<queue>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		priority_queue <int> H;
		bool X[101] = { 0, };
		int key[101], path_distance[101];
		int edge[101][101] = { 0, };

		for (int i = 0; i < 101; i++)
			for (int j = 0; j < 101; j++) {
				if(i!=j)
					edge[i][j] = INF;
			}

		int N, E, S, K,d[100],a,b,c;
		cin >> N >> E >> S >> K;
		for (int i = 0; i < K; i++)
			cin >> d[i];
		for (int i = 0; i < S; i++) {
			cin >> a >> b >> c;
			edge[a][b] = c;
		}

		for (int i = 0; i < N; i++) {
			key[i] = (i == S) ? 0 : INF;
			H.push(i);
		}
		while (!H.empty()) {
			int w = H.top();
			X[w] = true;
			path_distance[w] = key[w];
			for (int i = 0; i < 101; i++) {
				if (!X[i] && edge[w][i] != INF) {
					H.pop();
				}
			}
		}
	}
}
