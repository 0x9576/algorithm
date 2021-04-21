#include<iostream>
#include<list>
#include<map>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		list <int> lis;
		int C, N, K, V, cache[1003], count = 0;
		map <int, list<int>::iterator > iter_map;
		map <int, list<int>::iterator >::iterator iter;
		for (int i = 0; i < 1003; i++)
			cache[i] = -1;
		bool put_get;

		cin >> C >> N;
		for (int i = 0; i < N; i++) {
			cin >> put_get;
			if (put_get) { //get
				cin >> K;
				cout << cache[K] << " ";
			}
			else { //put
				cin >> K >> V;
				if (cache[K] != -1) {
					cache[K] = V;
				}
				else {
					if (C > count) {
						cache[K] = V;
						count++;
					}
					else {
						int k = lis.back();
						cache[k] = -1;
						iter_map.erase(k);
						lis.pop_back();
						cache[K] = V;
					}
				}
			}
			iter = iter_map.find(K);
			if (iter != iter_map.end())
				lis.erase(iter->second);
			lis.push_front(K);
			iter_map.insert({ K, lis.begin() });
		}
		cout << endl;
	}
}