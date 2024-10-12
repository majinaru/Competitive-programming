#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll
const int MOD = 1e9 + 7;

int mull(int a, int b) { return (a * b) % MOD; }

int potB(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = mull(res, a);
    }
    a = mull(a, a);
    b /= 2;
  }
  return res;
}

void solve() {
  int n;
  cin >> n;

  int sum = 0;

  for (int i = 1; i * i <= n; i++) {
    sum = (mull(n / i, i) + sum) % MOD;

    int dir = n / i;
    int esq = n / (i + 1) + 1;

    if (i == esq)
      continue;

    dir = dir % MOD;
    esq = esq % MOD;
    // gauss completa
    int gauss = mull((dir + esq) % MOD,
                     (dir - esq + 1) + MOD) %
                MOD;                       // numerador (a1 + an ) * n
    gauss = mull(gauss, potB(2, MOD - 2)); // divisao por 2 modular

    gauss = mull(gauss, i);
    sum = (sum + gauss) % MOD;
  }
  cout << sum << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
