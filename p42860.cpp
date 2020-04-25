#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
	int answer = 0, now_cur = 0, lessVal, rpos = 1, rcnt = 1, lpos = name.length()-1, lcnt = 1;
	string fs = "";

	for (int i = 0; i < name.length(); i++)
		fs.push_back('A');

	while (fs != name) {
		rpos = now_cur + 1;
		rcnt = 1;

		lpos = now_cur - 1;
		lcnt = 1;

		if (rpos == name.length())
			rpos = 0;

		if (lpos == -1)
			lpos = name.length() - 1;

		lessVal = ((int)name[now_cur] - (int)'A' < (int)'Z' + 1 - (int)name[now_cur]) ? (int)name[now_cur] - (int)'A' : (int)'Z' + 1 - (int)name[now_cur];
		fs[now_cur] = name[now_cur];
		answer += lessVal;

		if (fs == name) {
			break;
		}

		while (name[rpos] == fs[rpos]) {
			rpos++; rcnt++;
			if (rpos == name.length())
				rpos = 0;
		}

		while (name[lpos] == fs[lpos]) {
			lpos--; lcnt++;
			if (lpos == -1)
				lpos = name.length() - 1;
		}

		if (rcnt <= lcnt) {
			now_cur = rpos;
			answer += rcnt;
		}
		else {
			now_cur = lpos;
			answer += lcnt;
		}
		
	}

	return answer;
}

int main() {
	vector<int> v1 = { 3, 9, 9, 3, 5, 7, 2 };
	vector<int> v2 = { 3, 9, 9, 3, 5, 7, 2 };
	int i1 = 0;
	int i2 = 0;
	string s1 = "CANAANAA";
	string s2 = "AAEAA";
	cout << solution(s1) << '\n';
	cout << solution(s2) << '\n';
}