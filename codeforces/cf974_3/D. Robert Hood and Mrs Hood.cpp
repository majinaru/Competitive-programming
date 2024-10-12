#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int n, d, k;
  cin >> n >> d >> k;

  vector<int> pref(n + 1);

  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;

    int init = max(a - d + 1, 1);
    pref[init]++;
    if (b + 1 <= n)
      pref[b + 1]--;
  }

  pair<int, int> maxn = {-1, 0};
  pair<int, int> minx = {1e9 + 10, 0};

  for (int i = 1; i <= n; i++)
    pref[i] += pref[i - 1];

  for (int i = 1; i <= n - d + 1; i++) {

    if (maxn.first < pref[i]) {
      maxn.first = pref[i];
      maxn.second = i;
    }
    if (minx.first > pref[i]) {
      minx.first = pref[i];
      minx.second = i;
    }
  }

  /*for (auto v : pref) {*/
  /*  cout << v << " ";*/
  /*}*/
  /*cout << endl;*/

  cout << maxn.second << " " << minx.second << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
