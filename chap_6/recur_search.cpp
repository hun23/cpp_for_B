#include <iostream>
#include <string>

using namespace std;

const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1, 0, 1, -1, 0 ,1, -1 ,1 };

char board[5][5];

bool inRange(int y, int x) {
	if (y >= 0 && y < 5 && x >= 0 && x < 5) return true;
	return false;
}

bool hasWord(int y, int x, const string& word) {
	if (!inRange(y, x)) return false;
	if (board[y][x] != word[0]) return false;
	if (word.size() == 1) return true;
	for (int direction = 0; direction < 8; ++direction) {
		int nY = y + dy[direction], nX = x + dx[direction];
		if (hasWord(nY, nX, word.substr(1)))
			return true;
	}
	return false;
}


int main() {
	bool result = false;
	string word;
	cin >> word;
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[j][i];
		}
	}
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (hasWord(j, i, word))
				result = true;
		}
	}
	cout << result << endl;
}
