#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)

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

	int a, b;
	scanf("%d %d", &a, &b);

	int gcd_result = gcd(a, b);
	printf("%d\n", gcd_result);
	printf("%d", (a / gcd_result) * (b / gcd_result) * gcd_result);

	return 0;
}