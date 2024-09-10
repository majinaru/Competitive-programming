#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  set<string> st;
  for (int i = 0; i < s.length(); i++) {
    for (int j = 0; j <= s.length() - i; j++) {
      st.insert(s.substr(i, j));
    }
  }

  cout << st.size() - 1 << endl;
}
