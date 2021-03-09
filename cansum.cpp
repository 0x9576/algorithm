#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int M,n,in,T;

bool can_sum(int m) {
	if (m < 0)
		return false;
	if (!m)
		return true;
	for (int i = 0; i < v.size(); i++)
		if (can_sum(m - v[i]))
			return true;
	return false;
}

int main() {
	cin >> T;
	while (T--) {
		v.clear();
		cin >> M >> n;
		for (int i = 0; i < n; i++) {
			scanf("%d", &in);
			v.push_back(in);
		}
		if (can_sum(M))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
}