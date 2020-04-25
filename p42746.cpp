#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
	int longlen, aindex = 0, bindex = 0;
	if (a.length() > b.length()) {
		longlen = a.length();
	}
	else {
		longlen = b.length();
	}

	for (int i = 0; i < longlen; i++) {
		if (a[aindex] < b[bindex]) {
			return false;
		}
		else if (a[aindex] > b[bindex]) {
			return true;
		}

		aindex++;
		bindex++;

		if (aindex == a.length())
			aindex = 0;

		if (bindex == b.length())
			bindex = 0;
	}
	
	return false;
}

string solution(vector<int> numbers) {
	string answer = "";
	bool allZero = true;
	vector<string> vs;

	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] != 0) {
			allZero = false;
		}
		vs.push_back(to_string(numbers[i]));
	}

	sort(vs.begin(), vs.end(), cmp);

	for (int i = 0; i < vs.size(); i++)
		answer += vs[i];


	if (allZero)
		return "0";

	return answer;
}

int main() {
	vector<int> v1 = { 6, 10, 2 };
	vector<int> v2 = {3, 30, 34, 5, 9 };
	vector<int> v3 = { 21, 212 };
	vector<int> v4 = { 12, 121 };
	int i1 = 0;
	int i2 = 0;

	cout << solution(v1) << '\n';
	cout << solution(v2) << '\n';
	cout << solution(v3) << '\n';
	cout << solution(v4) << '\n';
}