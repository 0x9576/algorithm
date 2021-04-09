#define INF 9999999
#include<iostream>
#include<queue>
#define P pair<int,int>
using namespace std;

class PQ {
	class HeapIterator : public iterator<input_iterator_tag, int> {
		P* p;
	public:
		explicit HeapIterator(P* p) : p{ p } {}
		const HeapIterator& operator++() { ++p; return *this; }
		HeapIterator operator++(int) { HeapIterator retval = *this; ++p; return retval; }
		bool operator==(const HeapIterator& other) const { return p == other.p; }
		bool operator!= (const HeapIterator& other) const { return !(*this == other); }
		P operator*() const { return *p; }
	};
private:
	unsigned int capacity;
	unsigned int size{ 0 };
	P* heap{ nullptr };
	bool need_more_space() const {
		return size == capacity;
	}
	void increase_capacity() {
		capacity = capacity * 2 + 1;
		P* tmp{ new P[capacity] };
		copy(heap, heap + size, tmp);
		delete[] heap;
		heap = tmp;
	}
public:
	PQ() : capacity{ 101 }, heap{ new P[capacity] }{}
	PQ(initializer_list<P> init_list) : PQ{} {
		for (auto n : init_list) add(n);
	}
	virtual ~PQ() {
		if (heap) delete[] heap;
	}
	PQ(const PQ& other) : capacity{ other.capacity }, heap{ new P[capacity] }, size(other.size){
		copy(other.heap, other.heap + size, heap);
	}
	PQ(PQ&& tmp) : capacity{ tmp.capacity }, heap{ tmp.heap }, size{ tmp.size }{
		tmp.heap = nullptr;
	}
	const PQ& operator=(const PQ& other) {
		capacity = other.capacity;
		size = other.size;
		if (heap) delete[] heap;
		heap = new P[capacity];
		copy(other.heap, other.heap + size, heap);
		return *this;
	}
	const PQ& operator=(PQ&& tmp) {
		capacity = tmp.capacity;
		size = tmp.size;
		if (heap) delete[] heap;
		heap = tmp.heap;
		tmp.heap = nullptr;
		return *this;
	}
	bool is_empty() {
		return size == 0;
	}
	void add(P key) noexcept {
		if (need_more_space()) increase_capacity();
		heap[size] = key;
		reheap_up(size);
		++size;
	}
	int get_min() const {
		return heap[0].second;
	}
	/*int extrat_max() {
		int retval{ heap[0] };
		swap(heap[0], heap[size - 1]);
		heap[0] = heap[size - 1];
		--size;
		reheap_down(0);
		return retval;
	}*/
	void change_priority(int index, P key) {
		if (heap[index] == key) return;
		P prev_key{ heap[index] };
		heap[index] = key;
		if (prev_key > key) reheap_down(index);
		else reheap_up(index);
	}
	void remove(int index) {
		if (index != size-1) {
			change_priority(index, heap[size]);
		}
		--size;
	}
	void pop() {
		remove(0);
	}
	void print() {
		for (int i = 0; i < size; i++) {
			cout << heap[i].second<<" ";
		}
		cout << endl;
	}
	HeapIterator begin() { return HeapIterator(heap); }
	HeapIterator end() { return HeapIterator(heap + size); }
private:
	void reheap_up(int index) {
		int curr_index{ index };
		while (curr_index > 0) {
			int parent_index{ (curr_index - 1) / 2 };
			if (heap[parent_index] > heap[curr_index]) swap(heap[parent_index], heap[curr_index]);
			else return;
			curr_index = parent_index;
		}
	}
	void reheap_down(int index) {
		int curr_index{ index };
		while (curr_index < size) {
			int left_child = { 2 * curr_index + 1 };
			int right_child = { left_child + 1 };
			if (left_child >= size) return;
			int max_child{ left_child };
			if (right_child < size && heap[left_child] < heap[right_child])
				max_child = right_child;
			if (heap[max_child] > heap[curr_index]) swap(heap[max_child], heap[curr_index]);
			else return;
			curr_index = max_child;
		}
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		PQ H;
		bool X[101] = { 0, };
		int key[101] = { 0, }, path_distance[101] = { 0, };
		vector<P> edge[101];

		int N, E, S, K, d[100], a, b, c;
		cin >> N >> E >> S >> K;
		for (int i = 0; i < K; i++)
			cin >> d[i];
		for (int i = 0; i < E; i++) {
			cin >> a >> b >> c;
			edge[a].push_back({ b,c });
		}

		for (int i = 0; i < N; i++) {
			path_distance[i] = INF;
			key[i] = (i == S) ? 0 : INF;
			H.add({ key[i],i });
		}
		while (!H.is_empty()) {
			int w = H.get_min();
			X[w] = true;
			path_distance[w] = key[w];
			//H.print();
			/*for (int i = 0; i < N; i++)
				cout << key[i] << " ";
			cout << endl;*/
			//H.print();
			H.pop();
			for(int i = 0; i<edge[w].size(); i++) {
				int next_node = edge[w][i].first;
				if (!X[next_node]) {
					H.change_priority(0, {key[next_node],next_node});
					H.pop();
					key[next_node] = min(key[next_node], path_distance[w] + edge[w][i].second);
					H.add({ key[next_node], next_node });
				}
			}
		}
		for (int i = 0; i < K; i++) {
			if (path_distance[d[i]] < INF-100)
				cout << path_distance[d[i]]-1 << " ";
			else
				cout << -1 << " ";
		}
		cout << endl;
	}
}
