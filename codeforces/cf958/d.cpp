#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  int sum = 0;
  int dano = 0;
  vector<int> monstros(n);
  vector<vector<int>> graph(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    cin >> monstros[i];
    sum += monstros[i];
  }

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 0; i < 1000; i++) {
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
