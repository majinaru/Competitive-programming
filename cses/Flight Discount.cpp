#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll
const int INF = 1e18 + 5;

vector<vector<pair<int, int>>> graph;

void solve() {
  int n, m;
  cin >> n >> m;

  graph.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;
    graph[a].push_back({b, w});
  }

  // Dijkstra
  vector<int> nodos(n, INF);
  nodos[0] = 0;
  vector<int> nodosD(n, INF);
  nodosD[0] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      djk;
  djk.push({0, 0}); // {distância, nó}

  while (!djk.empty()) {
    pair<int, int> x = djk.top();
    djk.pop();

    int dist = x.first;
    int no = x.second;

    if (dist > nodos[no])
      continue;

    for (auto v : graph[no]) {
      int adj_no = v.first;
      int peso = v.second;
      bool cond = false;
      bool t = true;

      if (nodos[adj_no] > nodos[no] + peso) {
        nodos[adj_no] = nodos[no] + peso;
        djk.push({nodos[adj_no], adj_no});
        t = false;
      }

      if (nodosD[adj_no] > nodos[no] + peso / 2) {
        nodosD[adj_no] = nodos[no] + peso / 2;
        cond = true;
      }

      if (nodosD[adj_no] > nodosD[no] + peso) {
        nodosD[adj_no] = nodosD[no] + peso;
        cond = true;
      }

      if (cond && t)
        djk.push({nodosD[adj_no], adj_no});
    }
  }

  /*for (auto v : nodos) {*/
  /*  cout << v << " ";*/
  /*}*/
  /*cout << endl;*/
  /**/
  /*for (auto v : nodosD) {*/
  /*  cout << v << " ";*/
  /*}*/
  /*cout << endl;*/

  cout << nodosD[n - 1] << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
