#include<bits/stdc++.h>
using namespace std;
#define endl '\n';
using ll = long long;

int ask(int a, int b){
    cout << "? " << a << " " << b << endl;
    int res;
    cin >> res;
    return res;
}

void solve(){
    int n;
    cin >> n;
    vector<int> pos(n+1, -1);

    for(int i = 2; i <= n; i++){
        int last = 1;
        while(true){
            int x = ask(last, i);
            if(x == last)
                break;
            last = x;
        }
        pos[i] = last;
    }
    
    cout << "! ";
    for(int i = 2; i <=n; i++){
        cout << i << ' ' << pos[i] << ' ';
    }
    cout << endl;
}

int32_t main(){
    /*cin.tie(0)->sync_with_stdio(0);*/
    int t; 
    cin >> t;
    while(t--){
        solve();
    }
}
