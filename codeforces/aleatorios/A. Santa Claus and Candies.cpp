#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
vector<int> dp;
vector<int> vt;
int n;

int func(int i) {
  if (i + vt[i] > n)
    return 0;

  if (dp[i + vt[i]] != -1) {
    return dp[i + vt[i]];
  }

  return dp[i] = i + dp[i + vt[i]];
}

void solve() {
  cin >> n;

  vt.clear();
  dp.clear();
  dp.resize(n, -1);
  vt.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> vt[i];
  }
  int maxn = 0;

  for (int i = 0; i < n; i++) {
    maxn = max(maxn, func(i));
  }
  cout << maxn << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
