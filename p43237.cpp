#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = 0;

	sort(budgets.begin(), budgets.end());
	int everage = M / 4, sum=0, idx = 0;
	auto j = upper_bound(budgets.begin(), budgets.end(), everage);
	for (auto i = budgets.begin(); i != j; i++) {
		sum += everage - *i;
		idx++;
	}

	if (budgets.size() - idx)
		answer = everage + sum / (budgets.size() - idx);
	else
		answer = everage;
	return answer;
}

int main() {
	vector<int> v1 = { 121, 110, 140, 150 };
	int i1 = 485;

	cout << solution(v1, i1) << '\n';
}