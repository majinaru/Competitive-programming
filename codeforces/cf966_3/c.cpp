#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> vt(n);
  bool cond = true;

  for (int i = 0; i < n; i++) {
    cin >> vt[i];
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    map<char, int> mp;
    map<int, char> mp2;
    cond = true;

    if (s.size() != vt.size())
      cond = false;

    for (int i = 0; i < s.size(); i++) {
      if (mp.find(s[i]) != mp.end() && (mp.find(s[i])->second != vt[i])) {
        cond = false;
      }
      mp.insert({s[i], vt[i]});

      if (mp2.find(vt[i]) != mp2.end() && (mp2.find(vt[i])->second != s[i])) {
        cond = false;
      }
      mp2.insert({vt[i], s[i]});
    }

    cout << ((cond) ? "YES" : "NO") << endl;
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
