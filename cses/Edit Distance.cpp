#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int ll
using ll = long long;
const int INF = 1e18 + 5;

void solve() {
  string s1, s2;
  cin >> s1 >> s2;

  int n = s1.size();
  int m = s2.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));

  for (int i = 0; i <= n; i++) {
    dp[i][0] = i;
  }
  for (int i = 0; i <= m; i++) {
    dp[0][i] = i;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] =
            min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
      }
    }
  }
  cout << dp[n][m] << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
