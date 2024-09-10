#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> vt(n);

    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        vt[i] = {a,b};
    }


    sort(vt.begin(), vt.end(), [](const pair<int,int>& a, const pair<int,int>& b){ return a.second < b.second;});

    int last = -1;
    int cont = 0;
    for(int i = 0; i < n; i++){
        if(last <= vt[i].first){
            cont++;
            last = vt[i].second;
        }
    }
    cout << cont << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
