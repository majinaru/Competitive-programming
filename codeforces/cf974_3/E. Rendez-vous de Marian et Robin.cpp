#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define endl "\n"
using ll = long long;
#define int ll
const int INF = 1e18 + 5;

void djikstra(vector<vector<int>> &nodosX, vector<vector<pair<int, int>>> graph,
              int init, vector<bool> has_horse) {

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  pq.push({0, init});

  while (!pq.empty()) {
    auto [dist, origem] = pq.top();
    pq.pop();

    if (dist > nodosX[origem][0]) {
      continue;
    }

    for (auto [peso, atual] : graph[origem]) {

      // djikstra normal
      if (nodosX[atual][0] > nodosX[origem][0] + peso) {
        nodosX[atual][0] = nodosX[origem][0] + peso;
        pq.push({nodosX[atual][0], atual});
      }

      // achou um cavalo
      if (nodosX[origem][1] == INF && has_horse[origem]) {
        nodosX[origem][1] = nodosX[origem][0];
      }

      // veio de um nodo com cavalo
      if (nodosX[origem][1] != INF &&
          nodosX[atual][1] > nodosX[origem][1] + peso / 2 + nodosX[origem][0]) {
        nodosX[atual][1] += nodosX[origem][1] + peso / 2;
      }
    }
  }
}

void solve() {
  int n, m, h;
  cin >> n >> m >> h;

  vector<vector<pair<int, int>>> graph(n);
  vector<vector<int>> nodos1(n, vector<int>(2, INF));
  vector<vector<int>> nodos2(n, vector<int>(2, INF));
  vector<bool> has_horse1(n, false);
  vector<bool> has_horse2(n, false);

  nodos1[0][0] = 0;
  nodos2[n - 1][0] = 0;

  for (int i = 0; i < h; i++) {
    int a;
    cin >> a;
    a--;

    has_horse1[a] = true;
    has_horse2[a] = true;
  }

  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;

    graph[a].push_back({w, b});
    graph[b].push_back({w, a});
  }

  djikstra(nodos1, graph, 0, has_horse1);
  djikstra(nodos2, graph, n - 1, has_horse2);

  /*for (auto v : nodos1) {*/
  /*  cout << v[0] << " ";*/
  /*}*/
  /*cout << endl;*/
  /**/
  /*for (auto v : nodos1) {*/
  /*  cout << v[1] << " ";*/
  /*}*/
  /*cout << endl;*/
  /**/
  /*for (auto v : nodos2) {*/
  /*  cout << v[0] << " ";*/
  /*}*/
  /*cout << endl;*/
  /**/
  /*for (auto v : nodos2) {*/
  /*  cout << v[1] << " ";*/
  /*}*/
  /*cout << endl;*/

  int res = INF;
  for (int i = 0; i < n; i++) {
    res = min({res, max(nodos1[i][0], nodos2[i][0]),
               max(nodos1[i][1], nodos2[i][0]), max(nodos1[i][0], nodos2[i][1]),
               max(nodos1[i][1], nodos2[i][1])});
  }
  cout << ((res == INF) ? -1 : res) << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}
