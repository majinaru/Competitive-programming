#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  int cont1 = 0;
  int cont0 = 0;
  vector<int> vt(n);
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> vt[i];
    if (vt[i] == 1) {
      cont1++;
    } else {
      cont0++;
    }
    if (i > 1 && vt[i] == 0 && vt[i - 1] == 0) {
      cont0--;
    }
  }

  cout << ((cont0 >= cont1) ? "No" : "Yes") << endl;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}
