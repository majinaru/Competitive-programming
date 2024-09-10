#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
  int n;
  cin >> n;

  vector<int> vt(n);

  for (int i = 0; i < n; i++) {
    cin >> vt[i];
  }

  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  int index;
  if (n % 2 == 0) {
    index = n / 2 - 1;
  } else {
    index = n / 2;
  }

  sort(vt.begin(), vt.end());

  int cont = 0;
  int i = index;
  while (vt[i] == vt[i + 1] && i + 1 < n) {
    cont++;
    i++;
  }

  cout << cont + 1 << endl;
  return;
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
