#include<iostream>
#include<cstring>

using namespace std;

int n, m;
int isFriend[10][10];
int paired[10];

int paring() {
	int idx = -1;
	for (int i = 0; i < n; i++) {
		if (paired[i] == -1) {
			idx = i;
			break;
		}
	}
	if (idx == -1) return 1;

	int res = 0;
	for (int i = idx + 1; i < n; i++) {
		if (paired[i] == -1 && isFriend[idx][i] == 1) {
			paired[idx] = 1;
			paired[i] = 1;
			res += paring();
			paired[idx] = -1;
			paired[i] = -1;
		}
	}

	return res;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		cin >> n >> m;

		memset(isFriend, -1, sizeof(isFriend));
		memset(paired, -1, sizeof(paired));

		for (int i = 0; i < m; i++) {
			int y, x;
			cin >> y >> x;
			isFriend[y][x] = 1;
			isFriend[x][y] = 1;
		}

		cout << paring() << endl;
	}

	return 0;
}