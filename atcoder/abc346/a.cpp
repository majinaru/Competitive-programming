#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;

  vector<int> vt(n);
  for (int i = 0; i < n; i++) {
    cin >> vt[i];
  }

  for (int i = 0; i < n - 1; i++) {
    cout << vt[i] * vt[i + 1] << " ";
  }
  cout << endl;
}
