#include <iostream>

int solve(bool(*areFriends)[10], int *mates, int n, int now)
{
	std::cout << "now: " << now << std::endl;
	for (int k = 0; k < n; k++)
	{
		std::cout << "M" << k << " :" << mates[k] << std::endl;
	}
	std::cout << "END\n";
	if (now == n)
	{
		for (int i = 0; i < n; i++)
		{
			if (mates[i] == -1)
			{
				return 0;
			}
		}
		return 1;
	}

	int ret = 0;
	// check all friends
	for (int i = now + 1; i < n; i++)
	{
		if (areFriends[now][i])
		{
			if (mates[now] == -1 && mates[i] == -1)
			{
				mates[now] = i;
				mates[i] = now;
				std::cout << "NOW & I: " << now << " " << i << std::endl;
				ret += solve(areFriends, mates, n, now + 1);
				mates[now] = -1;
				mates[i] = -1;
			}
		}
	}
	return ret + solve(areFriends, mates, n, now + 1);
}

void print(bool(*areFriends)[10], int *mates)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << areFriends[i][j] << ' ';
		}
		std::cout << "\n";
	}
}

int main(void)
{
	int T;
	std::cin >> T;
	for (int t = 0; t < T; t++)
	{
		int n, m;
		std::cin >> n;
		std::cin >> m;

		bool areFriends[10][10];
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				areFriends[i][j] = false;
			}
		}

		int mates[10];
		for (int i = 0; i < 10; i++)
		{
			mates[i] = -1;
		}
		for (int i = 0; i < m; i++)
		{
			int a, b;
			std::cin >> a >> b;
			areFriends[a][b] = true;
			areFriends[b][a] = true;
		}
		int answer = solve(areFriends, mates, n, 0);
		std::cout << "START: " << t << std::endl;
		std::cout << "ANSWER: " << answer << std::endl;
	}
	system("pause");
}