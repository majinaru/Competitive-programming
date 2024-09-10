#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;


void solve(){
    string s;
    cin >> s;

    map<char, char> mp;

    mp['0'] = '0';
    mp['1'] = '1';
    mp['2'] = '2';
    mp['3'] = 'E';
    mp['5'] = '5';
    mp['6'] = '9';
    mp['8'] = '8';
    mp['9'] = '6';
    mp['E'] = '3';

    string s2 = s;
    reverse(s2.begin(), s2.end());

    int cont = 0;

    for(int i = 0; i < s.size()/2+s.size()%2 ;i++){
        if(mp.count(s2[i])){
            if(s[i] == mp[s2[i]]){
                continue;
            }
            else{
                cont++;
            }
        }
        else if(mp.count(s[i])){
            cont++;
        }
        else{
            cont+=2;
        }
    }

    cout << cont << endl;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();

}
