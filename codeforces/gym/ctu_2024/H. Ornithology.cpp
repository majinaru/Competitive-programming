#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll
vector<int> t;

int sum(int v, int l, int r, int L, int R) {
  // retorna a soma dos elementos maiores que a posição q quero ir
  if (l > R or r < L)
    return 0;
  if (l >= L && r <= R) {
    return t[v];
  }
  int tm = (l + r) / 2;
  return sum(v * 2, l, tm, L, R) + sum(v * 2 + 1, tm + 1, r, L, R);
}

void update(int v, int l, int r, int pos, int new_val) {
  if (l == r) {
    t[v] = new_val;
  } else {
    int tm = (l + r) / 2;
    if (pos <= tm) {
      update(v * 2, l, tm, pos, new_val);
    } else {
      update(v * 2 + 1, tm + 1, r, pos, new_val);
    }
    t[v] = t[v * 2] + t[v * 2 + 1];
  }
}

void solve() {
  int n;
  cin >> n;

  t.resize(4 * (n + 1));

  vector<int> vetor(4 * (n + 1));
  int res = 0;

  for (int orig = 0; orig < n; orig++) {
    int qtd;
    cin >> qtd;

    vector<int> destinos;
    while (qtd--) {
      int dest;
      cin >> dest;

      destinos.push_back(dest);

      if (orig != 0) {
        res += sum(1, 0, n, dest + 1, n);
      }
    }

    for (auto dest : destinos) {
      vetor[dest]++;
      update(1, 0, n, dest, vetor[dest]);
    }
    destinos.clear();
  }

  cout << res << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
