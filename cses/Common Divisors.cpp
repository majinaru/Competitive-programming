#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int lim = 1e6;

/*vector<vector<int>> divisors(1e6 + 1);*/
vector<int> d(1e6 + 1);
int right1 = 0, right2 = 0;

/*void preprocessing() {*/
/*  for (int i = 1; i <= lim; i++) {*/
/*    for (int j = i; j <= lim; j += i) {*/
/*      divisors[j].push_back(i);*/
/*    }*/
/*  }*/
/*}*/

void getDivisors(int n) {
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      d[i]++;

      if (i * i != n) {
        int v = n / i;
        d[v]++;
        if (d[v] > 1 && right2 < v) {
          right2 = v;
        } else if (d[v] == 1 && right1 < v) {
          right1 = v;
        }
      }

      if (d[i] > 1 && right2 < i) {
        right2 = i;
      } else if (d[i] == 1 && right1 < i) {
        right1 = i;
      }
    }
  }
}

void solve() {
  int n;
  cin >> n;

  vector<int> vt(n);

  for (int i = 0; i < n; i++) {
    cin >> vt[i];

    getDivisors(vt[i]);
    /*for (auto v : divisors[vt[i]]) {*/
    /*  if (v * v > vt[i])*/
    /*    break;*/
    /*  d[v]++;*/
    /**/
    /*  if (d[v] > 1 && right2 < v) {*/
    /*    right2 = v;*/
    /*  } else if (d[v] == 1 && right1 < v) {*/
    /*    right1 = v;*/
    /*  }*/
    /**/
    /*  int otherside = vt[i] / v;*/
    /**/
    /*  if (d[otherside] > 1 && right2 < otherside) {*/
    /*    right2 = otherside;*/
    /*  } else if (d[otherside] == 1 && right1 < otherside) {*/
    /*    right1 = otherside;*/
    /*  }*/
    /*}*/
  }

  cout << ((right2 != 0) ? right2 : right1) << endl;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
