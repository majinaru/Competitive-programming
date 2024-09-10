#include <bits/stdc++.h>
#include <cmath>
using namespace std;

struct Card {
  int a;
  int c;
  int index;
};

int main() {
  int n;
  cin >> n;
  vector<Card> cards(n);

  for (int i = 0; i < n; i++) {
    int a, c;
    cin >> a >> c;
    cards[i] = {a, c, i};
  }

  // sorting in asceding order of ci
  sort(cards.begin(), cards.end(),
       [&](const auto &l, const auto &r) { return l.c < r.c; });

  // computando a resposta
  vector<int> ans;
  int v = 0;

  for (int i = 0; i < n; i++) {
    if (cards[i].a > v) {
      v = cards[i].a;
      ans.push_back(cards[i].index);
    }
  }

  sort(ans.begin(), ans.end());

  // Print the answer
  const int m = (int)ans.size();
  cout << m << endl;
  for (int i = 0; i < m; i++) {
    cout << ans[i] + 1 << ' ';
  }
  cout << endl;
}
