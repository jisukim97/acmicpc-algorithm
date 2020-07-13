#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;

int main() {

	int n;
	scanf("%d", &n);
	int max = 0;
	double sum = 0;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
		if (arr[i] > max) max = arr[i];
	}

	for (int i = 0; i < n; i++) 
		sum += (double) arr[i] / max * 100;


	printf("%.5lf", (double)sum/n);

	return 0;
}