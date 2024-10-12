#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll
const int INF = 1e18 + 5;

void solve() {
  int n;
  cin >> n;

  vector<int> vt(n + 1);
  vt[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> vt[i];
  }

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
  dp[0][0] = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + abs(vt[i - 1] - vt[i]));

      dp[i][i - 1] = min(dp[i][i - 1], dp[i - 1][j] + abs(vt[i] - vt[j]));
    }
  }

  int res = INF;
  for (int i = 0; i <= n; i++) {
    res = min(res, dp[n][i]);
  }

  cout << res << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
