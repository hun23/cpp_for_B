#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int>& arr, int start, int mid, int end)
{
	vector<int> temp(end - start + 1);
	int i = start, j = mid, k = 0;
	int cnt = 0;
	while (i < mid && j < end) {
		if (arr[i] <= arr[j]) temp[k++] = arr[i++];
		else temp[k++] = arr[j++];
	}
	if (i < mid) cnt = 1;
	while (i < mid) temp[k++] = arr[i++];
	while (j < end) temp[k++] = arr[j++];
	for (int i = start; i < end; i++) arr[i] = temp[i-start];
	return cnt;
}

int merge_sort(vector<int>& arr, int start, int end) {
	int cnt = 0;
	if (start + 1 < end) {
		int mid = (start + end) / 2;
		cnt += merge_sort(arr, start, mid);
		cnt += merge_sort(arr, mid, end);
		cnt += merge(arr, start, mid, end);
	}
	return cnt;
}

int main() {
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		int N, result;
		cin >> N;
		vector<int> set(N);
		for (int i = 0; i < N; i++) cin >> set[i];
		result = merge_sort(set, 0, N);
		cout << "#" << test_case << " " << set[(N / 2)] << " " << result << endl;
	}
	return 0;
}