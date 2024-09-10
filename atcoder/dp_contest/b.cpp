#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000009;

int main() {
  long long n, k;
  cin >> n >> k;
  vector<long long> h(n);
  for (long long i = 0; i < n; i++) {
    cin >> h[i];
  }
  vector<long long> dp(n, INF);

  dp[0] = 0;

  for (long long i = 0; i < n; i++) {
    for (long long j = 1; j <= k; j++) {
      if (i + j < n) {
        dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
      }
    }
  }

  cout << dp[n - 1] << endl;
}
