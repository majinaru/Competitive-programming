#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> vt(n);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> vt[i];

    mp[vt[i]]++;
  }

  int idx = 0;
  int last = -3;
  int sumAtual = 0;
  vector<int> id;
  int maxn = 0;

  for (auto v : mp) {
    id.push_back(v.second);

    if (v.first == last + 1) {
      sumAtual += v.second;

      if (idx - k >= 0) {
        sumAtual -= id[idx - k];
      }

      maxn = max(maxn, sumAtual);
    } else {
      sumAtual = v.second;

      if (idx > 0) {
        id.clear();
        idx = 0;
        id.push_back(v.second);
      }

      maxn = max(maxn, sumAtual);
    }
    last = v.first;
    idx++;
  }

  cout << maxn << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
