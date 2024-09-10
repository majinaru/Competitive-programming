#include<bits/stdc++.h> 
using namespace std;
#define endl '\n'
using ll = long long;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >>  s;

    if(s[0] != s[n-1]){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
