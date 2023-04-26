
#include <iostream>
using namespace std;

int heap[100000];
int heap_size = 0;

void push(unsigned int Num) {
	int idx = ++heap_size;
	heap[idx] = Num;
	while((idx != 1) && (Num < heap[idx / 2])) {
		int temp = heap[idx / 2];
		heap[idx / 2] = heap[idx];
		heap[idx] = temp;
		idx = idx / 2;
	}
}

int pop() {
	unsigned int minnimum = heap[1];
	if (heap_size <= 1) {
		heap_size = 0;
		heap[1] = 0;
		return minnimum;
	}
	heap[1] = heap[heap_size--];
	int parent_idx = 1;
	while (parent_idx*2 <= heap_size) {
		int left_idx = parent_idx * 2;
		if (left_idx + 1 <= heap_size && heap[left_idx] > heap[left_idx + 1]) {
			left_idx++;
		}
		if (heap[left_idx] < heap[parent_idx]) {
			unsigned int temp = heap[left_idx];
			heap[left_idx] = heap[parent_idx];
			heap[parent_idx] = temp;
			parent_idx = left_idx;
		}
		else {
			break;
		}
	}
	return minnimum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		unsigned int k;
		cin >> k;
		if (k) {
			push(k);
		}
		else { cout << pop() << '\n'; }
	}
}

