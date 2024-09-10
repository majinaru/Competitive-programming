#include<bits/stdc++.h>
using namespace std;
#define endl '\n';
using ll = long long;
const int maxn = 3e5;

void solve(){
    int n; cin >> n;
    vector<char> a(n);
    vector<int> freq(maxn, 0); 
    vector<char> s2;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(freq[a[i]] == 0){
            freq[a[i]]++;
            s2.push_back(a[i]);
        }
    }

    vector<char> aux = s2;
    sort(s2.begin(), s2.end(), greater<char>());
    sort(aux.begin(), aux.end());

    string p1, p2;
    for(int i = 1; i < s2.size(); i+=2){
        p1+= s2[i];
        p2+= aux[i];
    }
    if(p2 > p1){
        s2 = aux;
    }
    
    cout << s2.size() << endl;
    for(auto v : s2){
        cout << v << " ";
    }
    cout << endl;



}

int32_t main(){
    /*cin.tie(0)->sync_with_stdio(0);*/
    int t; cin >> t;
    while(t--){
        solve();
    }

}
