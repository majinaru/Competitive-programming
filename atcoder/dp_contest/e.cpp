#include<bits/stdc++.h>
using namespace std;
#define endl '\n';
using ll = long long;
#define int ll
const int INF = 1e18L +5;

void solve(){
    int n, w;
    cin >> n >> w;

    vector<int> pesos(n+1);
    vector<int> values(n+1);
    int sum = 0;

    for(int i = 1; i <= n; i++){
        cin >> pesos[i];
        cin >> values[i];
        sum+= values[i];
    }

    vector<vector<int>> dp(n+1, vector<int> (sum+1, INF));
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            dp[i][j] = dp[i-1][j];
            if(j>= values[i])
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-values[i]]+ pesos[i]);
        }
    }

    int max_value= 0;
    for(int i = 0;i <=sum; i++){
        if(dp[n][i]<= w){ // não fiz a verificação
            max_value = i;
        }
    }

    cout << max_value << endl;
}


int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
