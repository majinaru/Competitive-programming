#include <bits/stdc++.h>
using namespace std;

void uniqueNo2(vector<int> arr) {
  int n = arr.size();

  int result = 0;
  for (int i = 0; i < arr.size(); i++) {
    result = result ^ arr[i];
  }

  // position
  int pos = 0;
  int temp = result;
  while ((temp & 1) == 0) {
    pos++;
    temp = temp >> 1;
  }

  int setA = 0;
  int setB = 0;
  int mask = (1 << pos);

  for (int i = 0; i < arr.size(); i++) {
    if ((mask & arr[i]) > 0) {
      setA = setA ^ arr[i];
    } else {
      setB = setB ^ arr[i];
    }
  }

  cout << setA << endl;
  cout << setB << endl;
}

int main() {
  vector<int> arr = {1, 3, 5, 4, 1, 5, 7, 3};
  uniqueNo2(arr);
}
