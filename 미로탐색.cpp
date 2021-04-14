#include<iostream>
#include<queue>
using namespace std;

int main() {
	int N, M, arr[103][103] = { 0, };
	bool visited[103][103] = { 0, };
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%1d", arr[i] + j);
	queue <pair<pair<int,int>,int>> q;
	q.push({ { 1,1 },1 });
	visited[1][1] = true;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int count = q.front().second;
		q.pop();
		if (y == N && x == M) {
			cout << count << endl;
			break;
		}
		if (arr[y][x + 1] && !visited[y][x + 1]) {
			q.push({ {y,x + 1},count + 1 });
			visited[y][x + 1] = true;
		}
		if (arr[y][x - 1] && !visited[y][x - 1]) {
			q.push({ {y,x - 1},count + 1 });
			visited[y][x - 1] = true;
		}
		if (arr[y + 1][x] && !visited[y + 1][x]) {
			q.push({ {y + 1,x},count + 1 });
			visited[y + 1][x] = true;
		}
		if (arr[y - 1][x] && !visited[y - 1][x]) {
			q.push({ {y - 1,x},count + 1 });
			visited[y - 1][x] = true;
		}
	}
}