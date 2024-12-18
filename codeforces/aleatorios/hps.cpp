#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);
  int n, k;
  cin >> n >> k;

  vector<char> vt(n);

  for (int i = 0; i < n; i++) {
    cin >> vt[i];
  }

  vector<vector<vector<int>>> dp(n,
                                 vector<vector<int>>(k + 1, vector<int>(3, 0)));

  dp[0][0][0] = (vt[0] == 'H');
  dp[0][0][1] = (vt[0] == 'S');
  dp[0][0][2] = (vt[0] == 'P');

  // 0- P 1- H 2-S
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int p = 0; p < 3; p++) {
        dp[i][j][p] = dp[i - 1][j][p] + ((vt[i] == 'H' && p == 0) ||
                                         (vt[i] == 'S' && p == 1) ||
                                         (vt[i] == 'P' && p == 2));
        if (j > 0) {
          dp[i][j][p] =
              max(dp[i - 1][j - 1][0] + (vt[i] == 'H' && p != 0), dp[i][j][p]);
          dp[i][j][p] =
              max(dp[i - 1][j - 1][1] + (vt[i] == 'S' && p != 1), dp[i][j][p]);
          dp[i][j][p] =
              max(dp[i - 1][j - 1][2] + (vt[i] == 'P' && p != 2), dp[i][j][p]);
        }
      }
    }
  }

  /*for (int i = 0; i < n; i++) {*/
  /*  for (int j = 0; j <= k; j++) {*/
  /*    for (int p = 0; p < 3; p++) {*/
  /*      cout << dp[i][j][p] << " ";*/
  /*    }*/
  /*  }*/
  /*  cout << endl;*/
  /*}*/

  int maxn = 0;
  for (int i = 0; i < 3; i++) {
    maxn = max(maxn, dp[n - 1][k][i]);
  }
  cout << maxn << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
