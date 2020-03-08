#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
bool solution(vector<string> phone_book) {
	bool answer = true;
	int minn;

	unordered_map<string, vector<string>> m;

	minn = phone_book[0].length();
	for (int i = 1; i < phone_book.size(); i++) {
		if (minn > phone_book[i].length()) {
			minn = phone_book[i].length();
		}
	}

	string temp, longer, shorter;
	for (int i = 0; i < phone_book.size(); i++) {
		temp = phone_book[i].substr(0, minn);
		if(m[temp].empty())
			m[temp].push_back(phone_book[i]);
		else {
			for (int j = 0; j < m[temp].size(); j++) {
				if (m[temp][j].length() < phone_book[i].length())
				{
					longer = phone_book[i];
					shorter = m[temp][j];
				}
				else {
					longer = m[temp][j];
					shorter = phone_book[i];
				}
				if (shorter == longer.substr(0, shorter.length()))
					return false;
			}
		}
	}

	return answer;
}

int main() {
	vector<string> v1, v2, v3;
	vector<int> ans;
	int case_num = 3;

		v1 = {"123", "1235" , "567", "88"};

		cout << solution(v1) << '\n';
	
}