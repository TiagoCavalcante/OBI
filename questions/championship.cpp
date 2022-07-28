#include <iostream>

int main() {
  int kung, lu, playerNumber;

  for (auto i = 0; i < 16; i++) {
    std::cin >> playerNumber;

    if (playerNumber == 1) {
      kung = i;
    } else if (playerNumber == 9) {
      lu = i;
    }
  }

  // Ensure kung > lu.
  if (lu > kung) {
    std::swap(lu, kung);
  }

  // This is a tree for 8 players:
  //            ⬤
  //           ╱ ╲
  //          ╱   ╲
  //         ╱     ╲
  //        ╱       ╲
  //       ⬤         ⬤
  //      ╱ ╲       ╱ ╲
  //     ⬤   ⬤     ⬤   ⬤
  //    ╱╲   ╱╲   ╱╲   ╱╲
  //   ⬤  ⬤ ⬤  ⬤ ⬤  ⬤ ⬤  ⬤
  // If 2 players are in the same
  // "cluster" of the last line then they'll
  // play against each other in the 1st round.
  // The same logic is applied to the other "clusters".

  // lu - lu % 2 is the begin of the "cluster" with size 2.
  // lu - lu % 2 + 1 is the end of ther "cluster" with size 2.
  if (lu - lu % 2 <= kung && kung <= lu - lu % 2 + 1) {
    std::cout << "final 16" << "\n";
  } else if (lu - lu % 4 <= kung && kung <= lu - lu % 4 + 3) {
    std::cout << "final 8" << "\n";
  } else if (lu - lu % 8 <= kung && kung <= lu - lu % 8 + 7) {
    std::cout << "final 4" << "\n";
  } else {
    std::cout << "final 2" << "\n";
  }
}