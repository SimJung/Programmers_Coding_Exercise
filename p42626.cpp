#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < scoville.size(); i++) {
		pq.push(scoville[i]);
	}

	while (pq.top() < K) {
		if (pq.size() < 2) {
			return -1;
		}
		int newone = pq.top();
		pq.pop();

		newone += pq.top() * 2;
		pq.pop();

		pq.push(newone);
		answer++;
	}
	return answer;
}

int main() {
	vector<int> v1 = { 1, 2, 3, 9, 10, 12 };
	vector<int> v2 = { 3, 9, 9, 3, 5, 7, 2 };
	int i1 = 7;
	int i2 = 0;
	cout << solution(v1, i1) << '\n';
}