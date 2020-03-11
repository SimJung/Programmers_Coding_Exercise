#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;


	return answer;
}

int main() {
	vector<int> v1 = { 3, 9, 9, 3, 5, 7, 2 };
	vector<int> v2 = { 3, 9, 9, 3, 5, 7, 2 };
	int i1 = 0;
	int i2 = 0;
	vector<int> ans = solution(v1);

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << '\n';

	cout << solution(v1) << '\n';
}