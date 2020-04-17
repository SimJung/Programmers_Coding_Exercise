#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
	int answer = 0;
	for (int i = 111; i < 1000; i++) {
		string istr = to_string(i);
		string num;
		bool isOk = true, iscont = false;

		bool visit[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		for (int j = 0; j < 3; j++) {
			if(!visit[istr[j]-'0'])
				visit[istr[j] - '0'] = 1;
			else
			{
				iscont = true;
				break;
			}
			if (istr[j] == '0') {
				iscont = true;
				break;
			}
		}

		if (iscont)
			continue;
		
		for (int j = 0; j < baseball.size(); j++) {
			if (!isOk)
				continue;

			int strike = 0, ball = 0;
			bool isUsed[3] = { false, false, false };
			num = to_string(baseball[j][0]);

			for (int k = 0; k < 3; k++) {
				if (istr[k] == num[k]) {
					strike++;
					isUsed[k] = true;
				}
			}

			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					if (k == l)
						continue;

					if (istr[k] == num[l] && !isUsed[l]) {
						ball++;
						isUsed[l] = true;
					}
				}
			}
			
			if (strike != baseball[j][1] || ball != baseball[j][2]) {
				isOk = false;
			}
		}

		if (isOk)
			answer++;
	}
	return answer;
}

int main() {
	vector<vector<int>> v1 = { {123, 1, 1}, {356, 1, 0}, {327, 2, 0}, {489, 0, 1} };
	cout << solution(v1) << '\n';
}