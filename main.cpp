#include <iostream>
#include "ufo_functions.hpp"
#include <math.h>
int main() {

  srand(time(NULL));

  std::string name;
  greet(name);
  std::vector<std::string> codewords = {"keyboard","home","television","programming","coding","developer","ufo","computer"};
  std::string codeword = codewords[floor(rand() % codewords.size())];
  std::string answer;
  for (int i = 0; i < codeword.length() ; i++) answer += "_";
  int misses = 0;
  std::vector<char> incorrect;
  bool guess = false;
  char letter;

  while (answer != codeword && misses < 7) {
    
    display_misses(misses);
    display_status(incorrect, answer);

    std::cout << "\n\nPlease enter your guess: ";
    std::cin >> letter;

    for (int i = 0; i < codeword.length(); i++) {

      if (letter == codeword[i]) {

        answer[i] = letter;
        guess = true;

      }

    }

    if (guess) {

      std::cout << "\nCorrect!\n";

    } else {

      std::cout << "\nIncorrect! The tractor beam pulls the person in further.\n";
      incorrect.push_back(letter);
      misses++;

    }
    //to clean terminal
    for (int i= 0; i < 25; i++) {
      std::cout << "\n";
    }

    guess = false;
    
  }
  for (int i= 0; i < 25; i++) {
      std::cout << "\n";
    }

  end_game(answer, codeword);

}