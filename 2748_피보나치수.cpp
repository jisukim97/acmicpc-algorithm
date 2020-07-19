#include<iostream>

using namespace std;

long long* dp;
int n;

long long fibo(int k) {
	if (k <= 1) return k;
	else if (dp[k] != 0)  return dp[k];
	else return dp[k] = fibo(k - 1) + fibo(k - 2);
}


int main() {

	cin >> n;
	dp = new long long[n+5] {0};
	cout<< fibo(n);

	delete[] dp;

	return 0;
}