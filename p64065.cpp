#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isDigit(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (!isdigit(s[i]))
			return false;
	}

	return true;
}

vector<int> v[501];
bool visit[100001];
vector<int> solution(string s) {
	vector<int> answer;
	vector<int> temp;
	int tuple_sz = 0, sz = 0; 

	for (int i = 2; i < s.length() - 1; i++) {
		if (isdigit(s[i])) {
			string co = s.substr(i, s.find(',', i) - i);
			string bl = s.substr(i, s.find('}', i) - i);
			sz++;
			if (isDigit(co)) {
				temp.push_back(atoi(co.c_str()));
				i += co.length() - 1;
			}
			else {
				temp.push_back(atoi(bl.c_str()));
				i += bl.length() - 1;
			}
		}
		else if (s[i] == '}') {
			tuple_sz = tuple_sz < sz ? sz : tuple_sz;
			v[sz] = temp;
			temp.clear();
			sz = 0;
		}
	}

	answer.push_back(v[1][0]);
	visit[answer[0]] = true;
	for (int i = 2; i <= tuple_sz; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (!visit[v[i][j]]) {
				visit[v[i][j]] = true;
				answer.push_back( v[i][j] );
				break;
			}
		}
	}

	return answer;
}

int main() {
	vector<int> v1 = { 3, 9, 9, 3, 5, 7, 2 };
	vector<int> v2 = { 3, 9, 9, 3, 5, 7, 2 };
	int i1 = 0;
	int i2 = 0;
	string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
	vector<int> ans = solution(s);

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << '\n';
}