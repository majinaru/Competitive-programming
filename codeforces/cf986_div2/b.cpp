#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int ll
using ll = long long;

void solve(){
    int n, b, c;
    cin >>n >> b >> c;


    if(b == 0){
        if(c >= n){
            cout << n << endl; 
        }
        else if(c == n-1 || c == n-2){
            cout << n-1 << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    else{
        if(c >= n){
            cout << n << endl;
        }
        else{
            cout << n -max(0ll, (n-c-1)/b +1 ) << endl;
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
