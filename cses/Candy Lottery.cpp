#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll

void solve() {
  double n, k;
  cin >> n >> k;

  double sum = 0;
  double f = (double)1 / k;
  for (int x = 1; x <= k; x++) {
    double e = (double)(x - 1) / (double)k;
    sum += x * (f - pow(e, n ));
  }

  printf("%.6f", sum);
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
