#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }

  vector<int> dp(1 << n, -1);
  dp[0] = 0;

  for (int i = 1; i < (1 << n); i++) {
    bool f = false;
    for (int j = 0; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (((i >> j) & 1) && ((i >> k) & 1)) {
          if ((a[j] == a[k] || b[j] == b[k]) &&
              dp[i ^ (1 << j) ^ (1 << k)] == 0) {
            f = true;
          }
        }
      }
    }
    dp[i] = f;
  }

  cout << (dp.back() ? "Takahashi" : "Aoki") << endl;
}
