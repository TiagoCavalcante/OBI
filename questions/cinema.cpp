// Two friends are in line to buy tickets for a movie session.
// The ticket price, in dollars, is given in the table below:
//                   Age | Price
//        until 17 years |  15
//   from 18 to 59 years |  30
//      60 or more years |  20
// Input:
//   • the 1st line contains a integer, the age of the 1st friend.
//   • the 2nd line contains a integer, the age of the 2nd friend.
// Output:
//   • the total price, in dollars, to be paid for both movie tickets.
// Restrictions:
//   • 1 ≤ age ≤ 100

#include <iostream>

int getPrice(int age) {
  if (age <= 17) {
    return 15;
  } else if (age <= 59) {
    return 30;
  } else {
    return 20;
  }
}

int main() {
  int age1, age2;

  std::cin >> age1 >> age2;

  std::cout << getPrice(age1) + getPrice(age2) << "\n";
}