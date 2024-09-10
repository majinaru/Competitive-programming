#include<bits/stdc++.h>
using namespace std;
#define endl "\n";
using ll = long long;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<string> vt(n+1);

    for(int i = 1; i <= n; i++){
        cin >> vt[i];
    }


    for(int i = 0; i < q; i++){
        int x,y;
        cin >> x >> y;
        if(vt[x]== vt[y]){
            cout << x-y << endl;
            return;
        }

        if(vt[x][0] == vt[y][0]  || vt[x][1] == vt[y][1]  || vt[x][0] == vt[y][1] || vt[x][1] == vt[y][0]){
            cout << x-y << endl;
            return;
        }


    }
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
