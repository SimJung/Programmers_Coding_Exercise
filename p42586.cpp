#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int sz = progresses.size();
	int stat = 0;
	int upload = 0;
	
	while (stat != sz) {
		for (int i = 0; i < progresses.size(); i++) {
			progresses[i] += speeds[i];
		}

		if (progresses[0] >= 100) {
			int temp = progresses.size();
			for (int i = 0; i < temp; i++) {
				if (progresses[0] >= 100) {
					upload++;
					progresses.erase(progresses.begin());
					speeds.erase(speeds.begin());
					stat++;
				}
				else {
					break;
				}
			}
		}

		if (upload != 0) {
			answer.push_back(upload);
			upload = 0;
		}
	}

	return answer;
}

int main() {
	vector<int> heights = { 1, 94, 5};
	vector<int> heights2 = { 100, 5, 50};
	vector<int> ans = solution(heights, heights2);

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << '\n';
}