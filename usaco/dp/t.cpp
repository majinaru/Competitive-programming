#include<bits/stdc++.h>
using namespace std;
#define end "\n"
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<int> h(n);
    vector<int> dp(n+1, 0);

    for(int i = 0; i < n; i++){
        cin >> h[i];
    }

    dp[0] = 0;
    dp[1] =abs(h[0]-h[1]);


    for(int i = 2; i < n; i++){
        dp[i] = min( dp[i-1]+ abs( h[i-1] - h[i]),dp[i-2]+ abs( h[i-2]-h[i]));
    }
    cout << dp[n-1] << endl;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
