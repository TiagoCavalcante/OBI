// Given N, M and S, this program must find the biggest number k such that:
//   • k is in the interval [N, M] (ie. N ≤ k ≤ M).
//   • the sum of the digits of k is S.
// Input:
//   • the 1st line contains the integer N.
//   • the 2nd line contains the integer M.
//   • the 3rd line contains the integer S.
// Output:
//   • the integer k, if it exists, -1 otherwise.
// Restrictions:
//   • 1 ≤ N ≤ M ≤ 10000
//   • 1 ≤ S ≤ 36

#include <iostream>

int sumOfDigits(int k) {
  // This works because k < 10000.
  auto d1 = (k % 10);
  auto d2 = (k % 100 - d1) / 10;
  auto d3 = (k % 1000 - d2) / 100;
  auto d4 = (k % 10000 - d3) / 1000;

  return d1 + d2 + d3 + d4;
}

int main() {
  int N, M, S;

  std::cin >> N >> M >> S;

  for (int i = M; i >= N; i--) {
    if (sumOfDigits(i) == S) {
      std::cout << i << "\n";

      // Early exit.
      return 0;
    }
  }

  std::cout << "-1" << "\n";
}