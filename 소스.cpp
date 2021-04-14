#include<iostream>
#include<queue>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int arr[204][204] = { 0, }, n, m;
		cin >> n >> m;
		int ans = 9999999;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", arr[i] + j);
		queue<pair<int, pair<int, int>>> q;
		q.push({ arr[1][1],{1,1} });
		int d[2][2] = { {1,0},{0,1} };
		while (!q.empty()) {
			int cost = q.front().first;
			int y = q.front().second.first;
			int x = q.front().second.second;
			q.pop();
			if (y == n && x == m) {
				ans = min(ans, cost);
			}
			if (arr[y + d[0][0]][x + d[0][1]] < arr[y + d[1][0]][x + d[1][1]]) {
				q.push({ arr[y + d[0][0]][x + d[0][1]] + cost,{y + d[0][0],x + d[0][1]}});
			}
			else
				q.push({ arr[y + d[1][0]][x + d[1][1]] + cost,{y + d[1][0],x + d[1][1]} });
		}
		cout << ans << endl;
	}
}