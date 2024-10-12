#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define endl '\n'
using ll = long long;
const int mod = 1e9 + 7;

void solve() {
  int n;
  cin >> n;

  vector<int> dp(n + 1);

  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    int cont = 1;
    while (i - cont >= 0 && cont <= 6) {
      dp[i] = (dp[i] % mod + dp[i - cont] % mod) % mod;
      cont++;
    }
  }

  cout << dp[n] << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
