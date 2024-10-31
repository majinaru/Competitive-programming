#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int n;
vector<vector<int>> dp;
vector<int> vt;

void func(int i, bool f) {

  if (dp[i][f] != -1)
    return;

  dp[i][f] = vt[i];

  if (f == 1) {
    dp[i][f] = 0;
  }

  if (i + 1 >= n)
    return;

  if (i + 2 >= n) {
    func(i + 1, !f);
    return;
  } else {
    func(i + 1, !f);
    func(i + 2, !f);

    if (f == 0) // vez do amigo
      dp[i][f] += min(dp[i + 1][!f], dp[i + 2][!f] + vt[i + 1]);
    else // minha vez
      dp[i][f] += min(dp[i + 1][!f], dp[i + 2][!f]);
  }
}

void solve() {

  cin >> n;
  vt.clear();
  vt.resize(n + 1);
  dp.clear();
  dp.resize(n + 1, vector<int>(2, -1));

  for (int i = 0; i < n; i++) {
    cin >> vt[i];
  }

  func(0, 0);
  /*cout << endl;*/

  /*for (int i = 0; i < n; i++) {*/
  /*  for (int j = 0; j < 2; j++) {*/
  /*    cout << dp[i][j] << " ";*/
  /*  }*/
  /*  cout << endl;*/
  /*}*/
  /*cout << endl;*/
  cout << dp[0][0] << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
