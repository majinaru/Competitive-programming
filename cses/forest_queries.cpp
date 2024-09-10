#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
    int n,q;
    cin >> n >> q;

    vector<vector<ll>> prefx(n+1, vector<ll>(n+1,0));
    vector<vector<int>> mat(n+1, vector<int>(n+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char a;
            cin >> a;
            mat[i][j] = a=='*'? 1 : 0;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            prefx[i][j] = prefx[i][j-1] + prefx[i-1][j] - prefx[i-1][j-1]+ mat[i][j];
        }
    }

    for(int i = 0; i < q; i++){
        int y1, x1, y2,x2;
        cin >> y1 >> x1 >> y2 >> x2;

         if(y1 == y2 && x2 == x1){
            cout << mat[y1][x1] << endl;;
            continue;
        }


        int ans = prefx[y2][x2] - prefx[y1-1][x2] - prefx[y2][x1-1] + prefx[y1-1][x1-1];
        cout << ans << endl;
    }
    
}


int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
