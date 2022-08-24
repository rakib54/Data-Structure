#include <bits/stdc++.h>
using namespace std;

void reverse_each_word(string s)
{
  stack<char> st;
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] != '.') // dot separated word
    {
      st.push(s[i]);
    }
    else
    {
      while (!st.empty())
      {
        cout << st.top();
        st.pop();
      }
      cout << ".";
    }
  }

  while (!st.empty())
  {
    cout << st.top(); // remaining word
    st.pop();
  }
}
int main()
{
  string s;
  cin >> s;

  reverse_each_word(s);

  return 0;
}