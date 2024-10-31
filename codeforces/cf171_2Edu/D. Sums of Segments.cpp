#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll

int n;
vector<int> b;
vector<int> vt;
vector<int> prefB(n);
vector<int> posicoes(n);

int F(int x) {
  int p = lower_bound(posicoes.begin(), posicoes.end(), x) - posicoes.begin();

  cout << "p " << p << endl;
  if (posicoes[p] == x)
    return prefB[p];

  // calculo do restinho de p até x
  cout << "x: " << x << endl;
  cout << "pos " << p << endl;

  int ret = 0;
  x--;
  for (int i = x - p; i < n; i++) {
    ret += vt[i] * (n - i);
    cout << vt[i] << " ";
  }
  cout << endl;

  return prefB[p] - ret;
}

void solve() {
  cin >> n;
  vector<int> pref(n);
  b.resize(n + 1);
  vt.resize(n);
  prefB.resize(n + 1);
  posicoes.resize(n);
  int sum = 0;

  for (int i = 0; i < n; i++) {
    cin >> vt[i];

    if (i == 0) {
      pref[i] = vt[i];
    } else {
      pref[i] = pref[i - 1] + vt[i];
    }

    sum += pref[i];
  }

  b[0] = sum;
  prefB[0] = 0;
  posicoes[0] = n;
  for (int i = 1; i < n; i++) {
    b[i] = b[i - 1] - (vt[i - 1] * (n - (i - 1)));
    posicoes[i] = n - i + posicoes[i - 1];
    prefB[i] = b[i - 1] + prefB[i - 1];
  }

  prefB[n] = b[n - 1] + prefB[n - 1];

  // soma acumalada em b(1..n) construida

  int q;
  cin >> q;

  while (q--) {
    int l, r;
    cin >> l >> r;

    if (l == 1)
      cout << F(r) << endl;
    else
      cout << F(r) - F(l - 1) << endl;
  }
}

int32_t main() {
  /*cin.tie(0)->sync_with_stdio(0);*/
  solve();
}
