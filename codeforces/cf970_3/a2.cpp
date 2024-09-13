#include<bits/stdc++.h> 
using namespace std;
#define endl '\n'
using ll = long long;

void solve(int cont){
    int a, b;
    cin >> a >> b;


    if(a % 2 != 0){
        cout << "NO" << endl;
    }
    else{
        if(b%2 == 0){
            cout << "YES" << endl;
        }
        else{
            if(a >= 2 ){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    int cont = 0;
    while(t--){
        cont++;
        solve(cont );
    }
}
