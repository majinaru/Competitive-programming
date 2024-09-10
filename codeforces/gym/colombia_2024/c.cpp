#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;


void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> pref(n+1, 0);
    map<int, int> mp;
    ll cont = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }


    for(int i = 1; i < n; i++){
        pref[i] = pref[i-1] + ((a[i-1] > a[i]) ? 1 : 0);

        mp[2*pref[i-1] - i + 1]++;

        if(mp[2*pref[i]- i]){
            cont+= mp[2*pref[i]-i];
        }
    }

    cout << cont +n << endl;

}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
