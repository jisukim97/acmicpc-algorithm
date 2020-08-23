#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)

//유클리드 호제법으로 gcd를 구한 것으로 최소공배수 구하기

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a, b; 
		scanf("%d %d", &a, &b);
		int gcd_result = gcd(a, b);
		printf("%d\n",(a/gcd_result)*(b/gcd_result)*gcd_result);
	}

	return 0;
}