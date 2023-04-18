#define N 4

typedef struct {

	int strike;

	int ball;

} Result;

typedef struct {
	int strike;
	int ball;
	int num;
} QueryResult;

int query_result_length = 0;

// API

extern Result query(int guess[]);
bool go(int num, QueryResult *qr) {
	for (int i = 0; i < query_result_length; i++) {
	}
	return false;
}

int pow(int n) {
	int ret = 1;
	for (int i = 0; i < n; i++) {
		ret *= 10;
	}
	return ret;
}

void update_query_results(int num, Result ret, QueryResult *qrs) {
	qrs[query_result_length].strike = ret.strike;
	qrs[query_result_length].ball = ret.ball;
	qrs[query_result_length].num = num;
	query_result_length += 1;
}

int nth_digit(int num, int nth) {
	int ret = 0;
	int i = 0;
	int temp[10] = { 0,0,0,0,0,0,0,0,0,0 };
	while (num != 0) {
		temp[i] = num % 10;
		num /= 10;
		i++;
	}
	ret = temp[N - 1 - nth];
	return ret;
}


void doUserImplementation(int guess[]) {
	// variables
	int digits[10];
	Result result;
	QueryResult *QueryResults = new QueryResult[100];

	// first query 0123
	for (int i = 0; i < N; i++) {
		guess[i] = i;
	}
	result = query(guess);
	update_query_results(123, result, QueryResults);

	// for all nums
	for (int num = 0; num < pow(N); num++) {  
		// initialize
		for (int i = 0; i < 10; i++) {
			digits[i] = 0;
		}
		for (int i = 0; i < N; i++) {
			int rem = nth_digit(num, i);
			guess[i] = rem;
		}

		// check duplicated
		bool duplicated = false;
		for (int i = 0; i < N; i++) {
			digits[guess[i]] += 1;
			if (digits[guess[i]] > 1) {
				duplicated = true;
				break;
			}
		}
		if (duplicated) continue;
		if (go(num, QueryResults)) {
			result = query(guess);
			update_query_results(num, result, QueryResults);
		}
	}
}