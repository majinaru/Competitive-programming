#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

void solve(){
    int n;
    cin >> n;

    set<int> ans;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins;
    }

    for(int i = 0; i < n; i++){
        for(auto v: ans){
            ans.insert(v+ coins[i]);
        }
    }


    for(auto v : ans){
        cout << v <<" "; 
    }
    cout << endl;

}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
