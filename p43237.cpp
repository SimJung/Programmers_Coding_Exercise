#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
	long long answer = 0, right, left, mid, sum;

	sort(budgets.begin(), budgets.end());
	left = 0;
	right = M;
	sum = 0;
	for (int i = 0; i < budgets.size(); i++) {
		sum += budgets[i];
	}

	if (sum < M) {
		return budgets[budgets.size() - 1];
	}
	else {
		while (left <= right) {
			mid = (left + right) / 2;
			answer = mid;
			sum = 0;

			for (int i = 0; i < budgets.size(); i++) {
				if (budgets[i] > mid) {
					sum += mid;
				}
				else {
					sum += budgets[i];
				}
			}

			if (sum < M) {
				left = mid + 1;
			}
			else if (sum > M) {
				right = mid - 1;
				answer = right;
			}
			else {
				answer = mid;
				break;
			}
		}
	}

	return answer;
}

int main() {
	vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int i1 = 56;

	vector<int> v2 = { 110, 120, 100, 100};
	int i2 = 450;

	vector<int> v3 = { 120, 110, 140, 150 };
	int i3 = 485;

	cout << solution(v1, i1) << '\n';
	cout << solution(v2, i2) << '\n';
	cout << solution(v3, i3) << '\n';
}