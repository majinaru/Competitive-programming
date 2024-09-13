#include<bits/stdc++.h> 
using namespace std;
#define endl '\n'
using ll = long long;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int raiz = sqrt(n);
    vector<int> freq(raiz);

    if(raiz * raiz != n){
        cout << "No" << endl;
        return;
    }

    for(int i = 0; i < n; i++){
        freq[i % raiz]+= s[i] -'0';
    }

    if(freq[0] == raiz && freq[raiz-1] == raiz){
        if(raiz == 2){
            cout << "Yes" << endl;
            return;
        }
        for(int i = 1; i < raiz-1; i++){
            if(freq[i] > 2){
                cout << "No" << endl;
                return;
            }
        }
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
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
