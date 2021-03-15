#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
vector<int> ans;
int M, n, in,T;

void best_sum(int m, vector<int> list) {
	if (!m &&(ans.empty() || ans.size()>list.size())) {
		ans = list;
	}
	if (m <= 0)
		return;
	if (m > 0) {
		for (int i = 0; i < v.size(); i++) {
			vector<int> newlist = list;
			newlist.push_back(v[i]);
			best_sum(m - v[i], newlist);
		}
	}
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
		best_sum(M, vec);
		if (!ans.empty()) {
			cout << ans.size() << " ";
			for (int i = 0; i < ans.size(); i++) {
				printf("%d ", ans[i]);
			}
		}
		else
			printf("-1");
		puts("");
	}
	return 0;
}