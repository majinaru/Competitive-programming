#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll

void solve() {
    int n,m,k;
    cin >> n >> m >>k;
    int w;
    cin >> w;
    vector<int> pesos(w+1);
    vector<vector<int>> mat(n+2, vector<int>(m+2));
    vector<vector<int>> prefx(n+2, vector<int>(m+2));

    for(int i = 1; i <= w; i++){
        cin >> pesos[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=m; j++){

            if(i+k-1 <= n && j+k-1 <=m){
                mat[i][j]++;
                mat[i+k][j]--;
                mat[i][j+k]--;
                mat[i+k][j+k]++;
            }
        }
    }

    vector<int> sums_queries;
    sums_queries.push_back(0);

    for(int i = 1; i <=n; i++){
        for(int j = 1; j<=m;j++){
            prefx[i][j]= prefx[i-1][j] + prefx[i][j-1] - prefx[i-1][j-1] + mat[i][j];
            sums_queries.push_back(prefx[i][j]);
        }
    }

    sort(pesos.begin() +1, pesos.end(), greater<int>());
    sort(sums_queries.begin()+1, sums_queries.end(), greater<int>());
    int sums = 0;


    for(int i = 1; i <= w; i++){
        sums+= pesos[i] * sums_queries[i];
    }

    cout << sums << endl;

}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--){
      solve();
  }
}
