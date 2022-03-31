#include <iostream>
#include "Tictactoe.h" // This file contains our class "blueprint" we must include it so we can reference the class below
#include "TestMe.xxx" 

using namespace std;


int main() {
 // TestMe testInstance;

  int row = 0;
  int col = 0;
  vector<char> playerTokens = {'X','Y'};
  int currentPlayerId = 0;

  cout << "Let's Play Tic Tac Toe...\n";

  Tictactoe myGame;

  cout << "Enter two integers from 1 to 3 to indicate where you want to place your token. For example, 1 2 means 'Row 1, Column 2'." << endl;
  cout << "Make a move!" << endl;

  myGame.printMe();

  bool valid = true;
  while(1)
  {
    cout << playerTokens[currentPlayerId] << "'s turn!" << endl;
    cin >> row >> col;
  
    valid = myGame.takeTurn(row,col,playerTokens[currentPlayerId]);

    if(myGame.isWin(playerTokens[currentPlayerId]) == true)
    {
      cout <<  "Goodbye!" <<endl;
      break;
    }

    if(myGame.isTie() == true)
    {
      cout << "The game is tie! Game over. Goodbye" << endl;
      break;
    }

    myGame.printMe();

     if (valid == true)
    {
    currentPlayerId++;
    currentPlayerId = currentPlayerId % 2; //alternating turns for 0,1,0,1...
    }
    
  }

}