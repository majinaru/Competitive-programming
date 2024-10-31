#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll

vector<int> t;

void build(int a[], int v, int tl, int tr) {
  if (tl == tr)
    t[v] = a[tl];
  else {
    int tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);
    t[v] = t[v * 2] + t[v * 2 + 1];
  }
}

int sum(int v, int tl, int tr, int l, int r) {
  if (l > r)
    return 0;
  if (tl == l && tr == r) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  return sum(v * 2, tl, tm, l, min(r, tm)) +
         sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
  if (tl == tr)
    t[v] = new_val;
  else {
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
      update(v * 2, tl, tm, pos, new_val);
    } else {
      update(v * 2 + 1, tm + 1, tr, pos, new_val);
    }
    t[v] = t[v * 2] + t[v * 2 + 1];
  }
}

void solve() {
  int n, q;
  cin >> n >> q;
  int vt[n];
  t.resize(4 * n + 1);
  for (int i = 0; i < n; i++) {
    cin >> vt[i];
  }

  build(vt, 1, 0, n - 1);
  while (q--) {
    int num;
    cin >> num;

    if (num == 1) {
      int k, u;
      cin >> k >> u;

      update(1, 0, n - 1, k - 1, u);
    } else {
      int a, b;
      cin >> a >> b;

      cout << sum(1, 0, n - 1, a - 1, b - 1) << endl;
    }
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
