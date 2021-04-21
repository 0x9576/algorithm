#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        vector <pair<int,int>> vec [101];
        priority_queue <pair<int, int>>pq;
        bool visited[101] = { 0, };
        int N, E, S, a, b, c, ans = 0;

        cin >> N >> E;
        S = 0;
        visited[S] = 1;

        for (int i = 0; i < E; i++) {
            cin >> a >> b >> c;
            vec[a].push_back({ c,b });
            vec[b].push_back({ c,a });
        }

        for (auto i : vec[S]) {
            int cost = i.first;
            int des = i.second;
            pq.push({ -cost,des });
        }

        while (!pq.empty()) {
            int now = pq.top().second;
            int co = -pq.top().first;
            pq.pop();
            if (visited[now])
                continue;

            visited[now] = 1;
            ans += co;
            for (auto i : vec[now]) {
                int cost = i.first;
                int des = i.second;
                pq.push({ -cost,des });
            }
        }
        cout << ans<< endl;
    }
}