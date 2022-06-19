// Input:
//   • the 1st line contains the integer D.
//   • the 2nd line contains the integer A.
//   • the 3rd line contains the integer N.
// Output:
//   • the total value to be paid to the hotel for the stay.
// Restrictions:
//   • 1 ≤ D ≤ 1000
//   • 1 ≤ A ≤ 1000
//   • 1 ≤ N ≤ 31

#include <iostream>

int min(int a, int b) {
  return (a < b) ? a : b;
}

int main() {
  int D, A, N;

  std::cin >> D >> A >> N;

  auto days = 32 - N;
  auto increasedDays = min(N, 15) - 1;
  auto price = D + increasedDays * A;

  std::cout << days * price << "\n";
}