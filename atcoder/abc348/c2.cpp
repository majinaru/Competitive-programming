#include <bits/stdc++.h>
#include <queue>
using namespace std;
const int maxd = 1000000009;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;

  set<int> qtdc;
  vector<priority_queue<int>> vt(n);

  for (int i = 0; i < n; i++) {
    int a, c;
    cin >> a >> c;

    vt[c].push(a);
    qtdc.insert(c);
  }

  int maximo = -1;
  for (auto c : qtdc) {
    if (!vt[c].empty()) {
      maximo = max(maximo, vt[c].top());
    }
    cout << maximo << endl;
  }
}
