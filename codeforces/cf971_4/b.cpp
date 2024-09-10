#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n;
    cin >>  n;

    vector<vector<char>> vt(n, vector<char>(4));
    vector<int> ans;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            cin >> vt[i][j];
            if(vt[i][j] == '#'){
                ans.push_back(j+1);
            }
        }
    }

    for(int i = ans.size()-1; i >=0; i--){
        cout << ans[i] << " ";
    }
    cout << endl;
}


int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
