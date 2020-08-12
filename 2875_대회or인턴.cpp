#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main() {

	int N, M, K;
	cin >> N >> M >> K;

	priority_queue<int> team_N;

	for (int i = 0; i <= K; i++) {
		int j = K - i;
		team_N.push(min((N-i) / 2, (M-j))); //여자와 남자의 수가 주어졌을 때, 만들 수 있는 팀의 최대값을 추가
	}

	cout << team_N.top();

	return 0;
}