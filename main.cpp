/*                                                          
        * NAME: Sean Cuenco

        * Description: In this program we are solving the eight queens
        problem. We are using backtracking to solve the problem. 
        
        An initial queen will be placed in the board, and then recursion
        must be used to populate the board with seven other queens
        for a total of eight queens that are not threatening each other.

        Yeah so backtracking with recursion lol. 
        It's all magic, the gathering.

        * Input: The user simply inputs the initial coordinates of
        the first queen

        * Output: The program uses recursion to place the 7 other queens
        for a chess board with a total of 8 queens and prints that board
*/

#include <iostream>
using namespace std;

// function prototypes
void printQueensBoard(int queensBoard[8][8]);
bool placeEightQueens(int queensBoard[8][8], int yAxis);
bool isQueenSafe(int queensBoard[8][8], int yAxis, int xAxis);

int main()
{

  // eight queens problem chess board as array
  int queensBoard[8][8] = {0};

  // prompt the user for the first queen
  // variables to store user input
  int xAxis;
  int yAxis;

  // message prompting user and outputs the choice
  cout << "Enter initial coordinates of the first queen: ";
  // cin >> yAxis >> xAxis;
  yAxis = 3;
  xAxis = 4;
  cout << yAxis << " " << xAxis << endl << endl;

  // add the initial queen to the board
  queensBoard[yAxis-1][xAxis-1] = 1;

  // recursively adds queens as a boolean
  if(placeEightQueens(queensBoard, 0) == true)
  {
  //prints the board
  printQueensBoard(queensBoard);
  } else {
    // this shouldn't actually print
    cout << "No solution";
  }


  return 0;
}

// recursive function to place the queens on the board
// the y axis with the user inputted queen has to be accounted for
/*
the inputs are the queensBoard which will have one queen already inputted
and the yAxis to start the recursive function from which is always zero
to make sure that all 8 xAxis ( - ) direction has a queen
it outputs true once the board is populated
which for the purposes of this assignment is always true
*/
bool placeEightQueens(int queensBoard[8][8], int yAxis)
{

    // base case hits if each X-axis has a queen and the 9th
    // y-axis is reached meaning 8 queens is achieved
    if (yAxis == 8) 
    { return true; }

    // traversal that checks the user inputted queen
    // user inputted queen must remain on the board and can't be 
    // backtracked, so it automatically calls the next recursion call
    // it's similar to the general recursion call minus the backtrack
    for(int i = 0; i < 8; i++)
    {
        if(queensBoard[yAxis][i] == 1)
        {
            if(placeEightQueens(queensBoard, yAxis + 1) == true)
            {
                return true;
            }
        }
    }

    // general recursion call to place queens
    for(int i = 0; i < 8; i++)
    {
        // nested if statement to go on to different decision trees
        // or save points I guess
        // traverse the x Axis on the current y Axis position
        if(isQueenSafe(queensBoard, yAxis, i) == true)
        {
            // first places a queen on the board and calls recursion
            // to the next y-Axis repeating the process
            queensBoard[yAxis][i] = 1;
            if(placeEightQueens(queensBoard, yAxis + 1) == true)
            {
                // if recursion keeps being a success a true is going
                // to be returned from the deepest layer around 7ish
                // of recursion
                return true;
            } else {
                // backtrack
                // if a layer of recursion that's not the final is hit
                // we would have to back track and remove the queen
                queensBoard[yAxis][i] = 0;
            }
        }
        // the for loop continues its run and it will try to place
        // another queen towards the right of the queen that failed
        // the eightQueens problem
        // if it keeps failing then it will keep going
        //  higher on the board
    }


    // return false if traversal doesn't work
    // this accounts for dead ends and cuts up that decision tree
    // this would happen after a back track and would signal the
    // function to go up higher on the y-Axis checking previous 
    // x-Axises that weren't checked
    // not all x-Axises have to be checked to reach the base case
    // that's why some of the boards don't have pieces at the right
    // most position on the 0th y-axis
    return false;


}

// boolean function to check if the queen is safe to be used
// in the recursive function call for placing the queens
/*
the parameters are the board, and the spot we want to check 
denoted by the y and x axis
all directions are checked | - \ /
each output scenario is a success so each x axis row from top to bottom
will have a queen placed on it
 */ 
bool isQueenSafe(int queensBoard[8][8], int yAxis, int xAxis)
{

// the queen must not be threatened from anywhere
// if the queen is threatened the program exits with a return false
// right away

  // check the yAxis
  // the xAxis is static and only the top and bottom positions
  // are checked for marks
  for(int i = 0; i < 8; i++)
    {
      if(queensBoard[i][xAxis] == 1)
      {
        return false;
      }
    }

  // check the xAxis
  // the yAxis is static and only the left and right positions
  // are checked for marks
  for(int i = 0; i < 8; i++)
    {
      if(queensBoard[yAxis][i] == 1)
      {
        return false;
      }
    }

    // check the diagonals NW NE SW SE
    // code is inspired by code from the CS Lab

    // row or r is yAxis ( | ), column or c is xAxis ( - )

    // - + is NE direction
    for(int r = yAxis, c = xAxis; r>=0 && c < 8; r--,c++)
    {
        if(queensBoard[r][c] == 1) { return false; }
    }

    // - - is NW direction
    for(int r = yAxis, c = xAxis; r>=0 && c >=0; r--,c--)
    {
        if(queensBoard[r][c] == 1) { return false; }
    }

    // + - is SW direction
    for(int r = yAxis, c = xAxis; r<8 && c >=0; r++,c--)
    {
        if(queensBoard[r][c] == 1) { return false; }
    }

    // + + is SE is direction
    for(int r = yAxis, c = xAxis; r<8 && c<8; r++,c++)
    {
        if(queensBoard[r][c] == 1) { return false; }
    }

  return true;
}

// Display Function: to display the board
void printQueensBoard(int queensBoard[8][8])
{
  // outputs the header
  cout << "   1  2  3  4  5  6  7  8" << endl;

  // nested for loop to output the entire board
  for(int i = 0; i < 8; i++)
    {
      cout << i+1 << "  ";
      for(int j = 0; j < 8; j++)
        {
          // if the current board spot has 1, there is a queen
          // else statement or 0, there is no queen '-' is outputted
          if(queensBoard[i][j] == 1)
          {
          cout << "Q";
          } else {
            cout << "-";
          }
          // output the white spaces
          if(j < 7)
          {
            cout << "  ";
          } else {
            cout << endl;
          }

        }

    }

};

