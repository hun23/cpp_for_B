#include <iostream>

using namespace std;

const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1, 0, 1,-1, 0, 1, -1, 1 };
const char board[5][5] = { {'U', 'R', 'L', 'P', 'M'},
						{'X', 'P', 'R', 'E', 'T'},
						{'G', 'I', 'A', 'E', 'T'},
						{'X', 'T', 'N', 'Z', 'Y'},
						{'X', 'O', 'Q', 'R', 'S'} };

bool inRange(int x, int y)
{
	if (x >= 5 || x < 0)
	{
		return false;
	}
	if (y >= 5 || y < 0)
	{
		return false;
	}
	return true;
}


bool hasWord(int y, int x, const string& word)
{
	if (!inRange(y, x)) return false;
	if (board[y][x] != word[0]) return false;
	if (word.size() == 1) return true;
	for (int direction = 0; direction < 8; ++direction)
	{
		int nextY = y + dy[direction], nextX = x + dx[direction];
		if (hasWord(nextY, nextX, word.substr(1))) return true;
	}
	return false;
}

int main() {
	string word = "GIRL";
	bool answer = false;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			bool temp = hasWord(i, j, word);
			if (temp)
			{
				answer = temp;
				cout << "TRUE";
				int a;
				cin >> a;
				return 0;
			}
		}
	}
	cout << "FALSE";
	int a;
	cin >> a;
	return 0;
}