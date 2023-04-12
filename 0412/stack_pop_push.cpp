#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> h;

// stack solving base skeleton code
int solveStack(void)
{
  stack<int> remaining;
  h.push_back(0);
  int ret = 0;
  for(int i = 0; i<h.size(); ++i)
  {
    while(!remaining.empty() && h[remaining.top()] >= h[i])
    {
      int j = remaining.top();
      remaining.pop();
      int width = -1;
      if (remaining.empty())
        width = i;
      else
        width = (i - remaining.top() - 1);
      ret = max(ret, h[j]*width);
    }
    remaining.push(i);
  }
  return ret;
}

int main(void)
{
  return 0;
}