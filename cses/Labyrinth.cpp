#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

struct nodo {
  int x, y;
};

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<char>> mat(n, vector<char>(m));
  vector<vector<pair<int, int>>> graph(n);
  pair<int, int> a;
  queue<pair<int, int>> bfs;
  pair<int, int> start, end;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];

      if (mat[i][j] == 'A') {
        start = {i, j};
      }
      if (mat[i][j] == 'B') {
        end = {i, j};
      }
    }
  }

  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  int r[] = {'U', 'D', 'R', 'L'};

  vector<vector<bool>> visited(n, vector<bool>(m, false));
  vector<vector<tuple<int, int, char>>> where(
      n, vector<tuple<int, int, char>>(m, {-1, -1, '#'}));

  bfs.push(start);
  bool cond = true;
  bool condres = true;

  while (!bfs.empty()) {
    auto [x, y] = bfs.front();
    bfs.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] &&
          mat[nx][ny] != '#' && mat[nx][ny] != 'A' && cond) {

        if (mat[nx][ny] == 'B') {
          condres = false;
        }

        bfs.push({nx, ny});
        visited[nx][ny] = true;
        where[nx][ny] = {x, y, r[i]};

        if (make_pair(nx, ny) == end) { // b
          cond = false;
        }
      }
    }
  }

  /*for (int i = 0; i < n; i++) {*/
  /*  for (int j = 0; j < m; j++) {*/
  /*    cout << get<2>(where[i][j]) << " ";*/
  /*  }*/
  /*  cout << endl;*/
  /*}*/

  auto [x, y] = end;
  string res;
  while (true) {
    int ax = get<0>(where[x][y]);
    int ay = get<1>(where[x][y]);
    char l = get<2>(where[x][y]);

    if (l == '#') {
      break;
    }

    res += l;
    x = ax;
    y = ay;
  }

  if (condres)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    cout << res.size() << endl;
    reverse(res.begin(), res.end());
    cout << res << endl;
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
