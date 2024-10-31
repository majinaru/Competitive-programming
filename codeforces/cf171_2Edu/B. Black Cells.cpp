#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;
#define int ll
const int INF = 1e18;

void solve(int c) {
  int n;
  cin >> n;
  vector<int> vt(n);
  int res = INF;

  for (int i = 0; i < n; i++) {
    cin >> vt[i];
  }

  auto find_res = [&]() {
    sort(vt.begin(), vt.end());
    int ans = 0;

    for (int i = 1; i < vt.size(); i += 2)
      if (vt[i - 1] == vt[i])
        return;

    for (int i = 0; i < vt.size(); i += 2) {
      int diff = vt[i + 1] - vt[i];
      ans = max(ans, diff);
    }
    res = min(ans, res);
  };

  if (n == 1) {
    cout << 1 << endl;
    return;
  }

  if (n % 2 == 0) {
    find_res();
  } else {
    for (int i = 0; i < n; i++) {
      for (auto x : {-1, 1}) {
        vt.push_back(vt[i] + x);
        find_res();
        vt.pop_back();
      }
    }
  }
  cout << res << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  int cont = 0;
  bool cond = false;
  if (t == 462) {
    cond = true;
  }
  while (t--) {
    if (cond) {
      cont++;
    }
    solve(cont);
  }
}
