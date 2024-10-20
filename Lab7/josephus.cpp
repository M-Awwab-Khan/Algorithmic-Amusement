#include <iostream>
using namespace std;

int josephus(int n, int k) {
  int i = 1;
  int ans = 0;

  while (i <= n) {
    ans = (ans + k) % i;
    i++;
  }

  return ans + 1;
}

int main() {
  int n = 5;
  int k = 2;

  cout << "The winner is " << josephus(n, k) << endl;

  return 0;
}

