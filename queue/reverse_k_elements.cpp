#include <bits/stdc++.h>
#include "MYSTACK.h"
#include "MYQUEUE.h"
using namespace std;

void reverse_kth_element(int n, int k, Queue<int> q)
{
  int x = n / k;
  int y = n % k;
  Stack<int> st;

  while (x--)
  {
    while (k--)
    {
      st.push(q.pop());
    }
    while (!st.Empty())
    {
      q.push(st.pop());
    }
  }

  while (y--)
  {
    q.push(q.pop());
  }

  while (!q.Empty())
  {
    cout << q.pop() << " ";
  }
}

int main()
{
  int n, k;
  cin >> n >> k;
  Queue<int> q;
  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    q.push(val);
  }

  reverse_kth_element(n, k, q);

  return 0;
}