#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 10000000;

ll funcao(ll x, ll y) { return ((x + y) % MOD); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll soma = 0;

  int n;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      soma = (soma + funcao(a[i], a[j]));
    }
  }
  cout << soma << endl;
}
