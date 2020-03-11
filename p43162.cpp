#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	queue<int> q;
	vector<bool> visit;
	int t;

	for (int i = 0; i < computers.size(); i++) {
		visit.push_back(0);
	}
	for (int i = 0; i < computers.size(); i++) {
		if (!visit[i])
		{
			q.push(i);
			visit[i] = 1;
			answer++;
			while (!q.empty()) {
				t = q.front();
				q.pop();
				for (int j = 0; j < computers[t].size(); j++) {
					if (!visit[j] && computers[t][j]) {
						q.push(j);
						visit[j] = 1;
					}
						
				}
			}
		}
		
	}
	

	return answer;
}

int main() {
	vector<vector<int>> heights = { {1, 1, 0}, {1, 1, 0}, {0, 0, 1} };
	int n = 3;

	cout << solution(n, heights) << '\n';
}