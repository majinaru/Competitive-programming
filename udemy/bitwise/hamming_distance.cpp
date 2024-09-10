#include <bits/stdc++.h>
using namespace std;

int numberOfBit(int i) {
  int cont = 0;
  while (i > 0) {
    i = i & (i - 1);
    cont++;
  }
  return cont;
}

int hammingDistance(int x, int y) {
  cout << numberOfBit(x ^ y) << endl;
  return 0;
}

int main() {
  int x = 1;
  int y = 4;

  hammingDistance(x, y);
}
