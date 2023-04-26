#include <iostream>
#include <queue>

using namespace std;

priority_queue <int, vector <int>, greater<int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num != 0) q.push(num);
		else {
			if (q.empty()) cout << 0 << '\n'; // endl로 자료 flush 하는 경우 시간초과 발생
			else {
				cout << q.top() << '\n';
				q.pop();
			}
		}
	}
	return 0;
}

/*
#include <iostream>

using namespace std;
#define MAX 0xfff0000

void swap(int* lst, int idx) {
	int tmp = lst[idx / 2];
	lst[idx / 2] = lst[idx];
	lst[idx] = tmp;
}

void push(int* hp, int& hn, int inp) {
	hp[++hn] = inp;
	for (int i = hn; i > 1; i /= 2) {
		if (hp[i / 2] < hp[i]) return;
		swap(hp, i);
	}
}

void pop(int* hp, int& hn) {
	int rst = 0;
	if (hn) {
		rst = hp[1];
		hp[1] = hp[hn];
		hp[hn--] = MAX;
		for (int i = 1; i < hn;) {
			if (hp[i] < hp[2 * i] && hp[i] < hp[2 * i + 1]) break;
			else if (hp[2 * i] < hp[2 * i + 1]) {
				swap(hp, 2 * i);
				i *= 2;
			}
			else {
				swap(hp, 2 * i + 1);
				i = 2 * i + 1;
			}
		}
	}
	cout << rst << '\n';
}

int n;
int input;
int heap[100000] = {MAX};
int heap_idx;

int main() {
	cin >> n;
	while (n--) {
		cin >> input;
		if (input) push(heap, heap_idx, input);
		else pop(heap, heap_idx);
	}
	return 0;
}
*/