#include <iostream>
#include <string>
#include <vector>

using namespace std;



vector<int> solution(vector<int> heights) {
	vector<int> answer;

	int n1 = 0, n2 = 0, n3 = 0, a1 = 1, a2 = 1, a3 = 3;
	for (int i = 0; i < heights.size(); i++) {
		if (heights[i] == a1) {
			n1++;
		}
		a1++;
		if (a1 == 6)
			a1 = 1;
	}

	return answer;
}

int main() {
	vector<int> v1 = { 1, 2, 3, 4, 5 };
	vector<int> v2 = { 3, 9, 9, 3, 5, 7, 2 };
	int i1 = 0;
	int i2 = 0;
	vector<int> ans = solution(v1);

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << '\n';
}