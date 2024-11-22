#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

bool primo(int x){
    for(int i =2; i * i <= x; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}



void solve(){
    int n;
    cin >> n;

    if(n <=4 ){
        cout << -1 << endl;
        return;
    }

    vector<int> imp;
    for(int i = 1; i <= n; i+=2){
        if(i != 5)
            imp.push_back(i);
    }

    reverse(imp.begin(), imp.end());

    for(auto v : imp){
        cout << v << " ";
    }

    cout << 5 << " " << 4 << " "; 

    for(int i = 2; i <= n; i+=2){
        if(i != 4)
        cout << i << " ";
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
