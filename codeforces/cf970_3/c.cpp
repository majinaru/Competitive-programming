#include<bits/stdc++.h> 
using namespace std;
#define endl '\n'
using ll = long long;

void solve(){
    int l, r;
    cin >> l >> r;

    int cont = 0;
    int res = 0;
    for(int i = l; i <=r; i+=cont){
        res++;
        cont++;
    }
    cout << res << endl;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
