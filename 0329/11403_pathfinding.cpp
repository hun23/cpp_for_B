#include <iostream>
#include <stack>

int main(void) {
  int N;
  std::cin >> N;

  // get adjL
  int adjList[100][100];
  int answer[100][100];
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      std::cin >> adjList[i][j];
    }
  }

  // solve
  std::stack<int> stack;
  int visited[100];
  for (int i=0; i<N; i++) {
    // check if i -> j is possible

    // initialize visited
    for (int k=0; k<100; k++) {
      visited[k] = 0;
    }
    // to check returning to start point is possible
    visited[i] = -1;
    
    // DFS
    stack.push(i);
    while (!stack.empty()) {
      int cur = stack.top();
      stack.pop();
      if (visited[cur] <= 0) {
        visited[cur] += 1;
        for (int k=0; k<N; k++) {
          if (adjList[cur][k] == 1) {
            stack.push(k);
          }
        }
      }
    }

    for (int k=0; k<N; k++) {
      if (visited[k] == 1) {
        answer[i][k] = 1;
      }
    }
  }

  // print
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      std::cout << answer[i][j];
      if (j != N) {
        std::cout << ' ';
      }
    }
    std::cout << "\n";
  }
}