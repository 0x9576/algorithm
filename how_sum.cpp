#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
vector<int> ans;
int M, n, in, T;

void how_sum(int m, vector<int> list) {
	if (!m) {
		ans = list;
		return;
	}
	if (m > 0) {
		for (int i = 0; i < v.size(); i++) {
			vector<int> newlist = list;
			newlist.push_back(v[i]);
			how_sum(m - v[i], newlist);
		}
	}
	return;
}

int main() {
	cin >> T;
	while (T--) {
		v.clear();
		ans.clear();
		cin >> M >> n;
		for (int i = 0; i < n; i++) {
			scanf("%d", &in);
			v.push_back(in);
		}
		if (!M) {
			printf("0\n");
			continue;
		}
		vector<int> vec;
		how_sum(M, vec);
		if (!ans.empty()) {
			cout << ans.size()<<" ";
			for (int i = 0; i < ans.size(); i++) {
				printf("%d ", ans[i]);
			}
		}
		else
			printf("-1");
		puts("");
	}
}