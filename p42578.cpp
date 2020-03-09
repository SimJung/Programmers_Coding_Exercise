#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

queue<int> qv;
queue<int> ql;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	for (int i = 0; i < priorities.size(); i++) {
		ql.push(i);
		qv.push(priorities[i]);
	}
	sort(priorities.begin(), priorities.end());

	while (!qv.empty()) {
		if (qv.front() == *(priorities.end()-1)) {
			answer++;
			if (location == ql.front())
				return answer;
			qv.pop();
			ql.pop();
			priorities.erase(priorities.end() - 1);
		}
		else {
			qv.push(qv.front());
			qv.pop();
			ql.push(ql.front());
			ql.pop();
		}
	}

	return answer;
}

int main() {
	vector<int> v1 = { 1, 1, 9, 1, 1, 1 };
	int l = 0;

	cout << solution(v1, l) << '\n';
}