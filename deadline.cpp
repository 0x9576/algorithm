#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<set>
#define P pair<int,int>
using namespace std;

bool feasible(list <int> &lis , int &dead) {
	list<int>::iterator it;
	list<int>::iterator insert_iter = lis.begin();
	bool null_flag = true;
	for (it = lis.begin(); it != lis.end(); it++) {
		int a = *it;
		if (a >= dead) {
			if (lis.size() >= a)
				return false;
			if (null_flag) {
				insert_iter = it;
				null_flag = false;
			}
		}
	}
	lis.insert(insert_iter, dead);
	return true;
}

bool cmp(pair<P, int> p1, pair<P, int> p2) {
	return p1.first.second > p2.first.second;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		list <int> lis;
		int N, p, d;
		cin >> N;
		vector<pair<P, int>> vec;
		set <int> ans;
		for (int i = 1; i <= N; i++) {
			cin >> d >> p;
			vec.push_back({ {d,p},i });
		}
		sort(vec.begin(), vec.end(), cmp);

		lis.push_back(vec[0].first.first);
		ans.insert(vec[0].second);

		for (int i = 1; i < vec.size(); i++) {
			int dead = vec[i].first.first;
			int id = vec[i].second;
			if (feasible(lis, dead))
				ans.insert(id);
		}

		for (auto i : ans)
			cout << i << " ";

		cout << endl;
	}
}