#include<iostream>
#include<set>
using namespace std;
int T, N, card;
bool ans[100000];

bool is_overlap() {
	set<int> s;
	for (int i = 0; i < N; i++) {
		scanf("%d", &card);
		s.insert(card);
	}
	if (s.size() != N)
		return true;
	else
		return false;
}

int main() {
	cin >> T;
	for(int i = 0; i<T; i++) {
		scanf("%d", &N);
		if (is_overlap())
			ans[i] = 1;
		else
			ans[i] = 0;
	}
	for (int i = 0; i < T; i++)
		if (ans[i])
			cout << "true" << endl;
		else
			cout << "false" << endl;
	return 0;
}