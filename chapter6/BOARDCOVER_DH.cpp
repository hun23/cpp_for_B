#include <iostream>

const int dr[4][2] = { {0, -1}, {-1, -1}, {0, 1}, {1, 1} };
const int dc[4][2] = { {-1, -1}, {0, 1}, {1, 1}, {-1, 0} };

void print(int(*arr)[20])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			std::cout << arr[i][j] << ' ';
		}
		std::cout << "\n";
	}
}

bool inRange(int H, int W, int r, int c)
{
	if (H <= r || r < 0) return false;
	if (W <= c || c < 0) return false;
	return true;
}

int solve(int(*arr)[20], int H, int W, int idx)
{
	int ret = 0;
	int r = idx / W, c = idx % W;
	if (idx == H * W)
	{
		for (int r = 0; r < H; r++)
		{
			for (int c = 0; c < W; c++)
			{
				if (arr[r][c] == 0)
				{
					return 0;
				}
			}
		}
		return 1;
	}
	// if this cell is wall or filled
	if (arr[r][c] == 1)
	{
		// move to next cell
		return ret + solve(arr, H, W, idx + 1);
	}
	
	// check 4 directions
	for (int d = 0; d < 4; d++)
	{
		bool can = true;
		int nrs[3] = {r, r, r};
		int ncs[3] = {c, c, c};
		for (int i = 0; i < 2; i++)
		{
			int nr = r + dr[d][i], nc = c + dc[d][i];
			// not inRange or wall/filled
			if (!inRange(H, W, nr, nc) || arr[nr][nc] == 1)
			{
				can = false;
			}
			else
			{
				nrs[i] = nr;
				ncs[i] = nc;
			}
		}
		if (can)  // if possible
		{
			// fill
			for (int j = 0; j < 3; j++)
			{
				arr[nrs[j]][ncs[j]] = 1;
			}
			// recursion
			std::cout << "----------------------\n";
			print(arr);
			std::cout << "----------------------\n";
			ret += solve(arr, H, W, idx + 1);
			// reset
			for (int j = 0; j < 3; j++)
			{
				arr[nrs[j]][ncs[j]] = 0;
			}
			std::cout << "----------------------\n";
			print(arr);
			std::cout << "----------------------\n";
		}
	}
	return ret + solve(arr, H, W, idx + 1);
}

int main(void)
{
	int T;
	std::cin >> T;
	for (int t = 0; t < T; t++)
	{
		int H, W;
		std::cin >> H;
		std::cin >> W;

		int arr[20][20];
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				char temp;
				std::cin >> temp;
				if (temp == '#')
				{
					arr[i][j] = 1;
				}
				else
				{
					arr[i][j] = 0;
				}
			}
		}
		print(arr);
		int answer;
		answer = solve(arr, H, W, 0);
		std::cout << answer << std::endl;
	}

	system("pause");
}