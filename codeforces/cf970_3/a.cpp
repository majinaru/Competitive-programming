#include<bits/stdc++.h> 
using namespace std;
using ll = long long;
#define endl "\n"

void solve(){
    int a, b;
    cin >> a >> b;

    int sumTotal = b + a/2 + a % 2;

    if(sumTotal % 2 == 0 || (b == 0 && a % 2 == 0)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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
