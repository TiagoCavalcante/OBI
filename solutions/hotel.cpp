// The Teachers' Vacation Camp hotel has a promotion for the July holidays. THE
// Promotion is valid for those arriving from the 1st of July and leaving on
// August 1st. The price of the hotel is lower for those who arrive earlier,
// and it increases every day. Most precisely, the promotion works like this:
//   • the hotel rate for each person arriving on the 1st is D dollars, so
//     will pay a total of 31 × D dollars.
//   • the hotel rate increases by A dollars per day.
//     That is, the daily rate is D + A dollars for those who arrive on day 2;
//     D + 2 × A dollars on day 3;
//     D + 3 × A dollars on day 4 and so on.
//   • from the 16th, the daily rate does not increase.
// Note that whoever arrives on the 2nd will pay a total of 30 × (D + A)
// dollars; who arrives on the 3rd will pay a total of 29 × (D + 2 × A)
// dollars, and so on.
// Bruno is very fond of teacher Vilma, and to please her, he wants to help her
// plan her vacation, writing a program to calculate the total (in dollars)
// that teacher Vilma will spend, depending on the day she arrives at the hotel.
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