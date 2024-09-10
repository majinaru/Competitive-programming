#include <bits/stdc++.h>
#include <cctype>
using namespace std;

bool is_subseq(string &s, string &t) {
  int i = 0;
  for (auto c : s) {
    if (c == t[i]) {
      i++;
    }
    if (i == t.size()) {
      return true;
    }
  }

  return false;
}

int main() {
  string s, t;
  cin >> s >> t;

  for (char &c : s) {
    c = toupper(c);
  }
  if (t.back() == 'X') {
    t.pop_back();
  }

  cout << ((is_subseq(s, t)) ? "Yes" : "No") << endl;
}
