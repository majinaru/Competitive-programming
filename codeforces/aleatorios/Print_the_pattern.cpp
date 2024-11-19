#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    string ans = "A";

    for (int i = 1; i < n; i++){
        string aux = ans;
        ans.push_back(i+ 'A');
        ans+= aux;
    }

    cout << ans;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
