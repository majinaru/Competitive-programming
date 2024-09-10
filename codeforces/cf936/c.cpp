#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<bool> visited;
vector<vector<int>> graph;
vector<int> num_child;
int k;

int dfs(int i) {
  if (visited[i]) {
    return 0;
  }

  visited[i] = true;

  for (auto u : graph[i]) {
    if (!visited[u]) {

      int temp_child = 0;
      temp_child += dfs(u);

      if (temp_child >= 2 && k >= 0) {
        auto it = find(graph[i].begin(), graph[i].end(), u);
        graph[i].erase(it);
        it = find(graph[u].begin(), graph[u].end(), i);
        graph[u].erase(it);
        k--;
      } else {
        num_child[i] += temp_child;
      }
    }
  }
  return num_child[i] + 1;
}
void solve() {
  int n;
  cin >> n >> k;

  graph.resize(n + 1);
  visited.resize(n + 1, false);
  num_child.resize(n + 1, 0);

  for (int i = 0; i < n - 1; i++) {
    int v, u;
    cin >> v >> u;

    graph[v].push_back(u);
    graph[u].push_back(v);
  }

  int L, R;
  int minimo = 0;

  while (L < R) {
    int x = (L + R) / 2;

    // encontrar componente
    int cont = 0;
    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        minimo = min(dfs(i) - 1, minimo);
      }
    }

    // Binary Search
    if (x > minimo) {
      L = x + 1;
    } else {
      R = x;
    }
  }
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
