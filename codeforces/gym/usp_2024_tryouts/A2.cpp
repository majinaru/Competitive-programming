#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> vt(n);
  for (int i = 0; i < n; i++) {
    int init, fim, b;
    cin >> init >> fim >> b;

    vt[i] = {init, fim, b, i};
  }

  sort(vt.begin(), vt.end());

  stack<vector<int>> fila;

  fila.push(vt[0]);

  vector<int> res;

  for (int i = 1; i < n; i++) {
    auto top = fila.top();
    fila.pop();
    auto atual = vt[i];

    if (atual[0] < top[0] + top[1] && atual[2] == 0) {
      int aux = atual[0];
      atual[0] = top[1];
      fila.push(atual);
    } else if (atual[0] < top[0] + top[1] ||
               atual[1] < top[1] && atual[2] == 1) {
      res.push_back(atual[3]);
    }
    fila.push(atual);
  }

  cout << res.size() << endl;
  for (auto v : res) {
    cout << v << " ";
  }
  cout << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
