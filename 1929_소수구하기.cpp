#include<iostream>
#include<cstdio>
#include<cmath>
#pragma warning(disable:4996)

using namespace std;


int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	
	int* arr = new int[n] {0, }; //사용한 소수 저장
	int index = 0; //어디까지 저장했는지 인덱스 저장

	if (m <= 2 && n>=2) printf("%d\n", 2);
	arr[index++] = 3;

	for (int i = 3; i <= n; ) { //i는 증가하며 소수를 판별할 것임

		if (m <= i) printf("%d\n", i);

		while (1) {
			int flag = 1;
			i += 2;
			for (int j = 0; arr[j] <= sqrt(i) && j < index; j++) { //제곱근까지만 소수인지 아닌지 판단해도 충분
				if (i % arr[j] == 0) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				arr[index++] = i;
				break;
			}
		}
	}

	return 0;
}