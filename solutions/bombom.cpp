// Bonbom is a card game for 2 people, played with only 16 cards: Ace, Jack,
// Queen and King, in the 4 suits (Hearts, Spades, Diamonds and Clubs).
// Each card has a value, which depends on the figure and suit.
// Each game, the cards are shuffled and placed in a pile. Initially a letter
// from pile is flipped and shown to both players: the suit of this card is
// called the dominant suit of departure.
// Then each player receives 3 cards from the pile. The player who has the
// cards whose sum of values is greater.
// The value of the cards is given in the table below:
//   Figure | Non-dominant suit | Dominant suit
//    Ace   |         10        |      14
//    Jack  |         11        |      15
//    Queen |         12        |      16
//    King  |         13        |      17
// Luana and Ed are playing Bombom and want your help to determine the winner
// of the match, or if there is a tie.
// Input:
//   • the input contains 7 lines.
//   • each line contains the description of a card.
//   • each card is described by 2 letters, the 1st letter is the figure of the
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
  char figure;
  char suit;
} player;

int getSum(char dominantSuit) {
  int sum = 0;

  for (int i = 0; i < 3; i++) {
    std::cin >> player.figure >> player.suit;

    bool isDominant = player.suit == dominantSuit;

    if (player.figure == 'A') {
      sum += isDominant ? 14 : 10;
    } else if (player.figure == 'J') {
      sum += isDominant ? 15 : 11;
    } else if (player.figure == 'Q') {
      sum += isDominant ? 16 : 12;
    } else {  // K
      sum += isDominant ? 17 : 13;
    }
  }

  return sum;
}

int main() {
  char dominantSuit;

  // Discard the first value as the user is going to pass the suit after the
  // the figure, but the figure doesn't matter.
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