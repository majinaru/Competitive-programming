#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(m);
  set<pair<int, string>> c;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    c.insert({a[i], "a"});
  }

  for (int i = 0; i < m; i++) {
    cin >> b[i];
    if (c.find({b[i], "a"}) == c.end()) {
      c.insert({b[i], "b"});
    }
  }

  int cont = 0;
  for (auto t : c) {
    if (t.second == "a")
      cont++;
    else
      cont = 0;
    if (cont > 1) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}
