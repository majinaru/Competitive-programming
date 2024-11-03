#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define endl "\n"
vector<int> vt;
vector<int> pref;
vector<int> posicoes;
vector<int> b;
vector<int> prefB;
vector<int> prefP;

int F(int t) {
  int pos = lower_bound(posicoes.begin(), posicoes.end(), t) - posicoes.begin();

  if (posicoes[pos] == t)
    return prefB[pos];

  int x;
  x = t - posicoes[pos - 1] + (pos - 1);

  // está errado
  return prefB[pos - 1] + pref[x] - pref[pos - 1];
}

void solve() {
  int n;
  cin >> n;

  vt.clear();
  pref.clear();
  posicoes.clear();
  b.clear();
  prefB.clear();
  prefP.clear();

  vt.resize(n + 1);
  pref.resize(n + 1);
  posicoes.resize(n + 1);
  b.resize(n + 1);
  prefB.resize(n + 1);
  prefP.resize(n + 1);

  int sum = 0;

  for (int i = 1; i <= n; i++) {
    cin >> vt[i];

    if (i != 1) {
      pref[i] = pref[i - 1] + vt[i];
    } else {
      pref[i] = vt[i];
    }

    prefP[i] = pref[i] + prefP[i - 1];
    sum += pref[i];
  }

  b[1] = sum;
  prefB[1] = b[1];
  for (int i = 1; i <= n; i++) {
    posicoes[i] = n - (i - 1) + posicoes[i - 1];
    if (i != 1) {
      b[i] = b[i - 1] - vt[i - 1] * (n - (i - 2));
      prefB[i] = b[i] + prefB[i - 1];
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;

    if (l == 1) {
      cout << F(r) << endl;
    } else {
      cout << F(r) - F(l - 1) << endl;
    }
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
