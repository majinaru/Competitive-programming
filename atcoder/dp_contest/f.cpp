#include<bits/stdc++.h>
using namespace std;
#define endl '\n';
using ll = long long;

string s1, s2;

string achar(vector<vector<int>> dp, int n,int m){
    int x = n, y= m;
    string ans = "";
    while(x>0 && y>0){
        if(s1[x-1] == s2[y-1]){
            ans+= s1[x-1];
            x--;
            y--;
        }
        else if(dp[x-1][y] > dp[x][y-1]){
            x--;
        }
        else{
            y--;
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

void solve(){
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+2, vector<int>(m+2));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s2[j-1] == s1[i-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << achar(dp,n,m) << endl;
}


int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
