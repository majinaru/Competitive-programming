#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define endl '\n'

void solve(){
    int x, y , k;
    cin >> x >> y >> k;

    int p = x/k + ((x%k>0) ? 1 : 0);
    int t = y/k + ((y%k >0) ? 1 : 0);
    if(p> t){
        cout << p * 2 -1 << endl;
    }
    else
        cout << t*2 << endl;

}


int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
