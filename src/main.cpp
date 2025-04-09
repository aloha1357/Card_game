#include "poker/Poker.h"
#include "uno/Uno.h"
#include <iostream>

int main() {
  srand(static_cast<unsigned>(time(NULL)));

  std::cout << "========================\n";
  std::cout << "   1) Poker\n";
  std::cout << "   2) UNO\n";
  std::cout << "========================\n";
  int choice;
  std::cin >> choice;

  IGame *game = nullptr;
  if (choice == 1) {
    game = new Poker();
  } else {
    game = new Uno();
  }

  game->start();
  while (!game->check()) {
    game->next_turn();
    game->compare();
  }
  game->end_game();

  delete game;
  return 0;
}
