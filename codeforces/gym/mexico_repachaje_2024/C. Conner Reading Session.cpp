#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> pages(n);

  for (int i = 0; i < n; i++) {
    cin >> pages[i];
  }

  vector<int> pleasure(n), fame(n);
  for (int i = 0; i < n; i++) {
    cin >> pleasure[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> fame[i];
  }

  vector<vector<int>> dp1(n, vector<int>(781)), dp2(n, vector<int>(781));

  int W = 780;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= W; j++) {
      int w = pages[i] * 3;

      // dp1
      if (i == 0) {
        dp1[i][j] = (j >= w ? pleasure[i] : 0);
      } else {
        dp1[i][j] = dp1[i - 1][j];

        if (j >= w) {
          dp1[i][j] = max(dp1[i][j], dp1[i - 1][j - w] + pleasure[i]);
        }
      }

      // dp2
      if (i == 0) {
        dp2[i][j] = (j >= w ? fame[i] : 0);
      } else {
        dp2[i][j] = dp2[i - 1][j];
        if (j >= w) {
          dp2[i][j] = max(dp2[i][j], dp2[i - 1][j - w] + fame[i]);
        }
      }
    }
  }

  int p = dp1[n - 1][W];
  int f = dp2[n - 1][W];

  if (p == f) {
    cout << "EITHER" << endl;
  } else if (p > f) {
    cout << "PLEASURE" << endl;
  } else {
    cout << "FAME" << endl;
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
