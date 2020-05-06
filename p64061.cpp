#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> s[31];
stack<int> temp;
int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;

	for (int i = board.size()-1; i >= 0; i--) {
		for (int j = 0; j < board[i].size(); j++) {
			if(board[i][j])
				s[j+1].push(board[i][j]);
		}
	}

	for (int i = 0; i < moves.size(); i++) {
		int doll;
		if (!s[moves[i]].empty()) {
			doll = s[moves[i]].top();
			s[moves[i]].pop();
			if (!temp.empty() && temp.top() == doll) {
				temp.pop();
				answer+=2;
			}
			else
				temp.push(doll);
		}
	}

	return answer;
}

int main() {
	vector<vector<int>> v1 = { {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
	vector<int> v2 = { 1,5,3,5,1,2,1,4 };
	int i1 = 0;
	int i2 = 0;
	cout << solution(v1, v2) << '\n';
}