#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct edge {
    int a, b, c;
    edge(int x, int y, int z) {
        a = x;
        b = y;
        c = z;
    }
};

bool cmp(edge e1, edge e2) {
    return e1.c < e2.c;
}

int find(int parent[], int f) {
    if (f == parent[f])
        return f;
    return parent[f] = find(parent, parent[f]);
}

void uni(int parent[], int p, int c) {
    p = find(parent, p);
    c = find(parent, c);

    parent[c] = p;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        vector <edge> vec;
        int N, E, a, b, c, parent[103], ans = 0;
        for (int i = 0; i < 103; i++)
            parent[i] = i;
        cin >> N >> E;
        for (int i = 0; i < E; i++) {
            cin >> a >> b >> c;
            vec.push_back({ a,b,c });
        }
        sort(vec.begin(), vec.end(), cmp);

        for (auto e : vec) {
            if (find(parent, e.a) != find(parent, e.b)) {
                uni(parent, e.a, e.b);
                ans += e.c;
            }
        }
        cout << ans << endl;
    }
    return 0;
}