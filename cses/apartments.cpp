#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> ape(n);
    vector<int> apli(m);

    for(int i = 0; i < n; i++){
        cin >> ape[i];
    }

    for(int i = 0; i < m; i++){
        cin >> apli[i];
    }

    sort(ape.begin(), ape.end());
    sort(apli.begin(), apli.end());

    int ptrA = 0;
    int ptrB= 0;
    int cont = 0;

    while(ptrA < ape.size() && ptrB< apli.size()){
        if(abs(ape[ptrA] - apli[ptrB]) <= k){
            cont++;
            ptrA++;
            ptrB++;
        }
        else if(ape[ptrA] - apli[ptrB] > k){
            ptrB++;
        }
        else{
            ptrA++;
        }
    }
    cout << cont << endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
