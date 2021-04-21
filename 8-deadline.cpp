#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<set>
using namespace std;

struct Job {
	int job;
	int deadline;
	int profit;
};

bool cmp(Job j1,Job j2) {
	if (j1.profit == j2.profit)
		return j1.job < j2.job;
	return j1.profit > j2.profit;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, p, d;
		cin >> N;
		Job scheduled[1002];
		vector<Job> jobs;
		bool filled[1002] = { 0, };
		set <int> ans;
		for (int i = 1; i <= N; i++) {
			cin >> d >> p;
			jobs.push_back({i,d,p});
		}

		sort(jobs.begin(), jobs.end(), cmp);

		scheduled[jobs[0].deadline] = jobs[0];
		ans.insert(jobs[0].job);
		filled[jobs[0].deadline] = 1;

		for (int i = 1; i < jobs.size(); i++) {
			for (int j = jobs[i].deadline; j >= 1; j--) {
				if (!filled[j]) {
					scheduled[j] = jobs[i];
					filled[j] = 1;
					ans.insert(jobs[i].job);
					break;
				}
			}
		}

		for (auto i : ans)
			cout << i << " ";

		cout << endl;
	}
}