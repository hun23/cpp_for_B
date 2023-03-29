#include <iostream>

using namespace std;
int box[100][100][100] = {};
int x[10000] = {};
int y[10000] = {};
int z[10000] = {};
int tx[10000] = {};
int ty[10000] = {};
int tz[10000] = {};
int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };
int M, N, H;

int search(int mx_idx, int cnt) {
	int new_idx = 0;
	for (int i = 0; i < mx_idx; i++) {
		for (int j = 0; j < 6; j++) {
			if (x[i] + dx[j] >= 0 && x[i] + dx[j] < M) {
				if (y[i] + dy[j] >= 0 && y[i] + dy[j] < N) {
					if (z[i] + dz[j] >= 0 && z[i] + dz[j] < H) {
						if (box[z[i] + dz[j]][y[i] + dy[j]][x[i] + dx[j]] == 0) {
							box[z[i] + dz[j]][y[i] + dy[j]][x[i] + dx[j]] = 1;
							tx[new_idx] = x[i] + dx[j];
							ty[new_idx] = y[i] + dy[j];
							tz[new_idx++] = z[i] + dz[j];
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < new_idx; i++) {
		x[i] = tx[i];
		y[i] = ty[i];
		z[i] = tz[i];
	}
	if (new_idx)
		cnt = search(new_idx, cnt+1);
	return cnt;
}

int main() {
	cin >> M >> N >> H;
	int p = 0;
	for (int k = 0; k < H; k++) {
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < M; i++) {
				cin >> box[k][j][i];
				if (box[k][j][i] == 1) {
					x[p] = i;
					y[p] = j;
					z[p++] = k;
				}
			}
		}
	}
	int days;
	days = search(p, 0);
	for (int k = 0; k < H; k++) {
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < M; i++) {
				if (box[k][j][i] == 0) {
					days = -1;
				}
			}
		}
	}
	cout << days;
	return 0;
}