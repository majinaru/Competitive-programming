#include <bits/stdc++.h>
using namespace std;
const int maxd = 1000000009;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;

  vector<int> vt(n, maxd);
  set<int> qtdc;

  for (int i = 0; i < n; i++) {
    int a, c;
    cin >> a >> c;

    vt[c] = min(vt[c], a);
    qtdc.insert(c);
  }

  int maximo = -1;
  for (auto c : qtdc) {
    maximo = max(maximo, vt[c]);
  }

  cout << maximo << endl;
}
