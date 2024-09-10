#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    map<int,int> pos;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pos[a[i]]= i;
    }

    for(int i = 0; i < n; i++){
        if(pos[x-a[i]] && i != pos[x-a[i]]){
                cout << i+1 << " " << pos[x-a[i]]+1 << endl;
                return;
        }
    }

    cout << "IMPOSSIBLE" << endl;


}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
} 
