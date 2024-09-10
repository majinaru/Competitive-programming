#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define endl '\n'

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> mat(2, vector<int>(n+1));


    for(int i= 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        mat[b][a] = 1;
    }

    int qtd= 0;
    int fixo =0 ;
    int tri = 0;

    for(int i = 0; i <= n; i++){
        if(mat[0][i] && mat[1][i]){
            fixo++;
            qtd+=2;
        }
        else if(mat[0][i] || mat[1][i]){
            qtd++;
        }

        if(i+1 <= n && i-1>= 0){
            if(mat[0][i] == 1 &&  mat[1][i-1] && mat[1][i+1]){
                tri++; }
            if(mat[1][i] && mat[0][i-1] && mat[0][i+1]){
                tri++;
            }
        }
    }
    cout <<  tri+ (qtd-2)*fixo << endl;
}


int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
