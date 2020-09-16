//SUDOKU SOLVER
/*Output Format
Print N lines containing N integers each, where jth integer int ith line denotes
the value at ith row and jth column in sudoku grid, such that all cells are filled.

Sample Input
9
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
Sample Output
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9 */
#include <iostream>
using namespace std;

int n;
int grid[9][9];
bool found=false;


bool IsSafe(int r, int c, int no){
  int count = 0;
  //Check Vetical
  for(int i=0;i<n;i++){
    if(grid[i][c]==no){count++;}
  }
  if(count>1){return false;}

  //Check Horizontal
  count = 0;
  for(int i=0;i<n;i++){
    if(grid[r][i]==no){count++;}
  }
  if(count>1){return false;}

  //Check gridbox 3x3
  count = 0;
  int cstart, rstart;
  if(c<3){cstart=0;}
  else if(c<6){cstart=3;}
  else{cstart=6;}
  if(r<3){rstart=0;}
  else if(r<6){rstart=3;}
  else{rstart=6;}

  for(int i=rstart;i<rstart+3;i++){
    for(int j=cstart;j<cstart+3;j++){
      if(grid[i][j]==no){count++;}
    }
  }
  if(count>1){return false;}

  //If not returned anything by now, its SAFE!
  return true;
}

void SudokuSolver(int row, int col){
  if(col==n){col=0;row++;}
  //Base Case / Termination
  if(row>=n){found = true; return;}

  if(grid[row][col]!=0){SudokuSolver(row,col+1);
                        return;}
  else{
  //Recursion with backtracking
  for(int i=1;i<=n;i++){
    grid[row][col]=i;
    //OutGrid();
    bool flag = IsSafe(row,col,i);
    if (flag) {SudokuSolver(row,col+1);
              if(found){return;}
               }
    grid[row][col]=0;

    }
    return;}
}

int main(){
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> grid[i][j];
    }
  }
  cout << endl;
  SudokuSolver(0,0);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout << grid[i][j] << " ";
    }
    cout << endl;
}
}
