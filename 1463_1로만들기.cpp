#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

//다이나믹프로그래밍
//세가지 연산을 사용하여 1로 만들기

int dp[1000001];
int N;

int makeOne(int n, int c) {

	if (n == 1) return c;

	if (dp[n] == -1) {
		c++;
    
        int tmp3 = N, tmp2 = N, tmp1 = N;

		if (n % 3 == 0) //사용가능한 연산1. 3으로 나누기
			tmp3 = makeOne(n / 3, c);

		if (n % 2 == 0) //사용가능한 연산2. 2로 나누기
			tmp2 = makeOne(n / 2, c);

		tmp1 = makeOne(n - 1, c); //사용가능한 연산3. 1 빼기

		int mini = min(tmp1, tmp2);
		return min(mini, tmp3);
	}
	else  //dp에 이미 계산한 값이 있으면;
		return c+dp[n];
	
}

int main() {

	cin >> N;

	memset(dp, -1, sizeof(dp));

	int ans;
	for (int i = 1; i <= N; i++) {
		ans = makeOne(i, 0);
		dp[i] = ans;
	}

	cout << dp[N];

	return 0;
}