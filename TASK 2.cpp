#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

vector<vector<char>> matrix(3, vector<char>(3));

void init_matrix(void) {
  int i, j;
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++) matrix[i][j] = ' ';
}

void display(void) {
  for (int i = 0; i < 3; i++) {
    cout << " " << matrix[i][0] << " | " << matrix[i][1] << " | " << matrix[i][2] << " ";
    if (i != 2) {
      cout << "\n---|---|---\n";
    }
  }
}
bool player_chance(void) {
  int a, b;
  cout << endl<<"Enter coordinates of your move: " << endl;
  cin >> a >> b;
  a--;
  b--;
  if (matrix[a][b] == 'X' || matrix[a][b] == 'O') {
    cout << "Invalid input" << endl;
    return false; // Return false to indicate invalid input
  } else {
    matrix[a][b] = 'O';
    return true; // Return true to indicate successful move
  }
}
char win(void) {
  for (int i = 0; i < 3; i++) {
    if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] && matrix[i][2] != ' ' && matrix[i][0]=='O') {
      return matrix[i][0];
    }
  }
  for (int i = 0; i < 3; i++) {
    if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i] && matrix[2][i] !=' '&& matrix[0][i]=='O') {
      return matrix[i][0];
    }
  }
  if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[2][2] != ' ' && matrix[0][0]=='O') {
    return matrix[0][0];
  }
  for (int i = 0; i < 3; i++) {
    if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] && matrix[i][2] != ' ' && matrix[i][0]=='X') {
      return matrix[i][0];
    }
  }
  for (int i = 0; i < 3; i++) {
    if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i] && matrix[2][i] !=' '&& matrix[0][i]=='X') {
      return matrix[0][i];
    }
  }
  if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[2][2] != ' ' && matrix[0][0]=='X') {
    return matrix[0][0];
  }

  return ' ';
}
bool win_move(char m) {
  for (int i = 0; i < 3; i++) {
    if (matrix[i][0] == m && matrix[i][1] == m && matrix[i][2] == m) {
      return true;
    }
  }
  for (int i = 0; i < 3; i++) {
    if (matrix[0][i] == m && matrix[1][i] == m && matrix[2][i] == m) {
      return true;
    }
  }
  if (matrix[0][0] == m && matrix[1][1] == m && matrix[2][2] == m) {
    return true;
  }
  return false;
}

int minimax(vector<vector<char>>& matrix, int depth, bool maximize) {
  if (win_move('X')) {
    return 1000 - depth;
  } else if (win_move('O')) {
    return -1000 + depth;
  } else if (depth == 9) {
    return 0; // It's a draw
  }

  int bestScore = maximize ? -10000 : 10000;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (matrix[i][j] == ' ') {
        matrix[i][j] = maximize ? 'X' : 'O';

        int score = minimax(matrix, depth + 1, !maximize);

        if (maximize) {
          bestScore = max(bestScore, score);
        } else {
          bestScore = min(bestScore, score);
        }

        matrix[i][j] = ' '; // Reset the cell
      }
    }
  }

  return bestScore;
}

void computer_chance(void) {
  int bestScore = -1000;
  int bestMoveX = -1;
  int bestMoveY = -1;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (matrix[i][j] == ' ') {
        matrix[i][j] = 'X';

        int score = minimax(matrix, 0, false);

        matrix[i][j] = ' '; // Reset the cell

        if (score > bestScore) {
          bestScore = score;
          bestMoveX = i;
          bestMoveY = j;
        }
      }
    }
  }

  matrix[bestMoveX][bestMoveY] = 'X';
  display();
}


int main()
 {
  init_matrix();
  display();
  char complete=' ';
  do
  {

   player_chance();
  complete=win();
   if(complete!=' ')
   {
       break;
   }
   computer_chance();
   complete=win();
  }while(complete==' ');
  if(complete=='X')
  {
      display();
      cout<<endl<<"AI won!"<<endl;
  }
   else if(complete=='O'){
        display();
    cout<<endl<<"You won!"<<endl;
  }
  else
  {
      cout<<"It's a draw!"<<endl;
  }
}

