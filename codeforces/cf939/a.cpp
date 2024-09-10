#include <bits/stdc++.h>
using namespace std;

int solve() {
  int k, q;
  cin >> k >> q;
  vector<int> a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < q; i++) {
    int qi;
    cin >> qi; // qi = 5 qi = 4

    bool cond = true;
    while (qi > 0 && cond) {
      cond = false;
      int qtd = 0;
      for (int j = 0; j < k; j++) {
        if (qi >= a[j]) {
          qtd++;
          cond = true;
        }
      }
      qi -= qtd;
    }
    cout << qi << " ";
  }
  cout << endl;

  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
