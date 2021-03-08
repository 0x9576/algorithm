#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int M, n, in;

int count_sum(int m) {
	if (m < 0)
		return 0;
	if (!m)
		return 1;
	int count = 0;
	for (int i = 0; i < v.size(); i++)
		count += count_sum(m - v[i]);
	return count;
}

int main() {
	cin >> M >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		v.push_back(in);
	}
	cout << count_sum(M) << endl;
}