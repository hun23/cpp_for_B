#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

struct Node {
	int idx;
	int weight;
	Node(int i, int w) : idx(i), weight(w) {}
};

int N;
int BIG = INT_MAX;
unordered_map<int, vector<Node>> graph;

void make_graph(int a, int b, int c) {
	if (graph.find(a) == graph.end()) {
		vector<Node> temp;
		temp.push_back(Node(b, c));
		graph.insert(make_pair(a, temp));
	}
	else {
		graph[a].push_back(Node(b, c));
	}
}

struct cmp {
	bool operator()(Node a, Node b) {
		if (a.weight > b.weight) {
			return true;
		}
		return false;
	}
};

void find_path(int start, int *arr) {
	// 최단거리 저장 배열 만들기
	for (int i = 0; i < 801; i++) {
		arr[i] = BIG;
	}

	// 우선순위 큐 만들기
	priority_queue<Node, vector<Node>, cmp> priorityQueue;
	// 시작 노드에 0 넣기
	priorityQueue.push(Node(start, 0));
	arr[start] = 0;
	while (!priorityQueue.empty()) {
		// 우선순위 큐에서 가장 작은 값 꺼내기
		Node curr = priorityQueue.top();
		priorityQueue.pop();
		// 최단거리가 이미 갱신된 경우 무시
		if (curr.weight > arr[curr.idx]) {
			continue;
		}
		// 연결된 노드 파악하기
		vector<Node> connected = graph[curr.idx];
		// 순회하며 최소 거리 갱신
		for (auto itr : connected) {
			int new_weight = itr.weight + curr.weight;
			if (arr[itr.idx] > new_weight) {
				arr[itr.idx] = new_weight;
				priorityQueue.push(Node(itr.idx, new_weight));
			}
		}
	}
}


int main(void) {
	cin >> N;
	int E;
	cin >> E;
	
	int a, b, c;
	for (int e = 0; e < E; e++) {
		cin >> a >> b >> c;
		// 해쉬맵 + 벡터로 그래프 나타내기
		make_graph(a, b, c);
		make_graph(b, a, c);
	}
	int U, V;
	cin >> U >> V;

	// 다익스트라 여러번? 
	// 1 -> U -> V -> N
	// 1 -> V -> U -> N

	int start_1[801];
	find_path(1, start_1);
	int start_u[801];
	find_path(U, start_u);
	int start_v[801];
	find_path(V, start_v);

	int u1, v1, uv, vn, un;
	u1 = start_1[U];
	v1 = start_1[V];
	uv = start_u[V];
	un = start_u[N];
	vn = start_v[N];

	int answer = -1;
	if (uv == BIG) { // 불가능한 경우
		cout << answer;
		return 0;
	}
	if (u1 != BIG && vn != BIG) {
		answer = u1 + uv + vn;
	}
	if (v1 != BIG && un != BIG) {
		int temp = v1 + uv + un;
		if (answer > temp) {
			answer = temp;
		}
	}
	cout << answer;
	return 0;
	//for (const auto& itr : graph) {
	//	for (const auto& itr2 : itr.second) {
	//		cout << itr.first << ' ' << itr2.idx << ' ' << itr2.weight << '\n';
	//	}
	//}
}
