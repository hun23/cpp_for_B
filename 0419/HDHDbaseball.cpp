using namespace std;
# include <iostream>
#define N 4
typedef struct {
	int strike;
	int ball;
} Result;

int myguess_c[10];

Result myquery(int myguess[], int possibles[]) {
	Result result;

	// Initialize myguess_c to all zeros
	int myguess_c[10] = { 0 };

	// Count the number of occurrences of each digit in myguess
	for (int idx = 0; idx < N; ++idx) {
		myguess_c[myguess[idx]]++;
	}

	result.strike = 0;
	result.ball = 0;

	// Iterate over the relevant indices of myguess and possibles
	for (int idx = 0; idx < N; ++idx) {
		if (myguess[idx] == possibles[idx]) {
			result.strike++;
		}
		else if (myguess_c[possibles[idx]] > 0) {
			result.ball++;
		}
	}

	return result;
}





// API
extern Result query(int guess[]);
void doUserImplementation(int guess[]) {
	// Implement a user's implementation function
	//
	// The array of guess[] is a return array that
	// is your guess for what digits[] would be.


	int table[5040][4];
	int idx = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == i) continue;
			for (int k = 0; k < 10; k++) {
				if (k == i || k == j) continue;
				for (int l = 0; l < 10; l++) {
					if (l == i || l == j || l == k) continue;
					table[idx][0] = i;
					table[idx][1] = j;
					table[idx][2] = k;
					table[idx][3] = l;
					idx++;
				}
			}
		}
	}
	while (idx > 1) {
		int* previous = table[0];
		Result previous_return = query(previous);
		cout << previous[0] << previous[1] << previous[2] << previous[3] << endl;
		cout << previous_return.ball << previous_return.strike << endl;
		for (int i = 0; i < idx; i++) {
			Result nowresult = myquery(table[i], previous);
			if (previous_return.strike != nowresult.strike || previous_return.ball != nowresult.ball) {
				for (int j = i; j < idx - 1; j++) {
					for (int k = 0; k < N; k++) {
						table[j][k] = table[j + 1][k];
					}
				}
				idx--;
			}
			else {
				
			}
		}
	}
	cout << table[0][0] << table[0][1] << table[0][2] << table[0][3] << endl;
	for (int i = 0; i < N; i++) {
		guess[i] = table[0][i];
	}

}
