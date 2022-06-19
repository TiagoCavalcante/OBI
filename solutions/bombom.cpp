// Input:
//   • the input contains 7 lines.
//   • each line contains the description of a card.
//   • each card is described by 2 letters, the 1st letter is the type of the
//     card (which can be "A", "J", "Q" or "K") and the 2nd letter is the suit
//     of the card (which can be "H", "S", "D" or "C").
//   • the 1st card in the game is the dominant suit.
//   • the 2nd, 3rd and 4th lines are Luana's cards.
//   • the 5th, 6th and 7th lines are Ed's cards.
// Output:
//   • the name of the player who wins the game, or "tie" if there is no winner.
// Restrictions:
//   • the cards at obey the format described above.
//   • there are NOT repeated cards.

#include <iostream>

struct {
	char type;
	char suit;
} player;

int getSum(char dominantSuit) {
	int sum = 0;

	for (int i = 0; i < 3; i++) {
		std::cin >> player.type >> player.suit;

		bool isDominant = player.suit == dominantSuit;

		if (player.type == 'A') {
			sum += isDominant ? 14 : 10;
		} else if(player.type == 'J') {
			sum += isDominant ? 15 : 11;
		} else if(player.type == 'Q') {
			sum += isDominant ? 16 : 12;
		} else { // K
			sum += isDominant ? 17 : 13;
		}
	}

	return sum;
}

int main() {
	char dominantSuit;

	// Discard the first value as the user is going to pass the suit after the
	// the type, but the type doesn't matter.
	std::cin >> dominantSuit >> dominantSuit;

	auto Luana = getSum(dominantSuit);
	auto Ed = getSum(dominantSuit);

	if (Luana > Ed) {
		std::cout << "Luana" << "\n";
	} else if (Ed > Luana) {
		std::cout << "Ed" << "\n";
	} else {
		std::cout << "tie" << "\n";
	}
}