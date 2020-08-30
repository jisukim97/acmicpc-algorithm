#include<iostream>
#include<cstdlib>
#include<algorithm>

// 재귀로 다이나믹프로그래밍 풀기
// 다소 느림

using namespace std;

int n;
int* stair_weight;

int score(int location, int cur_score, int step) {

	if (location == (n - 1)) return cur_score; //계단의 마지막 칸이면 누적된 점수를 반환
	else if (location == (n - 2)) {//마지막 바로전 계단이면 무조건 마지막 계단으로 가야함
		if (step == 2) return 0;
		return score(location + 1, stair_weight[location + 1] + cur_score, step + 1);
	}
	else if (step == 2) //이미 연속 2칸을 밟았으면 무조건 2칸 건너 밟기
		return score(location + 2, stair_weight[location + 2] + cur_score, 1);
	else {
		int tmp1, tmp2;

		tmp1 = score(location + 1, stair_weight[location + 1] + cur_score, step + 1);
		tmp2 = score(location + 2, stair_weight[location + 2] + cur_score, step + 1);

		return max(tmp1, tmp2);
	}
}

int main()
{
	cin >> n;

	stair_weight = new int[n];

	for (int i = 0; i < n; i++)
		cin >> stair_weight[i];

	cout << score(-1, 0, 0);

	return 0;
}