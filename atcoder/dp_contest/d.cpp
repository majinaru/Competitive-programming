#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll

void solve(){
    int n, w;
    cin >> n >> w;
    vector<pair<int,int>> t; // weight- value
    

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        t.push_back({a,b});
    }

    sort(t.begin(), t.end());

    vector<vector<int>> dp(n+1, vector<int>(w+1,0));

    for(int i = 1; i <= n; i++){
        for(int j =1; j <= w; j++){
            if(j>= t[i-1].first)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j- t[i-1].first] + t[i-1].second);
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][w] << endl;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
