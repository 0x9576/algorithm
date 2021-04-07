#define INF 9999999
#include<iostream>
#include<queue>
using namespace std;

class PQ {
	class HeapIterator : public iterator<input_iterator_tag, int> {
		int* p;
	public:
		explicit HeapIterator(int *p): p{p}{}
		const HeapIterator& operator++() { ++p; return *this; }
		HeapIterator operator++(int) { HeapIterator retval = *this; ++p; return retval;}
		bool operator==(const HeapIterator& other) const {return p == other.p;}
		bool operator!= (const HeapIterator& other) const { return !(*this == other); }
		int operator*() const { return *p; }
	};
private:
	unsigned int capacity;
	unsigned int size{ 0 };
	int* heap{ nullptr };
	bool need_more_space() const {
		return size == capacity;
	}
	void increase_capacity() {
		capacity = capacity * 2 + 1;
		int *tmp{ new int [capacity] };
		copy(heap, heap + size, tmp);
		delete [] heap;
		heap = tmp;
	}
public:
	PQ() : capacity {15}, heap{new int [capacity]}{}
	PQ(initializer_list<int> init_list) : PQ{} {
		for (auto n : init_list) add(n);
	}
	virtual ~PQ() {
		if (heap) delete[] heap;
	}
	PQ(const PQ& other) : capacity{ other.capacity }, heap{ new int[capacity] }, size(other.size){
		copy(other.heap, other.heap + size, heap);
	}
	PQ(PQ&& tmp) : capacity{ tmp.capacity }, heap{ tmp.heap }, size{ tmp.size }{
		tmp.heap = nullptr;
	}
	const PQ& operator=( const PQ & other ) {
		capacity = other.capacity;
		size = other.size;
		if (heap) delete[] heap;
		heap = new int[capacity];
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
	void add(int key) noexcept {
		if (need_more_space()) increase_capacity();
		heap[size] = key;
		reheap_up(size);
		++size;
	}
	int get_max() const {
		return heap[0];
	}
	int extrat_max() {
		int retval{ heap[0] };
		swap(heap[0], heap[size - 1]);
		heap[0] = heap[size - 1];
		--size;
		reheap_down(0);
		return retval;
	}
	void change_priority(int index, int key) {
		if (heap[index] == key) return;
		int prev_key{ heap[index] };
		heap[index] = key;
		if (prev_key>key) reheap_down(index);
		else reheap_up(index);
	}
	void remove(int index) {
		if (index != size - 1) {
			change_priority(index, heap[size]);
		}
		--size;
	}
	HeapIterator begin() { return HeapIterator(heap); }
	HeapIterator end() { return HeapIterator(heap+size); }
private:
	void reheap_up(int index) {
		int curr_index{ index };
		while (curr_index>0){
			int parent_index{ (curr_index - 1)/2 };
			if(heap[parent_index] > heap[curr_index]) swap(heap[parent_index], heap[curr_index]);
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
		int key[101], path_distance[101];
		int edge[101][101] = { 0, };

		for (int i = 0; i < 101; i++)
			for (int j = 0; j < 101; j++) {
				if(i!=j)
					edge[i][j] = INF;
			}

		int N, E, S, K,d[100],a,b,c;
		cin >> N >> E >> S >> K;
		for (int i = 0; i < K; i++)
			cin >> d[i];
		for (int i = 0; i < S; i++) {
			cin >> a >> b >> c;
			edge[a][b] = c;
		}

		for (int i = 0; i < N; i++) {
			key[i] = (i == S) ? 0 : INF;
			H.push(i);
		}
		while (!H.empty()) {
			int w = H.top();
			X[w] = true;
			path_distance[w] = key[w];
			for (int i = 0; i < 101; i++) {
				if (!X[i] && edge[w][i] != INF) {
					H.pop();
				}
			}
		}
	}
}
