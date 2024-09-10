#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  string s1, s2;
  cin >> s1 >> s2;

  int index = 0;
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] == s2[index]) {
      index++;
      continue;
    }

    if (index == s2.size() && s1[i] == '?') {
      s1[i] = 'a';
      continue;
    }

    if (s1[i] == '?') {
      s1[i] = s2[index];
      index++;
    }
  }

  if (index < s2.size()) {
    cout << "No" << endl;
    return;
  }

  cout << "Yes" << endl;
  cout << s1 << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}
