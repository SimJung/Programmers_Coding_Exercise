#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0, passed_trucks = 0, truckNum, sum=0;
	vector<int> v[2];
	truckNum = truck_weights.size();

	while (passed_trucks < truckNum)
	{
		sum = 0;
		for (int i = 0; i < v[0].size(); i++) {
			sum += v[0][i];
		}
		if (!truck_weights.empty() && sum + truck_weights[0] <= weight) {
			v[0].push_back(truck_weights[0]);
			v[1].push_back(0);
			truck_weights.erase(truck_weights.begin());
		}
		for (int i = 0; i < v[0].size(); i++) {
			v[1][i]++;
		}
		answer++;

		if (v[1][0] == bridge_length)
		{
			v[0].erase(v[0].begin());
			v[1].erase(v[1].begin());
			passed_trucks++;
		}
	}


	return answer+1;
}

int main() {
	int bl = 2, weight = 10;
	vector<int> heights = { 7, 4, 5, 6 };
	int ans = solution(bl, weight, heights);

	cout << ans << '\n';
}