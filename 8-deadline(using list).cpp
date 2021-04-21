#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;

struct Job {
    int job;
    int deadline;
    int profit;
};

bool feasible(list <int>& lis, int dead) {
    list<int>::iterator it;
    list<int>::iterator insert_iter = lis.end();
    int a;
    for (it = lis.begin(); it != lis.end(); it++) {
        a = *it;
        if (dead <= a) {
            insert_iter = it;
            break;
        }
    }
    lis.insert(insert_iter, dead);

    int count = 1;
    for (it = lis.begin(); it != lis.end(); it++) {
        a = *it;
        if (count > a) { //현재위치 > 현재값. 즉, 더이상 뒤로 갈 수가 없음.
            lis.erase(insert_iter);
            return false;
        }
        count++;
    }
    return true;
}

bool cmp(Job j1, Job j2) {
    if (j1.profit == j2.profit)
        return j1.job < j2.job;
    return j1.profit > j2.profit;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        list <int> lis;
        int N, p, d;
        cin >> N;
        vector<Job> vec;
        vector <int> ans;
        for (int i = 1; i <= N; i++) {
            cin >> d >> p;
            vec.push_back({ i,d,p });
        }

        sort(vec.begin(), vec.end(), cmp);

        lis.push_back(vec[0].deadline);
        ans.push_back(vec[0].job);

        for (int i = 1; i < vec.size(); i++) {
            int dead = vec[i].deadline;
            int id = vec[i].job;
            if (feasible(lis, dead))
                ans.push_back(id);
        }

        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << endl;
    }
}