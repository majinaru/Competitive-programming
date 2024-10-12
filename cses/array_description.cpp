#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll
const int MOD = 1e9+7;
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    vector<int> vt(n);
    vector<vector<int>> dp(m+2, vector<int>(n+1));
 
    for(int i = 0; i < n; i++){
        cin >> vt[i];
    }
 
    // caso inicial 0
    if(vt[0] == 0){
        for(int i = 1; i <= m;i++){
            dp[i][1] = 1;
        }
    }
    else{
        dp[vt[0]][1] = 1;
    }

    // geral
    for(int i = 1; i <= n; i++){
        if(vt[i-1] == 0){
            for(int j = 1; j <= m; j++){
                (dp[j][i]+= (dp[j-1][i-1] + dp[j][i-1]+ dp[j+1][i-1])) %= MOD;
            }
        }
        else{
            (dp[vt[i-1]][i] += (dp[vt[i-1] -1][i-1] + dp[vt[i-1]][i-1] + dp[vt[i-1]+1][i-1])) %= MOD ;
        }
    }
 
 
    /*for(int i = 0; i<= m;i++){*/
    /*    for(int j = 0; j<=n; j++){*/
    /*        cout << dp[i][j]<< " ";*/
    /*    }*/
    /*    cout << endl;*/
    /*}*/


    // output
    if(vt[n-1] != 0){
        cout << dp[vt[n-1]][n] % MOD<< endl;
    }
    else{
        int sum = 0;
        for(int i = 0; i <= m; i++){
            sum= (sum + dp[i][n]) % MOD;
        }
        cout << sum % MOD << endl;
    }
 
 
}
 
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

