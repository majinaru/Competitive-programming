#include<bits/stdc++.h> 
using namespace std;
#define endl '\n'
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<int> vt(n);
    for(int i = 0; i < n; i++){
        cin >> vt[i];
    }
    sort(vt.begin(), vt.end());
    
    int index = 0;
    int L = 0, R = n-1;
    while(L<R){
        if(index % 2 == 0){
            L++;
        }
        else{
            R--;
        }
        index++;
    }
    cout << vt[R] << endl;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
