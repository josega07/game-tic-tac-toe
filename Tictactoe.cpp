
#include <iostream>
#include <string>
#include "Tictactoe.h" // The Tictactoe.h file contains our class "blueprint" we must include it so we can reference the class below

Tictactoe::Tictactoe() //Default constructor 
{
  emptyToken = '-';

  for(int r=0; r<3; r++)
  {
    for(int c=0; c<3; c++)
    {
      grid[r][c] = emptyToken;
    }
  }
}

Tictactoe::Tictactoe(char _emptyToken) // Second constructor to use a personalized character
{
  emptyToken = _emptyToken;

  for(int r=0; r<3; r++)
  {
    for(int c=0; c<3; c++)
    {
      grid[r][c] = emptyToken;
    }
  }
}

Tictactoe::Tictactoe(char _emptyToken, std::vector<char> initTokens) : emptyToken(_emptyToken) //Third constructor that uses personalized character and initialize tokens that represent a game in progress.
{
   int i=0;
   for(int r=0; r<3; r++)
  {
    for(int c=0; c<3; c++)
    {
      if (i < initTokens.size())
      {
        grid[r][c] = initTokens[i++];
      }
       else grid[r][c] = emptyToken;
    }
  }
}

void Tictactoe::printMe()
{
  std::cout << "  1 2 3" << std::endl; //Print column headings
      int i=1;
      for (int r=0; r<3; r++)
      {                         //Print row headings
        for (int c=0; c<3; c++)
        {
          if(c==0) std::cout << std::to_string(i++) << " " ; 
          //if it is the first space in a new row, print a row heading
          std::cout << grid[r][c] << " ";
        }
        std::cout << std::endl;
      }
} 

bool Tictactoe::takeTurn(int rownum, int colnum, char playerToken)
{
  rownum--;
  colnum--; //To change range from 1-3 to 0-2
  if((rownum > -1 && rownum < 3 )&&(colnum > -1 && colnum < 3)) // Check if it is a valid range (0-2).
  {
    if(grid[rownum][colnum] == emptyToken) //If it is an empty token
    {
      grid[rownum][colnum] = playerToken; //Place the player token there
      return true; //Return true, it is a valid range
    }
    else std::cout << "Sorry, this location is already occupied." << std::endl;
    return false; //If there is a player token already
  }
  else std::cout << "Sorry, values are out of range." << std::endl;
   return false;
   //Above: If values are out of range, let player know and return false
}

bool Tictactoe::isWin(char playerToken)
{
  for (int e=0; e<3; e++)
  {
   if(grid[e][0]==playerToken && grid[e][1]==playerToken && grid[e][2] == playerToken){ std::cout << "Player " << playerToken << " won via row " << e+1 <<std::endl; return true;}

   //Above: Possible combinations to win via row: (00,01,02), (10,11,12), (20,21,22). Check if any of those combinations exist.

   if(grid[0][e]==playerToken && grid[1][e]==playerToken && grid[2][e]==playerToken){ std::cout << "Player " << playerToken << " won via column " << e+1 <<std::endl; return true;}

    //Above: Possible combinations to win via column: (00,10,20), (01,11,21), (02,12,22). Check if any of those combinations exist.
  }
  if(grid[0][0]==playerToken && grid[1][1]==playerToken && grid[2][2]==playerToken) {std::cout << "Player " << playerToken << " won via diagonal 1" <<std::endl; return true;} 

    //Above: Possible combinations to win via Diagonal 1 (upper left to bottom right): (00, 11, 22). Check if this combination exists.

  if(grid[2][0]==playerToken && grid[1][1]==playerToken && grid[0][2]==playerToken)  {std::cout << "Player " << playerToken << " won via diagonal 2" <<std::endl; return true;}

   //Above: Possible combinations to win via Diagonal 2 (upper right to bottom bottom left): (02, 11, 20). Check if this combination exists.

  return false; //If none of the previous combinations exists, return false, no one has won yet.
 
}

 bool Tictactoe::isTie()
 {
   for(int r=0; r<3; r++)
   {
     for (int c=0; c<3; c++)
     {
       if (grid[r][c] ==emptyToken) {return false;} //If there is at least one emptyToken, it is not tie...
     }
   }
   return true; //...Otherwise it is tie. Note that we call our isWin method first to check if the last move was a winning move.
 }    

  



/*

  WRITE YOUR OUT-OF-CLASS constructors and methods HERE for the Tic Tac Toe class

  Start each constructor with the name of your class followed by the scope resolution operator like ::, and then the class name (again)

  Start each method with its return type, followed by the name of your class followed the scope resolution operator, and then the method name

  Use the Tictactoe.h file as a guide (along with the README.md file) to help guide which constructors and methods you need to implement.

*/