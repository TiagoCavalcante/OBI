// Extreme weather events such as extraordinary rainfall are increasingly
// frequent and intense all around the world.
// The National Monitoring Center of Nlogônia has day-to-day rain gauges
// scattered throughout the kingdom. Each measurement is an integer, indicating
// the amount of rain, in millimeters, which fell in Nlogonia on a given day.
// As the system has been in existence for several years, the measurement list
// is too long.
// Concerned about the matter, the king of Nlogonia ordered the Minister of
// Science to create a program computer to calculate how many intervals are in
// the measurement list such that the sum of measurements in this interval is
// equal to a certain value S.
// More precisely, consider a list with N measurements, indicating the amount
// of rain from day 1 to day N. Also consider all possible intervals of days
// between 1 and N. The king wants to know how many intervals have the sum of
// the measurements exactly equal to S.
// The Minister of Science is a brilliant physicist, but he doesn't know how to
// solve this task. Can you help him?
// Input:
//   • the 1st line contains the integer N.
//   • the 2nd line contains the integer S.
//   • the 3rd line contains N integers Xi.
// Output:
//   • the number of sub-intervals that have a sum S.
// Restrictions:
//   • 1 ≤ N ≤ 100000
//   • 0 ≤ S ≤ 1000000
//   • 0 ≤ Xi ≤ 10, for 1 ≤ i ≤ N

#include <iostream>

int main() {
  uint32_t N, S;

  std::cin >> N >> S;

  uint32_t measurements[N];

  for (auto i = 0; i < N; i++) {
    std::cin >> measurements[i];
  }

  auto equals = 0;

  for (auto i = 0; i < N; i++) {
    auto sum = 0;

    for (auto j = i; j < N; j++) {
      sum += measurements[j];

      if (sum == S) {
        equals++;
      } else if (sum > S) {
        break;
      }
    }

    // If the sum of all numbers from i to N is less than S, then the sum from
    // i+1 to N will be less than S, as the numbers are non-negative.
    if (sum < S) {
      break;
    }
  }

  std::cout << equals << "\n";
}