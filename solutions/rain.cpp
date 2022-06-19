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

	uint32_t measured[N];

	for (auto i = 0; i < N; i++) {
		std::cin >> measured[i];
	}

	auto equals = 0;

	for (auto i = 0; i < N; i++) {
		auto sum = 0;

		for (auto j = i; j < N; j++) {
			sum += measured[j];

			if (sum == S) {
				equals++;
			} else if (sum > S) {
				break;
			}
		}

		// If the of all numbers from i to N is less than S, then the sum from
		// i+1 to N will of course be less than S, as the numbers are non-negative.
		if (sum < S) {
			break;
		}
	}

	std::cout << equals << "\n";
}