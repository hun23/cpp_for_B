#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool wellmatched(const string& formula)
{
  const string opening("({["), closing(")}]");
  stack<char> openStack;
  for(int i = 0; i < formula.size(); ++i)
  {
    if(opening.find(formula[i]) != -1)
      openStack.push(formula[i]);
    else
    {
      if(openStack.empty())
        return false;
      if(opening.find(openStack.top()) != closing.find(formula[i]))
        return false;    
      openStack.pop();
    }
  }
  
  return openStack.empty();
}

int main(void)
{
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc)
  {
    string input_string;
    cin >> input_string;
    string result = (wellmatched(input_string))? "YES":"NO";
    cout << result << endl;
  }
}