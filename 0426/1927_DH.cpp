#include <queue>
#include <stdio.h>

using namespace std;

int main(void) {
	int N;
	scanf_s("%d", &N); // 제출시 scanf로 바꿀 것
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int n = 0; n < N; n++) {
		int temp;
		scanf_s("%d", &temp); // 제출시 scanf로 바꿀 것
		if (temp > 0) {
			pq.push(temp);
		}
		else {
			if (!pq.empty()) {
				printf("%d\n", pq.top());
				pq.pop();
			}
			else {
				printf("0\n");
			}
		}
	}
	return 0;
}
