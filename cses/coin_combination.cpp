#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define endl '\n'
using ll = long long;
const int INF = 1e9+7;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> coin(n);
    for(int i = 0; i < n; i++){
        cin >> coin[i];
    }

    vector<int> dp(x+1, 0);

    dp[0] = 1;
    for(int i = 1; i <= x; i++){
        for(auto c: coin){
            if(i-c>=0){
                (dp[i] += dp[i-c] ) %= INF; 
            }
        }
    }
    cout << dp[x] << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
