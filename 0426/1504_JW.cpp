#include <iostream>
#define INF 10000000
using namespace std;

typedef struct st
{
	int distance;
	int node;
}HEAP;

void swap(HEAP* a, HEAP* b);
bool priority(HEAP* a, HEAP* b);
void push(int n, int d);
int pop();
int Dijkstra(int start, int end);

int hn = 0;
HEAP heap[10000] = {};
int N, E;
int v1, v2;
int arr[1001][1001];
int dist[1001];

int main() {
	cin >> N >> E;
	int n1 = 0;
	int n2 = 0;
	int c = 0;
	for (int i = 0; i < E; i++) {
		cin >> n1 >> n2 >> c;
		arr[n1][n2] = c;
		arr[n2][n1] = c;
	}
	cin >> v1 >> v2;
	int sum1 = Dijkstra(1, v1) + Dijkstra(v1, v2) + Dijkstra(v2, N);
	int sum2 = Dijkstra(1, v2) + Dijkstra(v2, v1) + Dijkstra(v1, N);
	int result = (sum1 < sum2) ? sum1 : sum2;
	if (result >= INF) printf("%d", result);
	else printf("0");
	return 0;
}

void swap(HEAP* a, HEAP* b) {
	HEAP tmp = *a;
	*a = *b;
	*b = tmp;
}

bool priority(HEAP* a, HEAP* b) {
	if (a->distance < b->distance) return true;
	if (a->distance == b->distance && a->node < b->node) return true;
	return false;
}

void push(int n, int d) {
	heap[++hn].node = n;
	heap[hn].distance = d;
	for (int i = hn; i > 1; i /= 2) {
		if (priority(&heap[i / 2], &heap[i])) swap(&heap[i / 2], &heap[i]);
		else break;
	}
}

int pop() {
	if (hn == 0) {
		return 0;
	}
	HEAP ret = heap[1];
	heap[1] = heap[hn];
	heap[hn].distance = INF;
	heap[hn--].node = -1;
	for (int i = 1; i * 2 < hn;) {
		if (priority(&heap[i], &heap[2 * i]) && priority(&heap[i], &heap[2 * i + 1])) break;
		else if (priority(&heap[2 * i], &heap[2 * i + 1])) {
			swap(&heap[i], &heap[2 * i]);
			i = 2 * i;
		}
		else {
			swap(&heap[i], &heap[2 * i + 1]);
			i = 2 * i + 1;
		}
	}
	return ret.node;
}

int Dijkstra(int start, int end) {
	if (start == end) return 0;
	for (int i = 1; i <= N; i++) dist[i] = INF;
	hn = 0;
	push(start, 0);
	dist[start] = 0;
	while (hn) {
		int node = pop();
		for (int i = 1; i <= N; i++) {
			if (dist[i] > dist[node] + arr[node][start]) {
				dist[i] = dist[node] + arr[node][start];
				push(-dist[i], i);
			}
		}
	}
}