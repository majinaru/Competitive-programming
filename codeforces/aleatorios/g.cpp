#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define endl "\n"


void solve(){
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> mat(n+1, vector<int> (m+1));
    for(int i= 1; i <= n; i++){
        for(int j= 1; j <= m ;j++){
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> pref(n+1, vector<int>(m+1));

    for(int i= 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            pref[i][j]+= pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + mat[i][j];
        }
    }

    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int ans = pref[x2][y2] - pref[x1-1][y2] - pref[x2][y1-1] + pref[x1-1][y1-1];
        cout << ans << endl;
    }
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
