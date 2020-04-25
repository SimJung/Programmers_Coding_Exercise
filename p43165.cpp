#include <iostream>
#include <string>
#include <vector>

using namespace std;
int answer = 0;
vector<int> vn;
int ta;

void func(int now_num, int sum) {
	if (now_num == vn.size()-1) {
		if (sum + vn[now_num] == ta)
			answer++;
		if (sum - vn[now_num] == ta)
			answer++;
	}
	else {
		func(now_num + 1, sum + vn[now_num]);
		func(now_num + 1, sum - vn[now_num]);
	}
}

int solution(vector<int> numbers, int target) {
	vn = numbers;
	ta = target;

	func(0, 0);
	return answer;
}

int main() {
	vector<int> v1 = { 1, 1, 1, 1, 1 };
	vector<int> v2 = { 3, 9, 9, 3, 5, 7, 2 };
	int i1 = 3;
	int i2 = 0;

	cout << solution(v1, i1) << '\n';
}