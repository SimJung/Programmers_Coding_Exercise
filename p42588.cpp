#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;

	for (int i = 0; i < heights.size(); i++)
		answer.push_back(0);

	for (int i = heights.size() - 1; i >= 1; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (heights[i] < heights[j]) {
				answer[i] = j+1;
				break;
			}
		}
	}

	return answer;
}

int main() {
	vector<int> heights = {3, 9, 9, 3, 5, 7, 2 };
	vector<int> ans = solution(heights);

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << '\n';
}