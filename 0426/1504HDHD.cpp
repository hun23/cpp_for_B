#include <vector>
#include <queue>
#include <iostream>
#define N_Max 801
#define INF 1e8

using namespace std;

vector<pair<int, int>> graph[N_Max];


int dijkstra(int start, int N, int destination) {
	if (start == destination) {
		return 0;
	}
	vector<int> dist(N + 1);

	for (int i = 0; i <= N; i++) {
		dist[i] = INF;
	}
	priority_queue<pair<int, int>> pq; // (거리, 노드)

	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int nowdist = -pq.top().first;
		int nownode = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[nownode].size(); i++) {
			int nxtnode = graph[nownode][i].first;
			int nxtdist = nowdist + graph[nownode][i].second;
			if (nxtdist < dist[nxtnode]) {
				dist[nxtnode] = nxtdist;
				pq.push({ -nxtdist,nxtnode });
			}
		}
	}
	return dist[destination];
}




int main()
{
	int N, E, a, b, c, x, y;
	cin >> N >> E;

	for (int i = 1; i <= N; i++) {
		graph[i].clear();
	}


	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	cin >> x >> y;


	priority_queue<int> ans;
	ans.push(-dijkstra(1, N, x) - dijkstra(x, N, y) - dijkstra(y, N, N));
	ans.push(-dijkstra(1, N, y) - dijkstra(y, N, x) - dijkstra(x, N, N));
	int result = -ans.top();
	if (result < INF) {
		cout << result << endl;
	}
	else { cout << -1 << endl; }

	return 0;
}