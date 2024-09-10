#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  vector<int> pos(1e9 + 1, 0);
  set<int> ans;

  int l, r;
  for (int i = 0; i < n; i++) {
    cin >> l >> r;

    for (int j = l; j <= r; j++) {
      pos[j]++;
      ans.insert(pos[j]);
    }
  }

  cout << *ans.begin() << endl;
}
