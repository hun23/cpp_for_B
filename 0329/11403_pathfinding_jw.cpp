#include <iostream>
using namespace std;

const int MAX = 100;

int graph[MAX][MAX];

int main() {
	int n;
	cin >> n;

	// Initialize the graph
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	// Floyd-Warshall algorithm
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (graph[i][k] && graph[k][j]) {
					graph[i][j] = 1;
				}
			}
		}
	}

	// Output the result
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
    
	return 0;
}
