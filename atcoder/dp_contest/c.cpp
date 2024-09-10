#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;

  vector<int> dp(n, 0);
  for (int i = 0; i < n; i++) {
    vector<int> new_dp(n, 0);
    vector<int> c(3);

    for (int i = 0; i < 3; i++) {
      cin >> c[i];
    }

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i != j) {
          new_dp[j] = max(new_dp[j], dp[i] + c[j]);
        }
      }
    }
    dp = new_dp;
  }
  cout << max({dp[0], dp[1], dp[2]}) << endl;
}
