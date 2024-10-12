#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long a, b, m;
  cin >> a >> b >> m;

  cout << (m / a) + (m / b) + 2 << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
