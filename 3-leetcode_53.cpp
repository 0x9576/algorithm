#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> dc(int n[], int s, int e) {
    vector<int> nv;
    if (s == e) {
        for (int i = 0; i < 4; i++)
            nv.push_back(n[s]);
        return nv;
    }
    int m = s + (e - s) / 2;
    vector<int> L = dc(n, s, m);
    vector<int> R = dc(n, m + 1, e);
    int r1 = max(L[0], L[3] + R[0]); //좌측의 최대
    int r2 = max(R[1], R[3] + L[1]); //우측의 최대 비교
    int r3 = max(max(L[2], R[2]), L[1] + R[0]); //부분합의 최대
    int r4 = L[3] + R[3]; //전체합
    nv.push_back(r1);
    nv.push_back(r2);
    nv.push_back(r3);
    nv.push_back(r4);
    return nv;
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        int arr[10001] = { 0, };
        for (int i = 0; i < N; i++)
            scanf("%d", arr + i);
        vector<int>ans = dc(arr, 0, N - 1);
        cout << ans[2] << endl;
    }
}