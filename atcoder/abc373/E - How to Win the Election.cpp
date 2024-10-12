#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<pair<int, int>> vt;
  int cont = 0;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    vt.push_back({a, i});
    cont += a;
  }

  vector<pair<int, int>> sortado = vt;

  sort(sortado.begin(), sortado.end());

  for (auto v : sortado) {
    cout << v.first << " ";
  }
  cout << endl;
  cout << cont << endl;

  int troca = n - m;
  if (troca < n - 1)
    troca++;

  map<int, int> res;

  for (int i = 0; i < n; i++) {

    if (sortado[i].first > sortado[troca].first) {
      res[sortado[i].second] = 0;

    } else if (sortado[troca].first - sortado[i].first <= k - cont) {
      // cont - k, sortado[troca] - sortado[i] +1
      res[sortado[i].second] =
          min(k - cont, sortado[troca].first - sortado[i].first);
    } else {
      res[sortado[i].second] = -1;
    }
  }

  for (auto v : res) {
    cout << v.second << " ";
  }
  cout << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
