#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;
const int MAXN = 1E9 + 5;
int n, t[4 * MAXN];

int build(int a[], int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tr];
  } else {
    int tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);
    t[v] = t[v * 2] + t[v * 2 + 1];
  }
}

int sum(int v, int tl, int tr, int l, int r) {
  if (l > r)
    return 0;
  if (l == tl && r == tr)
    return t[v];
  int tm = (tl + tr) / 2;
  return sum(v * 2, tl, tr, l, min(r, tr)) + sum(v * 2, tl, tr, max(l, tl), r);
}

int update(int v, int tl, int tr, int pos, int new_val) {
  if (tl == tr) {
    t[v] = new_val;
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(v * 2, tl, tm, pos, new_val);
    else
      update(v * 2 + 1, tm + 1, tr, pos, new_val);
    t[v] = t[v * 2] + t[v * 2 + 1];
  }
}

void solve() {}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
