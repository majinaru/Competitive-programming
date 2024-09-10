#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> ant(3, 0);
  vector<int> atu(3, 0);
  vector<int> c(3, 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> c[j];
    }

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i != j) {
          atu[j] = max(atu[j], ant[i] + c[j]);
        }
      }
    }
    ant = atu;
  }

  cout << max({ant[0], ant[1], ant[2]}) << endl;
}
