#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<string> a(n);
  unordered_set<string> teste;
  vector<string> b(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    teste.insert(a[i]);
  }

  bool cond = true;
  for (int i = 0; i < n; i++) {
    cin >> b[i];

    if (teste.insert(b[i]).second) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] != b[i][j] && cond) {
          cout << i + 1 << " " << j + 1 << endl;
          cond = false;
        }
      }
    }
  }
}
