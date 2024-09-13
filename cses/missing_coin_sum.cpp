#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll

int sol(int n, vector<int> vt){
    int x =1;

    for(int i = 0; i < n; i++){
        if(vt[i] > x){
            return x;
        }
        else{
            x+= vt[i];
        }
    }
    return x;
}

void solve() {
    int n;
    cin >> n;

    vector<int> vt(n);
    for(int i = 0; i < n; i++){
        cin >> vt[i];
    }


    sort(vt.begin(), vt.end());

    cout << sol(n, vt) << endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
