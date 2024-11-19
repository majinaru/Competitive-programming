#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

void solve(){
    int k;
    cin >> k;

    map<int,int> mp;
    for(int i = 0; i < k; i++){
        int a;
        cin >> a;

        mp[a]++;
    }

    k-=2;

    for(int i = 1; i <= k; i++){
        if(k % i == 0 && mp.count(k/i) && mp.count(i)){
            cout <<  i << " " << k /i << endl;
            return;
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
