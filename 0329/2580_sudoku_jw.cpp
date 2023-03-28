#include <iostream>

using namespace std;

int board[9][9] = {};
int check[81] = {};
bool answer_flag = false;


bool square_valid(int x, int y) {
	int r = 0;
	int c = 0;
	if (y >= 6) r = 6;
	else if (y >= 3) r = 3;
	if (x >= 6) c = 6;
	else if (x >= 3) c = 3;
	for (int dr = 0; dr < 3; dr++) {
		for (int dc = 0; dc < 3; dc++) {
			if (board[r + dr][c + dc] == board[y][x]) {
				if (r + dr != y || c + dc != x) return false;
			}
		}
	}
	return true;
}

bool validate(int x, int y) {
	for (int i = 0; i < 9; i++) {
		if (i != x && board[y][i] == board[y][x]) return false;
		if (i != y && board[i][x] == board[y][x]) return false;
	}
	if (!square_valid(x, y)) return false;
	return true;
}


int sudoku(int idx) {
	if (idx == 0) {
		answer_flag = true;
		return 1;
	}
	int x = check[idx - 1] % 9;
	int y = check[idx - 1] / 9;
	for (int j = 1; j < 10; j++) {
		board[y][x] = j;
		if (validate(x, y)) sudoku(idx - 1);
		if (answer_flag) return 1;
		board[y][x] = 0;
	}
	return 0;
}

int main() {
	int idx = 0;
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cin >> board[y][x];
			if (!board[y][x]) check[idx++] = x + y * 9;
		}
	}

	sudoku(idx);

	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cout << board[y][x] << " ";
		}
		cout << endl;
	}
	return 0;
}