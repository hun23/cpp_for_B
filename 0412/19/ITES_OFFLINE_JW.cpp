#include <iostream>
#include <vector>
using namespace std;

int optimized(const vector<int>& signals, int k)
{
  int ret = 0, tail = 0, rangeSum = signals[0];
  for(int head = 0; head < signals.size(); ++head)
  {
    while(rangeSum < k && tail + 1 < signals.size())
      rangeSum += signals[++tail];
    if (rangeSum == k) ret++;
    rangeSum -= signals[head];
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
    vector<int> signals(N);
    // linear congruential generator (LCG) algorithm
    cout << optimized(signals, K) << endl;
  }
  return 0;
}