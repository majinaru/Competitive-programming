#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<string> vt(n);

  for (int i = 0; i < n; i++) {
    cin >> vt[i];
  }

  if (n == k) {
    cout << vt[0][0] << endl;
    return;
  }

  for (int i = 0; i < n; i += k) {
    for (int j = 0; j < n; j += k) {
      cout << vt[i][j];
    }
    cout << endl;
  }
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}
