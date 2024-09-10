#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  double n;
  cin >> n;
  vector<pair<double, int>> points(n + 1);
  double x, y;
  for (double i = 1; i <= n; i++) {
    cin >> x >> y;
    points[i] = {x, y};
  }
  for (double i = 1; i <= n; i++) {
    double distance = -1;
    double max_distance = -1;
    double id = 0;

    for (double j = 1; j <= n; j++) {
      if (j != i) {
        distance = sqrt(pow((points[i].first - points[j].first), 2) +
                        pow(points[i].second - points[j].second, 2));
        if (distance > max_distance) {
          max_distance = distance;
          id = j;
        }
        if (distance == max_distance && id > j) {
          id = j;
        }
      }
    }
    cout << id << endl;
  }
}
