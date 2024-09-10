#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  vector<int> alpha(26 + 1);
  for (int i = 0; i < s.length(); i++) {
    alpha[s[i] - 'a' + 1] += 1;
  }

  for (int i = 1; i <= s.length(); i++) {
    int cont = 0;

    for (int j = 1; j <= 26; j++) {
      if (alpha[j] == i) {
        cont++;
      }
    }
    if (cont != 2 && cont != 0) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}
