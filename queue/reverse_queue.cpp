#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int n;
  cin >> n;
  queue<int> q;
  stack<int> st;
  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    q.push(val);
  }

  while (n--)
  {
    st.push(q.front());
    q.pop();
  }
  while (!st.empty())
  {
    q.push(st.top());
    st.pop();
  }

  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }

  return 0;
}
