#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)

using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	int* arr = new int[n]{0, }; //사용한 소수 저장
	int index = 0; //어디까지 저장했는지 인덱스 저장

	for (int i = 2; i <= n;) {

		while (n % i == 0) {
			printf("%d\n", i);
			n = n / i;
		}
		
		if (n == 1) break;

		while (1) {
			int flag = 0;
			i++;
			for (int j = 0; j < index; j++)
				if (i % arr[j] != 0) {
					flag = 1;
					break;
				}
			if (n % i == 0) {
				arr[index++] = i;
				break;
			}
		}
	}

	return 0;
}