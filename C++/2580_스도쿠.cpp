#include <iostream>
using namespace std;

bool check_square[10][10];
bool check_row[10][10];
bool check_column[10][10];
int sudoku[10][10];

int getSquare(int row, int col) {
	return (row / 3) * 3 + (col / 3);
}

void input() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];

			if (sudoku[i][j] != 0) {
				check_row[i][sudoku[i][j]] = true;
				check_column[j][sudoku[i][j]] = true;
				check_square[getSquare(i, j)][sudoku[i][j]] = true;
			}
		}
	}
}
bool Sudoku(int n) {
	if (n == 81) {
		return true;
	}

	int x = n / 9; 
	int y = n % 9;

	if (sudoku[x][y] != 0) {
		return Sudoku(n + 1);
	}
	else {
		for (int i =1; i <= 9; i++) {
			if (!check_row[x][i] && !check_column[y][i] && !check_square[getSquare(x, y)][i]) {
				check_row[x][i] = true;
				check_column[y][i] = true;
				check_square[getSquare(x, y)][i] = true;
				sudoku[x][y] = i;
				if (Sudoku(n + 1)) {
					return true;
				}
				check_row[x][i] = false;
				check_column[y][i] = false;
				check_square[getSquare(x, y)][i] = false;
				sudoku[x][y] = 0;
				
			}
		}
	}
	return false;
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	input();
	Sudoku(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sudoku[i][j] << " ";
		}
		cout << "\n";
	}
	
}