#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



vector<int> solution(vector<int> heights) {
	vector<int> answer;
	vector<pair<int, int>> temp;

	bool two = true;
	int n1 = 0, n2 = 0, n3 = 0, a1 = 1, a2 = 5, a3 = 3;
	for (int i = 0; i < heights.size(); i++) {
		if (heights[i] == a1) {
			n1++;
		}
		a1++;
		if (a1 == 6)
			a1 = 1;
	}

	for (int i = 0; i < heights.size(); i++) {
		if (!two) {
			if (heights[i] == a2) {
				n2++;
			}
		}
		else {
			if (heights[i] == 2) {
				n2++;
			}
		}
		
		if (two) {
			a2++;
			if (a2 == 2)
				a2++;
			else if (a2 == 6) {
				a2 = 1;
			}
		}
		two = !two;
	}

	two = false;
	for (int i = 0; i < heights.size(); i++) {
		if (heights[i] == a3) {
			n3++;
		}

		if (two) {
			a3++;
			if (a3 == 4) {
				a3 = 1;
			}
			else if (a3 == 3) {
				a3 = 4;
			}
			else if (a3 == 6)
				a3 = 3;
		}
		two = !two;
	}

	temp.push_back(make_pair(n1, 1));
	temp.push_back(make_pair(n2, 2));
	temp.push_back(make_pair(n3, 3));
	sort(temp.begin(), temp.end());

	if (temp[0].first == temp[2].first)
		answer.push_back(temp[0].second);
	if (temp[1].first == temp[2].first)
		answer.push_back(temp[1].second);
	answer.push_back(temp[2].second);


	return answer;
}

int main() {
	vector<int> v1 = { 1, 3, 2, 4, 2 };
	vector<int> v2 = { 3, 9, 9, 3, 5, 7, 2 };
	int i1 = 0;
	int i2 = 0;
	vector<int> ans = solution(v1);

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << '\n';
}