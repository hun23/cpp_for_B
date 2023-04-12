#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// random number generator
struct RNG {
  unsigned seed;
  RNG(): seed(1983) {}
  unsigned next() {
    unsigned ret = seed;
    seed = ((seed* 214013u) + 2531011u);
    return ret%10000 + 1;
  }
};

int countRanges(int k, int n) {
  RNG rng;
  queue<int> range;
  int ret = 0, rangeSum = 0;
  for(int i = 0; i < n; i++)
  {
    int newSignal = rng.next();
    rangeSum += newSignal;
    range.push(newSignal);

    while (rangeSum > k)
    {
      rangeSum -= range.front();
      range.pop();
    }
    
    if (rangeSum == k) ret++;
  }
  return ret;
}

int main(void)
{
  int T = 0;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc)
  {
    int K, N;
    cin >> K >> N;
    cout << countRanges(K, N) << endl;
  }
  return 0;
}