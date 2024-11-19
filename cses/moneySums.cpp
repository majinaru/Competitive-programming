#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

void solve(){
    int n;
    cin >> n;

    set<int> ans;
    ans.insert(0);
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];

        set<int> aux;
        for(auto v: ans){
            aux.insert(v+ coins[i]);
        }
        ans.insert(aux.begin(), aux.end());
    }


    cout << ans.size()-1<< endl;
    for(auto v : ans){
        if(v != 0)
            cout << v <<" "; 
    }
    cout << endl;

}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
