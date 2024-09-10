#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  int sum = n / 4;
  sum += n % 4 / 2;

  cout << sum << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
