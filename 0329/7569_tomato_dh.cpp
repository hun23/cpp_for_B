#include <iostream>
#include <stdlib.h>
#include <queue>

int delta[6][3] = {
  {0, 0, 1}, {0, 0, -1},
  {0, 1, 0}, {0, -1, 0},
  {1, 0, 0}, {-1, 0, 0}
};

int main(void)
{
  int inputs[3]; // get M, N ,H
  for (int i=0; i<3; i++) {
    std::cin >> inputs[i];
  }
  int M, N, H;
  M = inputs[0];
  N = inputs[1];
  H = inputs[2];
  
  // get arr
  std::queue<int> queue;
  int ***arr;
  arr = (int ***)malloc(sizeof(int**) * H);
  for (int h=0; h<H; h++) {
    arr[h] = (int **)malloc(sizeof(int*) * N);
    for (int n=0; n<N; n++) {
      arr[h][n] = (int *)malloc(sizeof(int) * M);
      for (int m=0; m<M; m++) {
        int num;
        std::cin >> num;
        arr[h][n][m] = num;
        // push coordinates to queue if 1
        if (num == 1) {
          queue.push(m);
          queue.push(n);
          queue.push(h);
        }
      }
    }
  }

  // BFS
  while (!queue.empty()) {
    int cur[3];  // m, n, h
    for (int i=0; i<3; i++) {
      cur[i] = queue.front();
      queue.pop();
    }

    // check 6 directions
    for (int d=0; d<6; d++) {
      int next[3];
      bool go = true;
      for (int i=0; i<3; i++) {
        next[i] = cur[i] + delta[d][i];
        // check if next in index range
        if (next[i] < 0 || inputs[i] <= next[i]) go = false;
      }
      if (!go) continue;  // if index is out of range

      int nh, nn, nm;
      nm = next[0];
      nn = next[1];
      nh = next[2];
      // check visited
      if (arr[nh][nn][nm] == 0) {
        arr[nh][nn][nm] = arr[cur[2]][cur[1]][cur[0]] + 1;
        for (int i=0; i<3; i++) {
            queue.push(next[i]);
        }
      }
    }
  }

  int max = 0;
  for (int h=0; h<H; h++) {
    for (int n=0; n<N; n++) {
      for (int m=0; m<M; m++) {
        if (arr[h][n][m] > max) max = arr[h][n][m];
        if (arr[h][n][m] == 0) {
            std::cout << -1;
            exit(0);
        }
      }
    }
  }
  max -= 1;
  // print answer
  std::cout << max;

  // print queue
  // std::cout << '\n';
  // while (!queue.empty()) {
  //     for (int i=0; i<3; i++) {
  //         std::cout << queue.back();
  //         queue.pop();
  //     }
  // }

  // print arr
  // std::cout << '\n';
  // for (int h=0; h<H; h++) {
  //     for (int n=0; n<N; n++) {
  //         for (int m=0; m<M; m++) {
  //             std::cout << arr[h][n][m];
  //         }
  //         std::cout << '\n';
  //     }
  // }
}