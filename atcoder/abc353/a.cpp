#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> vt(n);
  bool cond = true;

  for (int i = 0; i < n; i++) {
    cin >> vt[i];

    if (vt[i] > vt[0] && cond) {
      cout << i + 1 << endl;
      cond = false;
    }
  }

  if (cond) {
    cout << -1 << endl;
  }
}
