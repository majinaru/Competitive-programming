#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int n, c;
  cin >> n >> c;
  vector<int> vt(n);
  vector<int> pref(n);
  map<int, vector<int>> freq;
  for (int i = 0; i < n; i++) {
    cin >> vt[i];

    if (vt[i] == c) {
      pref[i] = 1;
    }
    if (i > 0)
      pref[i] += pref[i - 1];

    freq[vt[i]].push_back(i);
  }
  int qtdc = pref[n - 1];
  int maxn = 0;

  for (auto v : freq) {
    int m = qtdc;
    if (v.first != c)
      m++;
    int l = 0;

    vector<int> a = v.second; // posicoes de vti

    for (int r = 0; r < a.size(); r++) {
      l = max(l, (a[r] ? pref[a[r] - 1] : 0) - r);
      m = max(m, r + 1 + qtdc - pref[a[r]] + l);
    }

    maxn = max(m, maxn);
  }
  cout << maxn << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
