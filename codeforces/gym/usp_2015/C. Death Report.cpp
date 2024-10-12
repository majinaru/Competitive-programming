#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  string n;
  cin >> n;

  int num = 0;
  int dez = 1;
  for (int i = n.size() - 1; i >= 0; i--) {
    if (n[i] == '.')
      continue;

    num += (n[i] - '0') * dez;
    dez *= 10;
  }
  cout << num << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
