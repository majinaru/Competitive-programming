#include <bits/stdc++.h>
using namespace std;
const long long N = 1000000;

void primeSieve(vector<int> &sieve) {

  sieve[1] = sieve[0] = 0;

  // start from 2 and set all multiples of i as notprime
  for (int i = 2; i * i <= N; i++) {
    if (sieve[i]) {
      for (long long j = i * i; j <= N; j += i) {
        sieve[j] = 0;
      }
    }
  }
}

int main() {
  vector<int> sieve(N, 1);
  primeSieve(sieve);

  for (int i = 0; i <= 100; i++) {
    if (sieve[i]) {
      cout << i << " ";
    }
  }
  cout << endl;
  return 0;
}
