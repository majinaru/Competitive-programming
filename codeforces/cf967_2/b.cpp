#include<bits/stdc++.h>
using namespace std;
#define endl '\n';
using ll = long long;

void solve(){
    int n;
    cin >> n;

    if(n&1){
        for(int i = 0; i < n/2; i++){
            cout << n-i << " " << i+1 << " ";
        }
        cout << (n+1) /2 << endl;
    }
    else{
        cout << -1 << endl;
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
