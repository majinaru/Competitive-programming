#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

void move(int &x, int &y,char s){
    if(s == 'N'){
        y +=1;
    }
    if(s == 'E'){
        x+=1;
    }
    if(s == 'S'){
        y-=1;
    }
    if(s == 'W'){
        x -=1;
    }
}

void solve(){
    int n, a,b;
    cin >> n >> a >> b;

    string s;
    cin >> s;
    int x = 0, y = 0, lastx =-1, lasty = -1;

    while(x <= 20 && y <= 20 && x >= -20 && y >= -20){

        if(x == lastx && lasty == y){
            break;
        }

        lastx = x;
        lasty= y;

        for(int i = 0; i < n; i++){
            move(x,y,s[i] );
            if(x == a && y == b){
                cout << "YES" << endl;
                return;
            }
        }
    }
        cout << "NO" << endl;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
