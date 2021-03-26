#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<cmath>
#define P pair<int,int>
#define PP pair<P,P>

using namespace std;
vector<P>vx,vy;
float bestd;

float d(P p1, P p2) {
    return (float) sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

bool cmp(P p1, P p2) {
    return p1.second < p2.second;
}

PP closet_split_pair(vector<P> &Px, vector<P> &Py, float delta) {
    P barX = Px[Px.size() / 2];
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
        return tp;
    }
    vector<P> Lx,Ly,Ry,Rx;
    for (int i = 0; i < Px.size() / 2; i++) {
        Lx.push_back(Px[i]);
    }
    int last_Lx = Lx.back().first;

    for (int i = 0; i < Py.size(); i++) {
        if (Py[i].first <= last_Lx)
            Ly.push_back({ Py[i] });
        else
            Ry.push_back({ Py[i] });
    }

    for (int i = Px.size() / 2; i < Px.size(); i++)
        Rx.push_back(Px[i]);

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
        vy.clear();
        cin >> N;
        bestd = (float) 999999.99;
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &v1, &v2);
            vx.push_back({ v1,v2 });
        }
        vy = vx;
        sort(vx.begin(), vx.end());
        sort(vy.begin(), vy.end(), cmp);
        if (N == 1) {
            printf("0.00\n");
            continue;
        }
        PP bp = closet_pair(vx, vy);
        printf("%.2f\n", d(bp.first, bp.second));
    }
}