#include<bits/stdc++.h> 
using namespace std;
#define endl '\n'
using ll = long long;
string s;
vector<int> p;
vector<int> f;
vector<bool> visited;
vector<int> res;

void ciclo(int x){
    for(auto j: res){
        visited[j] = true;
        f[j] = x; 
    }
    res.clear();
}

int fun(int j){

    int atual = ((s[j] - '0')? 0 : 1);

    if(visited[j]){
        return f[j];
    }
    res.push_back(j);
    visited[j] = true;

    if(p[j] == j){
        return f[j] = atual;
    }

    return f[j] = atual + fun(p[j]);
}

void solve(){
    int n;
    cin >> n;
    p.resize(n);
    f.assign(n, -1);
    visited.assign(n, false);


    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
    }

    cin >> s;

    for(int i = 0; i < n; i++){
        if(f[i] == -1){
            f[i] = 0;
            cout << fun(i) << " ";
            ciclo(f[i]);
        }
        else
            cout << f[i] << " ";
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
