#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

vector<vector<int>> mat;

string layers(int inicio, int n, int m) {
  string t;
  for (int i = inicio; i <= m; i++) {
    t.push_back(mat[inicio][i] + '0');
  }
  for (int i = inicio + 1; i <= n; i++) {
    t.push_back(mat[i][m] + '0');
  }

  for (int i = m - 1; i >= inicio; i--) {
    t.push_back(mat[n][i] + '0');
  }

  for (int i = n - 1; i > inicio; i--) {
    t.push_back(mat[i][inicio] + '0');
  }

  t += t.substr(0, 3);

  return t;
}

int qtd(string t) {
  int cont = 0;
  for (int i = 0; i < t.size() - 3; i++) {
    if (t.substr(i, 4) == "1543") {
      cont++;
    }
  }

  return cont;
}

vector<vector<int>> transforma(vector<string> ses) {
  vector<vector<int>> mat(ses.size(), vector<int>(ses[0].size()));
  for (int i = 0; i < ses.size(); i++) {
    for (int j = 0; j < ses[i].size(); j++) {
      mat[i][j] = ses[i][j] - '0';
    }
  }

  return mat;
}

void solve() {
  int n, m;
  cin >> n >> m;

  mat.clear();
  mat.resize(n, vector<int>(m));
  vector<string> ses;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    ses.push_back(s);
  }

  mat = transforma(ses);

  int cont = 0;
  for (int i = 0; i < min(n, m) / 2; i++) {
    string t = layers(i, n - i - 1, m - 1 - i);
    cont += qtd(t);
  }

  cout << cont << endl;
}

int32_t main() {
  /*cin.tie(0)->sync_with_stdio(0);*/
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
