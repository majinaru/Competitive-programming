#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n+1), b(n+1);
    vector<vector<int>> g(n+1, vector<int>(k+2,0));

    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];

        int x = a[i], y= b[i];
        int j = 1;
        while(x!= 0 && y !=0 && j <=k){
            if (x == 1 && y == 1) {
                g[i][j+1] = 1 + g[i][j-1];
                break;
            }
            if(x<y){
                g[i][j]= x + g[i][j-1];
                y--;
            }
            else{
                g[i][j]= y + g[i][j-1];
                x--;
            }
            j++;
        }
    }

    vector<vector<int>> dp(n+1, vector<int>(k+2, 1e9));
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k+1; j++){
            for(int p= 1; p<=j; p++){   
                dp[i][j] = min(min(dp[i][j], dp[i-1][j]), dp[i-1][j-p] + g[i][p]);
            }
        }
    }
    cout << ((dp[n][k] == 1e9 )? -1 : dp[n][k] )<< endl;

}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--){
      solve();
  }
}
