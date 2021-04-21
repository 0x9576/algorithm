#include<iostream>
#include<list>
#include<map>
using namespace std;

class LRU {
	typedef map<int, pair<int,list<int>::iterator>> MAP;
	MAP cache;
	list<int> lis;
	int size;
public:
	LRU(int s) {
		size = s;
	}

	int get(int key) {
		auto it = cache.find(key);
		if (it != cache.end())
		{
			move(it);
			return it->second.first;
		}
		else
			return -1;
	}

	void put(int key, int value) {
		auto it = cache.find(key);
		if (it != cache.end())
			move(it);

		else
		{
			if (size == cache.size())
			{
				cache.erase(lis.back());
				lis.pop_back();
			}
			lis.push_front(key);
		}
		cache[key] = { value, lis.begin() };

	}
	void move(MAP::iterator it)
	{
		int key = it->first;
		lis.push_front(key);
		lis.erase(it->second.second);
		it->second.second = lis.begin();
	}
};


int main() {
	int T;
	cin >> T;
	while (T--) {
		list <int> lis;
		int C, N, K, V;
		bool put_get;

		cin >> C >> N;
		LRU lru(C);
		for (int i = 0; i < N; i++) {
			cin >> put_get;
			if (put_get) { //get
				cin >> K;
				cout << lru.get(K) << " ";
			}
			else { //put
				cin >> K >> V;
				lru.put(K, V);
			}
		}
		cout << endl;
	}
}