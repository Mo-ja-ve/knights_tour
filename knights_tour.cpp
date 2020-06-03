/*
*  ANDRIY KALINICHENKO
*  CS3610
*  PROJECT 3
*  11/04/2019
*/
#include <iostream>
#include <iomanip>
#include "knights_tour.h"
using namespace std;

KnightsTour::KnightsTour(int board_size) {
  this->board_size = board_size ;

  this->board.resize(board_size);
  for (int i = 0; i < board_size; ++i) {
    this->board[i].resize(board_size);
  }

  for (int i = 0; i < this->board_size; i++) {
    for (int j = 0; j < this->board_size; j++){
      this->board[i][j] = 0;
    }
  }
}

void KnightsTour::print() {
  for (int i = 0; i < this->board_size; i++) {
    for (int j = 0; j < this->board_size; j++)
      cout << setw(4) << this->board[i][j] << " ";
    cout << endl;
  }
  cout << endl << endl;
}

// Function: get_moves()
//    Desc: Get the row and column indices of all valid
//          knight moves reachable from position row, col.
//          An invalid move would be one that sends the
//          knight off the edge of the board or
//          to a position that has already been visited.
//          
//    int row         - Current row position of knight.
//    int col         - Current column position of knight.
//    int row_moves[] - Array to store row indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int col_moves[] - Array to store column indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int num_moves -   Number of valid moves found. Corresponds
//                      to the sizes of row_moves and col_moves.

void KnightsTour::get_moves(int row, int col, int row_moves[], int col_moves[], int& num_moves){

  //  this is the get_moves() function - it finds all possible legal moves from the current position.

  //row - 2, col + 1
  if( ((row - 2) >= 0) && ((row - 2) <= 4)  && ((col + 1) >= 0) && ((col + 1) <= 4) && (board[row - 2][col + 1] == 0 ))
    {
      //cout<<endl<< "if 5";
      row_moves[num_moves] = row-2;
      col_moves[num_moves] = col+1;
      num_moves++;

  }
  //row -1, col + 2
  if( ((row - 1) >= 0) && ((row - 1) <= 4)  && ((col + 2) >= 0) && ((col + 2) <= 4) && (board[row - 1][col + 2] == 0 )) 
    {
      
      //cout<<endl<< "if 1";
      row_moves[num_moves] = row-1;
      col_moves[num_moves] = col+2;
      num_moves++;
      
    }

  //row + 1, col + 2
  if( ((row + 1) >= 0) && ((row + 1) <= 4)  && ((col + 2) >= 0) && ((col + 2) <= 4) && (board[row + 1][col + 2] == 0 ))
    {
      //cout<<endl<< "if 3";
      row_moves[num_moves] = row+1;
      col_moves[num_moves] = col+2;
      num_moves++;

    }

  //row + 2, col + 1
  if( ((row + 2) >= 0) && ((row + 2) <= 4)  && ((col + 1) >= 0) && ((col + 1) <= 4) && (board[row + 2][col + 1] == 0 ))
    {
      //cout<<endl<< "if 7";
      row_moves[num_moves] = row+2;
      col_moves[num_moves] = col+1;
      num_moves++;

    }

  //row + 2, col - 1
  if( ((row + 2) >= 0) && ((row + 2) <= 4)  && ((col - 1) >= 0) && ((col - 1) <= 4) && (board[row + 2][col - 1] == 0 ))
    {
      //cout<<endl<< "if 8";
      row_moves[num_moves] = row+2;
      col_moves[num_moves] = col-1;
      num_moves++;

    }

  //row + 1, col - 2
  if( ((row + 1) >= 0) && ((row + 1) <= 4)  && ((col - 2) >= 0) && ((col - 2) <= 4) && (board[row + 1][col - 2] == 0 ))
    {
      //cout<<endl<< "if 4";
      row_moves[num_moves] = row+1;
      col_moves[num_moves] = col-2;
      num_moves++;

    }

  //row - 1, col - 2
  if( ((row - 1) >= 0) && ((row - 1) <= 4)  && ((col - 2) >= 0) && ((col - 2) <= 4) && (board[row - 1][col - 2] == 0 ))
    {

      row_moves[num_moves] = row-1;
      col_moves[num_moves] = col-2;
      num_moves++;

    }

  //row - 2, col - 1
  if( ((row - 2) >= 0) && ((row - 2) <= 4)  && ((col - 1) >= 0) && ((col - 1) <= 4) && (board[row - 2][col - 1] == 0 ))
    {
      //cout<<endl<< "if 6";
      row_moves[num_moves] = row-2;
      col_moves[num_moves] = col-1;
      num_moves++;

  }

}

// Function: move() --> Recursive
//     int row        - Current row position of knight.
//     int col        - Current column position of knight.
//     int& m         - Current move id in tour.
//                      Stored in board at position
//                      row, col.
//     int& num_tours - Total number of tours found.

void KnightsTour::move(int row, int col, int& m, int& num_tours) {
  
  m++;//  we increment m, we've entered into move() which implies knight move will be found and taken thus increasing our move id
	
  int row_moves[8] = {0,0,0,0,0,0,0,0};//  we initialize our row and colom arrays
	int col_moves[8] = {0,0,0,0,0,0,0,0};

  board[row][col] = m;//  we set the new increased m to the row and col passed into our move function

  int num_moves = 0;//  we reset the move counter because we're about to find new sets of possible moves from our new current position

  get_moves(row, col, row_moves, col_moves, num_moves);//  we send our new position over to get a new list of good moves to take

  for(int i = 0; i < num_moves; i++){//  loop through the new number of possible moves found by get_moves

    move(row_moves[i],col_moves[i],m,num_tours);// we send over the for loops indexed possible move to move() thus causing recursion - once go backwards through the recursion we'll increment the  the loop and go down the alternate set of moves
    if (num_moves != 0){//  if we don't find any new possible moves we go backwards and reset each board space to 0 and decrease m each time                     
      board[row_moves[i]][col_moves[i]] = 0;
      m--;
    }
  }

  if(m == 25){// if we detect the entire board has been traveled we print the tour
    num_tours++;
    print();
    return;
  }

}

int KnightsTour::generate(int row, int col) {
  int m = 0;
  int num_tours = 0;

  move(row, col, m, num_tours);

  return num_tours;
}