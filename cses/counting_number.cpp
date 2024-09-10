#include <bits/stdc++.h>
using namespace std;

const int lim = 1000006;
vector<int> div_count(lim);

void preprossessing() {
  for (int i = 1; i <= lim; i++) {
    for (int j = i; j <= lim; j += i) {
      div_count[j] += 1;
    }
  }
}
void solve() {
  int x;
  cin >> x;

  cout << div_count[x] << endl;
}
int main() {
  preprossessing();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
