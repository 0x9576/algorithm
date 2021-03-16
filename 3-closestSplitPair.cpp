#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<cmath>
#define PP pair<pair<int,int>,P>
#define P pair<int,int>

using namespace std;
vector<P>vx;
float bestd;

float d(P p1, P p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

bool cmp(pair<int, int> p1, pair<int, int > p2) {
    return p1.second < p2.second;
}

PP closet_split_pair(vector<P> Px, vector<P> Py, float delta) {
    P barX = Px[Px.size() / 2];
    sort(Py.begin(), Py.end(), cmp);
    vector <P> Sy;
    PP best_pair = { {0,0},{99999,99999} };
    for (auto q : Py)
        if (barX.first - delta < q.first && q.first < barX.first + delta)
            Sy.push_back(q);
    for (int i = 0; i < Sy.size(); i++) {
        for (int j = 1; j < min((int)Sy.size() - i, 7); j++) {
            float temd = d(Sy[i], Sy[i + j]);
            if (temd < delta) {
                delta = temd;
                best_pair = { Sy[i],Sy[i + j] };
            }
        }
    }
    return best_pair;
}

PP closet_pair(vector<P> Px, vector<P> Py) {
    if (Px.size() <= 3) {
        float mn = bestd;
        PP tp = { {0,0},{99999,99999} };
        for (int i = 0; i < Px.size() - 1; i++)
            for (int j = i + 1; j < Px.size(); j++) {
                float dis = d(Px[i], Px[j]);
                if (mn > dis) {
                    mn = dis;
                    tp = { Px[i],Px[j] };
                }
            }
        for (int i = 0; i < Py.size() - 1; i++)
            for (int j = i + 1; j < Py.size(); j++) {
                float dis = d(Py[i], Py[j]);
                if (mn > dis) {
                    mn = dis;
                    tp = { Py[i],Py[j] };
                }
            }
        return tp;
    }

    vector<P> Lx;
    for (int i = 0; i < Px.size() / 2; i++)
        Lx.push_back(Px[i]);
    vector<P> Ly;
    Ly = Lx;
    vector<P> Rx;
    for (int i = Px.size() / 2; i < Px.size(); i++)
        Rx.push_back(Px[i]);
    vector<P> Ry;
    Ry = Rx;

    PP lef = closet_pair(Lx, Ly);
    PP rig = closet_pair(Rx, Ry);
    float ld = d(lef.first, lef.second);
    float rd = d(rig.first, rig.second);
    bestd = min(bestd, min(ld, rd));

    PP spl = closet_split_pair(Px, Py, min(ld, rd));
    float sd = d(spl.first, spl.second);
    bestd = min(bestd, sd);

    if (ld <= rd && ld <= sd)
        return lef;
    if (rd <= ld && rd <= sd)
        return rig;
    return spl;
}

int main() {
    int T, N, v1, v2;
    cin >> T;
    while (T--) {
        vx.clear();
        cin >> N;
        bestd = 999999.99;
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &v1, &v2);
            vx.push_back({ v1,v2 });
        }
        sort(vx.begin(), vx.end());
        if (N == 1) {
            printf("0.00\n");
            continue;
        }
        PP bp = closet_pair(vx, vx);
        printf("%.2f\n", d(bp.first, bp.second));
    }
}