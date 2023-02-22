#include <iostream>
#include <vector>
#include "hangman.h"
using namespace std;
int main()
{
  greet();

  string codeword = "Sternocleidomastoidian";
  string answer = "______________";
  int misses = 0;
  vector<char> incorrect;
  bool guess = false;
  char letter;


  while(answer!=codeword && misses < 7)
  {
    display_misses(misses);
    display_status(incorrect, answer);

    cout<<"\n\nVa rogy sa introduceti litera  estimarea dumneavoastra: ";
    cin>>letter;

    for(int i = 0; i<codeword.length(); i++)
    {
      if(letter==codeword[i])
      {
        answer[i] = letter;
        guess = true;
      }
    }
    if(guess)
    {
      cout<<"\nCorect!Bravo!\n";
    }
    else
    {
      cout<<"\nIncorect!Mai incearca! O alta parte a persoanei a fost desenata.\n";
      incorrect.push_back(letter);
      misses++;
    }
    guess = false;
  }

  end_game(answer, codeword);
  return 0;
}
