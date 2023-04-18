#define N 4
#include <vector>
#include <array>
using namespace std;

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
	

	vector<array<int, 4>>table;

	for (int i = 0; i < 10; i++) {
		array<int, 4> mynums;
		mynums[0] = i;
		for (int j = 0; j < 10; j++) {
			if (j == mynums[0]) continue;
			mynums[1] = j;
			for (int k = 0; k < 10; k++) {
				if (k == mynums[0] || k == mynums[1]) continue;
				mynums[2] = k;
				for (int l = 0; l < 10; l++) {
					if (l == mynums[0] || l == mynums[1] || l == mynums[2]) continue;
					mynums[3] = l;
					table.push_back(mynums);
				}
			}
		}
	}
	
	while (table.size() > 1) {
		if (!table.empty()) {
			int previous[4] = { table[0][0], table[0][1], table[0][2], table[0][3] };
			Result previous_return = query(previous);
			for (vector<array<int, 4>>::iterator iter = table.begin(); iter != table.end();) {
				Result nowresult = myquery(iter->data(), previous);
				if (previous_return.strike != nowresult.strike || previous_return.ball != nowresult.ball) {
					iter = table.erase(iter);
				}
				else {
					iter++;
				}
			}
		}
	}
	guess[0] = table[0][0];
	guess[1] = table[0][1];
	guess[2] = table[0][2];
	guess[3] = table[0][3];
}