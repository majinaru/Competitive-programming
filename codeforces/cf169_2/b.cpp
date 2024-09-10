#include<bits/stdc++.h>
using namespace std;
#define endl "\n";
using ll = long long;

void solve(){
    int l, r;
    int L, R;
    cin >> l >> r;
    cin >> L >> R;

    if(l > R || L > r ){
        cout << 1 << endl;
        return;
    }

    int ans = 0;

    if(R == r){
        ans--;
    }

    if(L == l){
        ans--;
    }

    int init = min(l,L);
    int end = max(r,R);

    for(int i = init; i <= end; i++){
        if(i >= L && i >= l && i <= R && i <=r){
            ans++;
        }
    } 
    cout << ans+1 << endl;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}
