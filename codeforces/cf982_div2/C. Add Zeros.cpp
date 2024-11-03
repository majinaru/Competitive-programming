#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll

map<ll, vector<ll>> graph;
set<int> visited;

int dfs(int x) {
  if (visited.count(x)) {
    return x;
  }
  visited.insert(x);

  if (graph.count(x) == 0) {
    return x;
  }

  int maxn = 0;
  for (auto v : graph[x]) {
    maxn = max(dfs(v + x), maxn);
  }

  return maxn;
}

void solve() {
  int n;
  cin >> n;
  graph.clear();
  visited.clear();

  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;

    graph[val - 1 + (i + 1)].push_back(i);
  }

  int sz = n;
  cout << dfs(sz) << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
