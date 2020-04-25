#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end());

	for (int i = 0; i < citations.size(); i++) {
		if (citations.size() - i >= citations[i]) {
			answer = i + 1;
		}
		else {
			break;
		}
	}

	return answer;
}

int main() {
	vector<int> v1 = { 4, 3, 3, 3, 3 };
	vector<int> v2 = { 3, 9, 9, 3, 5, 7, 2 };
	int i1 = 0;
	int i2 = 0;
	cout << solution(v1) << '\n';
}